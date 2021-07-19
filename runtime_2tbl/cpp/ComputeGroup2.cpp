#include "ComputeGroup2.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   struct V2_key
   {
      int store;
      V2_key(const int& store) : store(store)
      {  }
      bool operator==(const V2_key &other) const
      {
         return this->store == other.store ;
      }
   };

   struct V2_value
   {
      double aggregates[3];
   };

   struct V3_key
   {
      int onpromotion;
      V3_key(const int& onpromotion) : onpromotion(onpromotion)
      {  }
      bool operator==(const V3_key &other) const
      {
         return this->onpromotion == other.onpromotion ;
      }
   };

   struct V3_value
   {
      double aggregates[3];
   };

   struct V2_keyhash
   {
      size_t operator()(const V2_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.store)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V3_keyhash
   {
      size_t operator()(const V3_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.onpromotion)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   std::vector<V1_tuple> local_V1[8];
   std::unordered_map<V2_key,V2_value,V2_keyhash> local_V2_map[8];
   std::unordered_map<V3_key,V3_value,V3_keyhash> local_V3_map[8];

   void computeGroup2Parallelized(const size_t thread, const size_t lowerptr, const size_t upperptr)
   {
      std::vector<V1_tuple>& V1 = local_V1[thread];
      std::unordered_map<V2_key,V2_value,V2_keyhash>& V2_map = local_V2_map[thread];
      std::unordered_map<V2_key,V2_value,V2_keyhash>::iterator V2_iterator;
      V2_map.reserve(500000);
      std::unordered_map<V3_key,V3_value,V3_keyhash>& V3_map = local_V3_map[thread];
      std::unordered_map<V3_key,V3_value,V3_keyhash>::iterator V3_iterator;
      V3_map.reserve(500000);
      int max_date;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Sales[1] = {}, upperptr_Sales[1] = {}; 
      upperptr_Sales[0] = upperptr;
      lowerptr_Sales[0] = lowerptr;
      size_t lowerptr_V0[1] = {}, upperptr_V0[1] = {}; 
      upperptr_V0[0] = V0.size()-1;
      size_t ptr_Sales = 0;
      double *aggregates_V1 = nullptr, *aggregates_V2 = nullptr, *aggregates_V3 = nullptr, *aggregates_V0 = nullptr;
      int min_date;
      double aggregateRegister[10] = {};
      double localRegister[6] = {};
      double postRegister[3] = {};
      size_t rel[1] = {}, numOfRel[1] = {2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_date[2];
      if(Sales[lowerptr_Sales[0]].date < V0[lowerptr_V0[0]].date)
      {
         order_date[0] = std::make_pair(Sales[lowerptr_Sales[0]].date, Sales_ID);
         order_date[1] = std::make_pair(V0[lowerptr_V0[0]].date, V0_ID);
      }
      else
      {
         order_date[0] = std::make_pair(V0[lowerptr_V0[0]].date, V0_ID);
         order_date[1] = std::make_pair(Sales[lowerptr_Sales[0]].date, Sales_ID);
      }
      min_date = order_date[0].first;
      max_date = order_date[1].first;
      /*********** ORDERING RELATIONS *************/
      rel[0] = 0;
      atEnd[0] = false;
      memset(&postRegister[0], 0, sizeof(double) * 3);
      while(!atEnd[0])
      {
         found[0] = false;
         // Seek Value
         do
         {
            switch(order_date[rel[0]].second)
            {
            case Sales_ID:
               if(Sales[lowerptr_Sales[0]].date == max_date)
                  found[0] = true;
               else if(max_date > Sales[upperptr].date)
                  atEnd[0] = true;
               else
               {
                  min_date = Sales[lowerptr_Sales[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_Sales[0] <= upperptr)
                  {
                     lowerptr_Sales[0] += leap;
                     leap *= 2;
                     if(lowerptr_Sales[0] < upperptr)
                     {
                        min_date = Sales[lowerptr_Sales[0]].date;
                     }
                     else
                     {
                        lowerptr_Sales[0] = upperptr;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= Sales[lowerptr_Sales[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_Sales[0], low = lowerptr_Sales[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > Sales[mid - 1].date && max_date <= Sales[mid].date)
                        {
                           lowerptr_Sales[0] = mid;
                           break;
                        }
                        else if (max_date <= Sales[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (Sales[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_Sales[0] = mid;
                  }
                  max_date = Sales[lowerptr_Sales[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            case V0_ID:
               if(V0[lowerptr_V0[0]].date == max_date)
                  found[0] = true;
               else if(max_date > V0[V0.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = V0[lowerptr_V0[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_V0[0] <= V0.size()-1)
                  {
                     lowerptr_V0[0] += leap;
                     leap *= 2;
                     if(lowerptr_V0[0] < V0.size()-1)
                     {
                        min_date = V0[lowerptr_V0[0]].date;
                     }
                     else
                     {
                        lowerptr_V0[0] = V0.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= V0[lowerptr_V0[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V0[0], low = lowerptr_V0[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > V0[mid - 1].date && max_date <= V0[mid].date)
                        {
                           lowerptr_V0[0] = mid;
                           break;
                        }
                        else if (max_date <= V0[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V0[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_V0[0] = mid;
                  }
                  max_date = V0[lowerptr_V0[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            }
         } while (!found[0] && !atEnd[0]);
         // End Seek Value
         // If atEnd break loop
         if(atEnd[0])
            break;
         upperptr_Sales[0] = lowerptr_Sales[0];
         while(upperptr_Sales[0]<upperptr && Sales[upperptr_Sales[0]+1].date == max_date)
         {
            ++upperptr_Sales[0];
         }
         upperptr_V0[0] = lowerptr_V0[0];
         while(upperptr_V0[0]<V0.size()-1 && V0[upperptr_V0[0]+1].date == max_date)
         {
            ++upperptr_V0[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 7);
         Sales_tuple &SalesTuple = Sales[lowerptr_Sales[0]];
         V0_tuple &V0Tuple = V0[lowerptr_V0[0]];
         double *aggregates_V0 = V0Tuple.aggregates;
         double count = upperptr_Sales[0] - lowerptr_Sales[0] + 1;
         memset(&aggregateRegister[3], 0, sizeof(double) * 4);
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         ptr_Sales = lowerptr_Sales[0];
         while(ptr_Sales <= upperptr_Sales[0])
         {
            Sales_tuple &SalesTuple = Sales[ptr_Sales];
            localRegister[0] = f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
            localRegister[1] = SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
            localRegister[2] = SalesTuple.unit_sales*SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[0+i] += localRegister[0+i];
            ++ptr_Sales;
         }
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[3+i] += aggregates_V0[0]*aggregateRegister[0+i];
         aggregateRegister[6] += aggregates_V0[0];
         memset(addTuple, true, sizeof(bool) * 1);
         for (size_t i = 0; i < 3;++i)
            postRegister[0+i] += aggregateRegister[3+i];
         memset(&aggregateRegister[7], 0, sizeof(double) * 3);
         ptr_Sales = lowerptr_Sales[0];
         while(ptr_Sales <= upperptr_Sales[0])
         {
            Sales_tuple &SalesTuple = Sales[ptr_Sales];
            localRegister[3] = f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
            localRegister[4] = SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
            localRegister[5] = SalesTuple.unit_sales*SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
            aggregateRegister[7] += localRegister[3];
            aggregateRegister[8] += localRegister[4];
            aggregateRegister[9] += localRegister[5];
            V2_iterator = V2_map.find({SalesTuple.store});
            if (V2_iterator != V2_map.end())
               aggregates_V2 = &V2_iterator->second.aggregates[0];
            else
               aggregates_V2 = &V2_map.insert({{SalesTuple.store},{}}).first->second.aggregates[0];
            aggregates_V2[0] += aggregateRegister[6]*aggregateRegister[7];
            aggregates_V2[1] += aggregateRegister[6]*aggregateRegister[8];
            aggregates_V2[2] += aggregateRegister[6]*aggregateRegister[9];
            V3_iterator = V3_map.find({SalesTuple.onpromotion});
            if (V3_iterator != V3_map.end())
               aggregates_V3 = &V3_iterator->second.aggregates[0];
            else
               aggregates_V3 = &V3_map.insert({{SalesTuple.onpromotion},{}}).first->second.aggregates[0];
            aggregates_V3[0] += aggregateRegister[6]*aggregateRegister[7];
            aggregates_V3[1] += aggregateRegister[6]*aggregateRegister[8];
            aggregates_V3[2] += aggregateRegister[6]*aggregateRegister[9];
            ++ptr_Sales;
         }
         lowerptr_Sales[0] = upperptr_Sales[0];
         lowerptr_V0[0] = upperptr_V0[0];
         switch(order_date[rel[0]].second)
         {
         case Sales_ID:
            lowerptr_Sales[0] += 1;
            if(lowerptr_Sales[0] > upperptr)
               atEnd[0] = true;
            else
            {
               max_date = Sales[lowerptr_Sales[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         case V0_ID:
            lowerptr_V0[0] += 1;
            if(lowerptr_V0[0] > V0.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = V0[lowerptr_V0[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V1.emplace_back();
      aggregates_V1 = V1.back().aggregates;
      aggregates_V1[0] += postRegister[0];
      aggregates_V1[1] += postRegister[1];
      aggregates_V1[2] += postRegister[2];
   }
   void computeGroup2()
   {
      size_t lower, upper;
      lower = (size_t)(Sales.size() * ((double)0/8));
      upper = (size_t)(Sales.size() * ((double)1/8)) - 1;
      std::thread thread0(computeGroup2Parallelized,0,lower,upper);

      lower = (size_t)(Sales.size() * ((double)1/8));
      upper = (size_t)(Sales.size() * ((double)2/8)) - 1;
      std::thread thread1(computeGroup2Parallelized,1,lower,upper);

      lower = (size_t)(Sales.size() * ((double)2/8));
      upper = (size_t)(Sales.size() * ((double)3/8)) - 1;
      std::thread thread2(computeGroup2Parallelized,2,lower,upper);

      lower = (size_t)(Sales.size() * ((double)3/8));
      upper = (size_t)(Sales.size() * ((double)4/8)) - 1;
      std::thread thread3(computeGroup2Parallelized,3,lower,upper);

      lower = (size_t)(Sales.size() * ((double)4/8));
      upper = (size_t)(Sales.size() * ((double)5/8)) - 1;
      std::thread thread4(computeGroup2Parallelized,4,lower,upper);

      lower = (size_t)(Sales.size() * ((double)5/8));
      upper = (size_t)(Sales.size() * ((double)6/8)) - 1;
      std::thread thread5(computeGroup2Parallelized,5,lower,upper);

      lower = (size_t)(Sales.size() * ((double)6/8));
      upper = (size_t)(Sales.size() * ((double)7/8)) - 1;
      std::thread thread6(computeGroup2Parallelized,6,lower,upper);

      lower = (size_t)(Sales.size() * ((double)7/8));
      upper = (size_t)(Sales.size() * ((double)8/8)) - 1;
      std::thread thread7(computeGroup2Parallelized,7,lower,upper);

      thread0.join();
      thread1.join();
      thread2.join();
      thread3.join();
      thread4.join();
      thread5.join();
      thread6.join();
      thread7.join();
      V1.insert(V1.end(), local_V1[0].begin(), local_V1[0].end());
      for (size_t agg = 0; agg < 3; ++agg)
         V1[0].aggregates[agg] += local_V1[1][0].aggregates[agg]+local_V1[2][0].aggregates[agg]+local_V1[3][0].aggregates[agg]+local_V1[4][0].aggregates[agg]+local_V1[5][0].aggregates[agg]+local_V1[6][0].aggregates[agg]+local_V1[7][0].aggregates[agg];
      std::unordered_map<V2_key,V2_value,V2_keyhash>& V2_map = local_V2_map[0];
      for (size_t t = 1; t < 8; ++t)
      {
         for (const std::pair<V2_key,V2_value>& key : local_V2_map[t])
         {
            auto it = V2_map.find(key.first);
            if (it != V2_map.end())
            {
               for (size_t agg = 0; agg < 3; ++agg)
                  it->second.aggregates[agg] += key.second.aggregates[agg];
            }
            else
            {
               V2_map[key.first] = key.second;
            }
         }
      }
      V2.reserve(V2_map.size());
      for (const auto& kv_pair : V2_map)
      {
         V2.emplace_back(kv_pair.first.store);
         memcpy(&V2.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V2.begin(),V2.end(),[ ](const V2_tuple& lhs, const V2_tuple& rhs)
      {
         if(lhs.store != rhs.store)
            return lhs.store < rhs.store;
         return false;
      });
      std::unordered_map<V3_key,V3_value,V3_keyhash>& V3_map = local_V3_map[0];
      for (size_t t = 1; t < 8; ++t)
      {
         for (const std::pair<V3_key,V3_value>& key : local_V3_map[t])
         {
            auto it = V3_map.find(key.first);
            if (it != V3_map.end())
            {
               for (size_t agg = 0; agg < 3; ++agg)
                  it->second.aggregates[agg] += key.second.aggregates[agg];
            }
            else
            {
               V3_map[key.first] = key.second;
            }
         }
      }
      V3.reserve(V3_map.size());
      for (const auto& kv_pair : V3_map)
      {
         V3.emplace_back(kv_pair.first.onpromotion);
         memcpy(&V3.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V3.begin(),V3.end(),[ ](const V3_tuple& lhs, const V3_tuple& rhs)
      {
         if(lhs.onpromotion != rhs.onpromotion)
            return lhs.onpromotion < rhs.onpromotion;
         return false;
      });
   }

}
