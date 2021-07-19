#include "ComputeGroup5.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   struct V6_key
   {
      int store;
      V6_key(const int& store) : store(store)
      {  }
      bool operator==(const V6_key &other) const
      {
         return this->store == other.store ;
      }
   };

   struct V6_value
   {
      double aggregates[3];
   };

   struct V7_key
   {
      int onpromotion;
      V7_key(const int& onpromotion) : onpromotion(onpromotion)
      {  }
      bool operator==(const V7_key &other) const
      {
         return this->onpromotion == other.onpromotion ;
      }
   };

   struct V7_value
   {
      double aggregates[3];
   };

   struct V17_key
   {
      int store;
      V17_key(const int& store) : store(store)
      {  }
      bool operator==(const V17_key &other) const
      {
         return this->store == other.store ;
      }
   };

   struct V17_value
   {
      double aggregates[3];
   };

   struct V22_key
   {
      int item;
      V22_key(const int& item) : item(item)
      {  }
      bool operator==(const V22_key &other) const
      {
         return this->item == other.item ;
      }
   };

   struct V22_value
   {
      double aggregates[3];
   };

   struct V6_keyhash
   {
      size_t operator()(const V6_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.store)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V7_keyhash
   {
      size_t operator()(const V7_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.onpromotion)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V17_keyhash
   {
      size_t operator()(const V17_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.store)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V22_keyhash
   {
      size_t operator()(const V22_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.item)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   std::vector<V5_tuple> local_V5[8];
   std::unordered_map<V6_key,V6_value,V6_keyhash> local_V6_map[8];
   std::unordered_map<V7_key,V7_value,V7_keyhash> local_V7_map[8];
   std::vector<V8_tuple> local_V8[8];
   std::vector<V10_tuple> local_V10[8];
   std::vector<V15_tuple> local_V15[8];
   std::unordered_map<V17_key,V17_value,V17_keyhash> local_V17_map[8];
   std::unordered_map<V22_key,V22_value,V22_keyhash> local_V22_map[8];

   void computeGroup5Parallelized(const size_t thread, const size_t lowerptr, const size_t upperptr)
   {
      std::vector<V5_tuple>& V5 = local_V5[thread];
      std::unordered_map<V6_key,V6_value,V6_keyhash>& V6_map = local_V6_map[thread];
      std::unordered_map<V6_key,V6_value,V6_keyhash>::iterator V6_iterator;
      V6_map.reserve(500000);
      std::unordered_map<V7_key,V7_value,V7_keyhash>& V7_map = local_V7_map[thread];
      std::unordered_map<V7_key,V7_value,V7_keyhash>::iterator V7_iterator;
      V7_map.reserve(500000);
      std::vector<V8_tuple>& V8 = local_V8[thread];
      std::vector<V10_tuple>& V10 = local_V10[thread];
      std::vector<V15_tuple>& V15 = local_V15[thread];
      std::unordered_map<V17_key,V17_value,V17_keyhash>& V17_map = local_V17_map[thread];
      std::unordered_map<V17_key,V17_value,V17_keyhash>::iterator V17_iterator;
      V17_map.reserve(500000);
      std::unordered_map<V22_key,V22_value,V22_keyhash>& V22_map = local_V22_map[thread];
      std::unordered_map<V22_key,V22_value,V22_keyhash>::iterator V22_iterator;
      V22_map.reserve(500000);
      int max_date;
      int max_store;
      int max_item;
      bool found[3] = {}, atEnd[3] = {}, addTuple[3] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Sales[3] = {}, upperptr_Sales[3] = {}; 
      upperptr_Sales[0] = upperptr;
      lowerptr_Sales[0] = lowerptr;
      size_t lowerptr_V0[3] = {}, upperptr_V0[3] = {}; 
      upperptr_V0[0] = V0.size()-1;
      size_t lowerptr_V1[3] = {}, upperptr_V1[3] = {}; 
      upperptr_V1[0] = V1.size()-1;
      size_t lowerptr_V2[3] = {}, upperptr_V2[3] = {}; 
      upperptr_V2[0] = V2.size()-1;
      size_t lowerptr_V3[3] = {}, upperptr_V3[3] = {}; 
      upperptr_V3[0] = V3.size()-1;
      size_t lowerptr_V4[3] = {}, upperptr_V4[3] = {}; 
      upperptr_V4[0] = V4.size()-1;
      size_t ptr_Sales = 0;
      double *aggregates_V5 = nullptr, *aggregates_V6 = nullptr, *aggregates_V7 = nullptr, *aggregates_V8 = nullptr, *aggregates_V10 = nullptr, *aggregates_V15 = nullptr, *aggregates_V17 = nullptr, *aggregates_V22 = nullptr, *aggregates_V0 = nullptr, *aggregates_V1 = nullptr, *aggregates_V2 = nullptr, *aggregates_V3 = nullptr, *aggregates_V4 = nullptr;
      int min_date;
      int min_store;
      int min_item;
      double aggregateRegister[20] = {};
      double localRegister[6] = {};
      double viewRegister[6] = {};
      double postRegister[9] = {};
      size_t rel[3] = {}, numOfRel[3] = {4,3,2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_date[4] = 
         {
            std::make_pair(Sales[lowerptr_Sales[0]].date, Sales_ID),
            std::make_pair(V0[lowerptr_V0[0]].date, V0_ID),
            std::make_pair(V1[lowerptr_V1[0]].date, V1_ID),
            std::make_pair(V2[lowerptr_V2[0]].date, V2_ID)
         };
      std::sort(order_date, order_date + 4,[](const std::pair<int,int> &lhs, const std::pair<int,int> &rhs)
         {
            return lhs.first < rhs.first;
         });
      min_date = order_date[0].first;
      max_date = order_date[3].first;
      /*********** ORDERING RELATIONS *************/
      rel[0] = 0;
      atEnd[0] = false;
      memset(&postRegister[6], 0, sizeof(double) * 3);
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
            case V1_ID:
               if(V1[lowerptr_V1[0]].date == max_date)
                  found[0] = true;
               else if(max_date > V1[V1.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = V1[lowerptr_V1[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_V1[0] <= V1.size()-1)
                  {
                     lowerptr_V1[0] += leap;
                     leap *= 2;
                     if(lowerptr_V1[0] < V1.size()-1)
                     {
                        min_date = V1[lowerptr_V1[0]].date;
                     }
                     else
                     {
                        lowerptr_V1[0] = V1.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= V1[lowerptr_V1[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V1[0], low = lowerptr_V1[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > V1[mid - 1].date && max_date <= V1[mid].date)
                        {
                           lowerptr_V1[0] = mid;
                           break;
                        }
                        else if (max_date <= V1[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V1[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_V1[0] = mid;
                  }
                  max_date = V1[lowerptr_V1[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            case V2_ID:
               if(V2[lowerptr_V2[0]].date == max_date)
                  found[0] = true;
               else if(max_date > V2[V2.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = V2[lowerptr_V2[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_V2[0] <= V2.size()-1)
                  {
                     lowerptr_V2[0] += leap;
                     leap *= 2;
                     if(lowerptr_V2[0] < V2.size()-1)
                     {
                        min_date = V2[lowerptr_V2[0]].date;
                     }
                     else
                     {
                        lowerptr_V2[0] = V2.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= V2[lowerptr_V2[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V2[0], low = lowerptr_V2[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > V2[mid - 1].date && max_date <= V2[mid].date)
                        {
                           lowerptr_V2[0] = mid;
                           break;
                        }
                        else if (max_date <= V2[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V2[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_V2[0] = mid;
                  }
                  max_date = V2[lowerptr_V2[0]].date;
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
         upperptr_V1[0] = lowerptr_V1[0];
         while(upperptr_V1[0]<V1.size()-1 && V1[upperptr_V1[0]+1].date == max_date)
         {
            ++upperptr_V1[0];
         }
         upperptr_V2[0] = lowerptr_V2[0];
         while(upperptr_V2[0]<V2.size()-1 && V2[upperptr_V2[0]+1].date == max_date)
         {
            ++upperptr_V2[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         Sales_tuple &SalesTuple = Sales[lowerptr_Sales[0]];
         V0_tuple &V0Tuple = V0[lowerptr_V0[0]];
         double *aggregates_V0 = V0Tuple.aggregates;
         V1_tuple &V1Tuple = V1[lowerptr_V1[0]];
         double *aggregates_V1 = V1Tuple.aggregates;
         V2_tuple &V2Tuple = V2[lowerptr_V2[0]];
         double *aggregates_V2 = V2Tuple.aggregates;
         V3_tuple &V3Tuple = V3[lowerptr_V3[0]];
         double *aggregates_V3 = V3Tuple.aggregates;
         V4_tuple &V4Tuple = V4[lowerptr_V4[0]];
         double *aggregates_V4 = V4Tuple.aggregates;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         viewRegister[0] = aggregates_V0[0]*aggregates_V1[0];
         viewRegister[1] = aggregates_V1[0];
         viewRegister[2] = aggregates_V0[0];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[0+i] += viewRegister[0+i];
         upperptr_Sales[1] = upperptr_Sales[0];
         lowerptr_Sales[1] = lowerptr_Sales[0];
         upperptr_V0[1] = upperptr_V0[0];
         lowerptr_V0[1] = lowerptr_V0[0];
         upperptr_V1[1] = upperptr_V1[0];
         lowerptr_V1[1] = lowerptr_V1[0];
         upperptr_V2[1] = upperptr_V2[0];
         lowerptr_V2[1] = lowerptr_V2[0];
         upperptr_V3[1] = upperptr_V3[0];
         lowerptr_V3[1] = lowerptr_V3[0];
         upperptr_V4[1] = upperptr_V4[0];
         lowerptr_V4[1] = lowerptr_V4[0];
         /*********** ORDERING RELATIONS *************/
         std::pair<int, int> order_store[3] = 
            {
               std::make_pair(Sales[lowerptr_Sales[1]].store, Sales_ID),
               std::make_pair(V2[lowerptr_V2[1]].store, V2_ID),
               std::make_pair(V3[lowerptr_V3[1]].store, V3_ID)
            };
         std::sort(order_store, order_store + 3,[](const std::pair<int,int> &lhs, const std::pair<int,int> &rhs)
            {
               return lhs.first < rhs.first;
            });
         min_store = order_store[0].first;
         max_store = order_store[2].first;
         /*********** ORDERING RELATIONS *************/
         rel[1] = 0;
         atEnd[1] = false;
         memset(&postRegister[3], 0, sizeof(double) * 3);
         while(!atEnd[1])
         {
            found[1] = false;
            // Seek Value
            do
            {
               switch(order_store[rel[1]].second)
               {
               case Sales_ID:
                  if(Sales[lowerptr_Sales[1]].store == max_store)
                     found[1] = true;
                  else if(max_store > Sales[upperptr_Sales[0]].store)
                     atEnd[1] = true;
                  else
                  {
                     min_store = Sales[lowerptr_Sales[1]].store;
                     size_t leap = 1;
                     while (min_store < max_store && lowerptr_Sales[1] <= upperptr_Sales[0])
                     {
                        lowerptr_Sales[1] += leap;
                        leap *= 2;
                        if(lowerptr_Sales[1] < upperptr_Sales[0])
                        {
                           min_store = Sales[lowerptr_Sales[1]].store;
                        }
                        else
                        {
                           lowerptr_Sales[1] = upperptr_Sales[0];
                           break;
                        }
                     }
                     /* Backtrack with binary search */
                     if (leap > 2 && max_store <= Sales[lowerptr_Sales[1]].store)
                     {
                        leap /= 2;
                        size_t high = lowerptr_Sales[1], low = lowerptr_Sales[1] - leap, mid = 0;
                        while (high > low && high != low)
                        {
                           mid = (high + low) / 2;
                           if (max_store > Sales[mid - 1].store && max_store <= Sales[mid].store)
                           {
                              lowerptr_Sales[1] = mid;
                              break;
                           }
                           else if (max_store <= Sales[mid].store)
                              high = mid - 1;
                           else 
                              low = mid + 1;
                        }
                        mid = (high + low) / 2;
                        if (Sales[mid-1].store >= max_store)
                           mid -= 1;
                        lowerptr_Sales[1] = mid;
                     }
                     max_store = Sales[lowerptr_Sales[1]].store;
                     rel[1] = (rel[1]+1) % numOfRel[1];
                  }
                  break;
               case V2_ID:
                  if(V2[lowerptr_V2[1]].store == max_store)
                     found[1] = true;
                  else if(max_store > V2[upperptr_V2[0]].store)
                     atEnd[1] = true;
                  else
                  {
                     min_store = V2[lowerptr_V2[1]].store;
                     size_t leap = 1;
                     while (min_store < max_store && lowerptr_V2[1] <= upperptr_V2[0])
                     {
                        lowerptr_V2[1] += leap;
                        leap *= 2;
                        if(lowerptr_V2[1] < upperptr_V2[0])
                        {
                           min_store = V2[lowerptr_V2[1]].store;
                        }
                        else
                        {
                           lowerptr_V2[1] = upperptr_V2[0];
                           break;
                        }
                     }
                     /* Backtrack with binary search */
                     if (leap > 2 && max_store <= V2[lowerptr_V2[1]].store)
                     {
                        leap /= 2;
                        size_t high = lowerptr_V2[1], low = lowerptr_V2[1] - leap, mid = 0;
                        while (high > low && high != low)
                        {
                           mid = (high + low) / 2;
                           if (max_store > V2[mid - 1].store && max_store <= V2[mid].store)
                           {
                              lowerptr_V2[1] = mid;
                              break;
                           }
                           else if (max_store <= V2[mid].store)
                              high = mid - 1;
                           else 
                              low = mid + 1;
                        }
                        mid = (high + low) / 2;
                        if (V2[mid-1].store >= max_store)
                           mid -= 1;
                        lowerptr_V2[1] = mid;
                     }
                     max_store = V2[lowerptr_V2[1]].store;
                     rel[1] = (rel[1]+1) % numOfRel[1];
                  }
                  break;
               case V3_ID:
                  if(V3[lowerptr_V3[1]].store == max_store)
                     found[1] = true;
                  else if(max_store > V3[upperptr_V3[0]].store)
                     atEnd[1] = true;
                  else
                  {
                     min_store = V3[lowerptr_V3[1]].store;
                     size_t leap = 1;
                     while (min_store < max_store && lowerptr_V3[1] <= upperptr_V3[0])
                     {
                        lowerptr_V3[1] += leap;
                        leap *= 2;
                        if(lowerptr_V3[1] < upperptr_V3[0])
                        {
                           min_store = V3[lowerptr_V3[1]].store;
                        }
                        else
                        {
                           lowerptr_V3[1] = upperptr_V3[0];
                           break;
                        }
                     }
                     /* Backtrack with binary search */
                     if (leap > 2 && max_store <= V3[lowerptr_V3[1]].store)
                     {
                        leap /= 2;
                        size_t high = lowerptr_V3[1], low = lowerptr_V3[1] - leap, mid = 0;
                        while (high > low && high != low)
                        {
                           mid = (high + low) / 2;
                           if (max_store > V3[mid - 1].store && max_store <= V3[mid].store)
                           {
                              lowerptr_V3[1] = mid;
                              break;
                           }
                           else if (max_store <= V3[mid].store)
                              high = mid - 1;
                           else 
                              low = mid + 1;
                        }
                        mid = (high + low) / 2;
                        if (V3[mid-1].store >= max_store)
                           mid -= 1;
                        lowerptr_V3[1] = mid;
                     }
                     max_store = V3[lowerptr_V3[1]].store;
                     rel[1] = (rel[1]+1) % numOfRel[1];
                  }
                  break;
               }
            } while (!found[1] && !atEnd[1]);
            // End Seek Value
            // If atEnd break loop
            if(atEnd[1])
               break;
            upperptr_Sales[1] = lowerptr_Sales[1];
            while(upperptr_Sales[1]<upperptr_Sales[0] && Sales[upperptr_Sales[1]+1].store == max_store)
            {
               ++upperptr_Sales[1];
            }
            upperptr_V2[1] = lowerptr_V2[1];
            while(upperptr_V2[1]<upperptr_V2[0] && V2[upperptr_V2[1]+1].store == max_store)
            {
               ++upperptr_V2[1];
            }
            upperptr_V3[1] = lowerptr_V3[1];
            while(upperptr_V3[1]<upperptr_V3[0] && V3[upperptr_V3[1]+1].store == max_store)
            {
               ++upperptr_V3[1];
            }
            addTuple[1] = false;
            memset(&aggregateRegister[3], 0, sizeof(double) * 4);
            Sales_tuple &SalesTuple = Sales[lowerptr_Sales[1]];
            V0_tuple &V0Tuple = V0[lowerptr_V0[1]];
            double *aggregates_V0 = V0Tuple.aggregates;
            V1_tuple &V1Tuple = V1[lowerptr_V1[1]];
            double *aggregates_V1 = V1Tuple.aggregates;
            V2_tuple &V2Tuple = V2[lowerptr_V2[1]];
            double *aggregates_V2 = V2Tuple.aggregates;
            V3_tuple &V3Tuple = V3[lowerptr_V3[1]];
            double *aggregates_V3 = V3Tuple.aggregates;
            V4_tuple &V4Tuple = V4[lowerptr_V4[1]];
            double *aggregates_V4 = V4Tuple.aggregates;
            memset(&aggregateRegister[3], 0, sizeof(double) * 4);
            viewRegister[3] = aggregates_V2[0]*aggregates_V3[0];
            viewRegister[4] = aggregates_V3[0];
            viewRegister[5] = aggregates_V2[0];
            aggregateRegister[3] += viewRegister[3];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[4+i] += aggregateRegister[0]*viewRegister[3+i];
            upperptr_Sales[2] = upperptr_Sales[1];
            lowerptr_Sales[2] = lowerptr_Sales[1];
            upperptr_V0[2] = upperptr_V0[1];
            lowerptr_V0[2] = lowerptr_V0[1];
            upperptr_V1[2] = upperptr_V1[1];
            lowerptr_V1[2] = lowerptr_V1[1];
            upperptr_V2[2] = upperptr_V2[1];
            lowerptr_V2[2] = lowerptr_V2[1];
            upperptr_V3[2] = upperptr_V3[1];
            lowerptr_V3[2] = lowerptr_V3[1];
            upperptr_V4[2] = upperptr_V4[1];
            lowerptr_V4[2] = lowerptr_V4[1];
            /*********** ORDERING RELATIONS *************/
            std::pair<int, int> order_item[2];
            if(Sales[lowerptr_Sales[2]].item < V4[lowerptr_V4[2]].item)
            {
               order_item[0] = std::make_pair(Sales[lowerptr_Sales[2]].item, Sales_ID);
               order_item[1] = std::make_pair(V4[lowerptr_V4[2]].item, V4_ID);
            }
            else
            {
               order_item[0] = std::make_pair(V4[lowerptr_V4[2]].item, V4_ID);
               order_item[1] = std::make_pair(Sales[lowerptr_Sales[2]].item, Sales_ID);
            }
            min_item = order_item[0].first;
            max_item = order_item[1].first;
            /*********** ORDERING RELATIONS *************/
            rel[2] = 0;
            atEnd[2] = false;
            memset(&postRegister[0], 0, sizeof(double) * 3);
            while(!atEnd[2])
            {
               found[2] = false;
               // Seek Value
               do
               {
                  switch(order_item[rel[2]].second)
                  {
                  case Sales_ID:
                     if(Sales[lowerptr_Sales[2]].item == max_item)
                        found[2] = true;
                     else if(max_item > Sales[upperptr_Sales[1]].item)
                        atEnd[2] = true;
                     else
                     {
                        min_item = Sales[lowerptr_Sales[2]].item;
                        size_t leap = 1;
                        while (min_item < max_item && lowerptr_Sales[2] <= upperptr_Sales[1])
                        {
                           lowerptr_Sales[2] += leap;
                           leap *= 2;
                           if(lowerptr_Sales[2] < upperptr_Sales[1])
                           {
                              min_item = Sales[lowerptr_Sales[2]].item;
                           }
                           else
                           {
                              lowerptr_Sales[2] = upperptr_Sales[1];
                              break;
                           }
                        }
                        /* Backtrack with binary search */
                        if (leap > 2 && max_item <= Sales[lowerptr_Sales[2]].item)
                        {
                           leap /= 2;
                           size_t high = lowerptr_Sales[2], low = lowerptr_Sales[2] - leap, mid = 0;
                           while (high > low && high != low)
                           {
                              mid = (high + low) / 2;
                              if (max_item > Sales[mid - 1].item && max_item <= Sales[mid].item)
                              {
                                 lowerptr_Sales[2] = mid;
                                 break;
                              }
                              else if (max_item <= Sales[mid].item)
                                 high = mid - 1;
                              else 
                                 low = mid + 1;
                           }
                           mid = (high + low) / 2;
                           if (Sales[mid-1].item >= max_item)
                              mid -= 1;
                           lowerptr_Sales[2] = mid;
                        }
                        max_item = Sales[lowerptr_Sales[2]].item;
                        rel[2] = (rel[2]+1) % numOfRel[2];
                     }
                     break;
                  case V4_ID:
                     if(V4[lowerptr_V4[2]].item == max_item)
                        found[2] = true;
                     else if(max_item > V4[upperptr_V4[1]].item)
                        atEnd[2] = true;
                     else
                     {
                        min_item = V4[lowerptr_V4[2]].item;
                        size_t leap = 1;
                        while (min_item < max_item && lowerptr_V4[2] <= upperptr_V4[1])
                        {
                           lowerptr_V4[2] += leap;
                           leap *= 2;
                           if(lowerptr_V4[2] < upperptr_V4[1])
                           {
                              min_item = V4[lowerptr_V4[2]].item;
                           }
                           else
                           {
                              lowerptr_V4[2] = upperptr_V4[1];
                              break;
                           }
                        }
                        /* Backtrack with binary search */
                        if (leap > 2 && max_item <= V4[lowerptr_V4[2]].item)
                        {
                           leap /= 2;
                           size_t high = lowerptr_V4[2], low = lowerptr_V4[2] - leap, mid = 0;
                           while (high > low && high != low)
                           {
                              mid = (high + low) / 2;
                              if (max_item > V4[mid - 1].item && max_item <= V4[mid].item)
                              {
                                 lowerptr_V4[2] = mid;
                                 break;
                              }
                              else if (max_item <= V4[mid].item)
                                 high = mid - 1;
                              else 
                                 low = mid + 1;
                           }
                           mid = (high + low) / 2;
                           if (V4[mid-1].item >= max_item)
                              mid -= 1;
                           lowerptr_V4[2] = mid;
                        }
                        max_item = V4[lowerptr_V4[2]].item;
                        rel[2] = (rel[2]+1) % numOfRel[2];
                     }
                     break;
                  }
               } while (!found[2] && !atEnd[2]);
               // End Seek Value
               // If atEnd break loop
               if(atEnd[2])
                  break;
               upperptr_Sales[2] = lowerptr_Sales[2];
               while(upperptr_Sales[2]<upperptr_Sales[1] && Sales[upperptr_Sales[2]+1].item == max_item)
               {
                  ++upperptr_Sales[2];
               }
               upperptr_V4[2] = lowerptr_V4[2];
               while(upperptr_V4[2]<upperptr_V4[1] && V4[upperptr_V4[2]+1].item == max_item)
               {
                  ++upperptr_V4[2];
               }
               addTuple[2] = false;
               memset(&aggregateRegister[7], 0, sizeof(double) * 10);
               Sales_tuple &SalesTuple = Sales[lowerptr_Sales[2]];
               V0_tuple &V0Tuple = V0[lowerptr_V0[2]];
               double *aggregates_V0 = V0Tuple.aggregates;
               V1_tuple &V1Tuple = V1[lowerptr_V1[2]];
               double *aggregates_V1 = V1Tuple.aggregates;
               V2_tuple &V2Tuple = V2[lowerptr_V2[2]];
               double *aggregates_V2 = V2Tuple.aggregates;
               V3_tuple &V3Tuple = V3[lowerptr_V3[2]];
               double *aggregates_V3 = V3Tuple.aggregates;
               V4_tuple &V4Tuple = V4[lowerptr_V4[2]];
               double *aggregates_V4 = V4Tuple.aggregates;
               double count = upperptr_Sales[2] - lowerptr_Sales[2] + 1;
               memset(&aggregateRegister[10], 0, sizeof(double) * 7);
               memset(&aggregateRegister[7], 0, sizeof(double) * 3);
               ptr_Sales = lowerptr_Sales[2];
               while(ptr_Sales <= upperptr_Sales[2])
               {
                  Sales_tuple &SalesTuple = Sales[ptr_Sales];
                  localRegister[0] = f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
                  localRegister[1] = SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
                  localRegister[2] = SalesTuple.unit_sales*SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
                  for (size_t i = 0; i < 3;++i)
                     aggregateRegister[7+i] += localRegister[0+i];
                  ++ptr_Sales;
               }
               for (size_t i = 0; i < 3;++i)
                  aggregateRegister[10+i] += aggregates_V4[0]*aggregateRegister[7+i];
               aggregateRegister[13] += aggregateRegister[4]*aggregates_V4[0];
               for (size_t i = 0; i < 3;++i)
                  aggregateRegister[14+i] += aggregateRegister[4]*aggregateRegister[7+i];
               memset(addTuple, true, sizeof(bool) * 3);
               for (size_t i = 0; i < 3;++i)
                  postRegister[0+i] += aggregateRegister[10+i];
               memset(&aggregateRegister[17], 0, sizeof(double) * 3);
               ptr_Sales = lowerptr_Sales[2];
               while(ptr_Sales <= upperptr_Sales[2])
               {
                  Sales_tuple &SalesTuple = Sales[ptr_Sales];
                  localRegister[3] = f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
                  localRegister[4] = SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
                  localRegister[5] = SalesTuple.unit_sales*SalesTuple.unit_sales*f_Sales(SalesTuple.date,SalesTuple.store,SalesTuple.item,SalesTuple.unit_sales,SalesTuple.onpromotion);
                  aggregateRegister[17] += localRegister[3];
                  aggregateRegister[18] += localRegister[4];
                  aggregateRegister[19] += localRegister[5];
                  V7_iterator = V7_map.find({SalesTuple.onpromotion});
                  if (V7_iterator != V7_map.end())
                     aggregates_V7 = &V7_iterator->second.aggregates[0];
                  else
                     aggregates_V7 = &V7_map.insert({{SalesTuple.onpromotion},{}}).first->second.aggregates[0];
                  aggregates_V7[0] += aggregateRegister[13]*aggregateRegister[17];
                  aggregates_V7[1] += aggregateRegister[13]*aggregateRegister[18];
                  aggregates_V7[2] += aggregateRegister[13]*aggregateRegister[19];
                  ++ptr_Sales;
               }
               V22_iterator = V22_map.find({SalesTuple.item});
               if (V22_iterator != V22_map.end())
                  aggregates_V22 = &V22_iterator->second.aggregates[0];
               else
                  aggregates_V22 = &V22_map.insert({{SalesTuple.item},{}}).first->second.aggregates[0];
               aggregates_V22[0] += aggregateRegister[14];
               aggregates_V22[1] += aggregateRegister[15];
               aggregates_V22[2] += aggregateRegister[16];
               lowerptr_Sales[2] = upperptr_Sales[2];
               lowerptr_V4[2] = upperptr_V4[2];
               switch(order_item[rel[2]].second)
               {
               case Sales_ID:
                  lowerptr_Sales[2] += 1;
                  if(lowerptr_Sales[2] > upperptr_Sales[1])
                     atEnd[2] = true;
                  else
                  {
                     max_item = Sales[lowerptr_Sales[2]].item;
                     rel[2] = (rel[2]+ 1) % numOfRel[2];
                  }
                  break;
               case V4_ID:
                  lowerptr_V4[2] += 1;
                  if(lowerptr_V4[2] > upperptr_V4[1])
                     atEnd[2] = true;
                  else
                  {
                     max_item = V4[lowerptr_V4[2]].item;
                     rel[2] = (rel[2]+ 1) % numOfRel[2];
                  }
                  break;
               }
            }
            if (addTuple[1]) 
            {
               for (size_t i = 0; i < 3;++i)
                  postRegister[3+i] += aggregateRegister[3]*postRegister[0+i];
               V6_iterator = V6_map.find({SalesTuple.store});
               if (V6_iterator != V6_map.end())
                  aggregates_V6 = &V6_iterator->second.aggregates[0];
               else
                  aggregates_V6 = &V6_map.insert({{SalesTuple.store},{}}).first->second.aggregates[0];
               aggregates_V6[0] += aggregateRegister[4]*postRegister[0];
               aggregates_V6[1] += aggregateRegister[4]*postRegister[1];
               aggregates_V6[2] += aggregateRegister[4]*postRegister[2];
               V15.emplace_back(SalesTuple.date,SalesTuple.store);
               aggregates_V15 = V15.back().aggregates;
               aggregates_V15[0] += aggregateRegister[5]*postRegister[0];
               aggregates_V15[1] += aggregateRegister[5]*postRegister[1];
               aggregates_V15[2] += aggregateRegister[5]*postRegister[2];
               V17_iterator = V17_map.find({SalesTuple.store});
               if (V17_iterator != V17_map.end())
                  aggregates_V17 = &V17_iterator->second.aggregates[0];
               else
                  aggregates_V17 = &V17_map.insert({{SalesTuple.store},{}}).first->second.aggregates[0];
               aggregates_V17[0] += aggregateRegister[6]*postRegister[0];
               aggregates_V17[1] += aggregateRegister[6]*postRegister[1];
               aggregates_V17[2] += aggregateRegister[6]*postRegister[2];
            }
            lowerptr_Sales[1] = upperptr_Sales[1];
            lowerptr_V2[1] = upperptr_V2[1];
            lowerptr_V3[1] = upperptr_V3[1];
            switch(order_store[rel[1]].second)
            {
            case Sales_ID:
               lowerptr_Sales[1] += 1;
               if(lowerptr_Sales[1] > upperptr_Sales[0])
                  atEnd[1] = true;
               else
               {
                  max_store = Sales[lowerptr_Sales[1]].store;
                  rel[1] = (rel[1]+ 1) % numOfRel[1];
               }
               break;
            case V2_ID:
               lowerptr_V2[1] += 1;
               if(lowerptr_V2[1] > upperptr_V2[0])
                  atEnd[1] = true;
               else
               {
                  max_store = V2[lowerptr_V2[1]].store;
                  rel[1] = (rel[1]+ 1) % numOfRel[1];
               }
               break;
            case V3_ID:
               lowerptr_V3[1] += 1;
               if(lowerptr_V3[1] > upperptr_V3[0])
                  atEnd[1] = true;
               else
               {
                  max_store = V3[lowerptr_V3[1]].store;
                  rel[1] = (rel[1]+ 1) % numOfRel[1];
               }
               break;
            }
         }
         if (addTuple[0]) 
         {
            for (size_t i = 0; i < 3;++i)
               postRegister[6+i] += aggregateRegister[0]*postRegister[3+i];
            V8.emplace_back(SalesTuple.date);
            aggregates_V8 = V8.back().aggregates;
            aggregates_V8[0] += aggregateRegister[1]*postRegister[3];
            aggregates_V8[1] += aggregateRegister[1]*postRegister[4];
            aggregates_V8[2] += aggregateRegister[1]*postRegister[5];
            V10.emplace_back(SalesTuple.date);
            aggregates_V10 = V10.back().aggregates;
            aggregates_V10[0] += aggregateRegister[2]*postRegister[3];
            aggregates_V10[1] += aggregateRegister[2]*postRegister[4];
            aggregates_V10[2] += aggregateRegister[2]*postRegister[5];
         }
         lowerptr_Sales[0] = upperptr_Sales[0];
         lowerptr_V0[0] = upperptr_V0[0];
         lowerptr_V1[0] = upperptr_V1[0];
         lowerptr_V2[0] = upperptr_V2[0];
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
         case V1_ID:
            lowerptr_V1[0] += 1;
            if(lowerptr_V1[0] > V1.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = V1[lowerptr_V1[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         case V2_ID:
            lowerptr_V2[0] += 1;
            if(lowerptr_V2[0] > V2.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = V2[lowerptr_V2[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V5.emplace_back();
      aggregates_V5 = V5.back().aggregates;
      aggregates_V5[0] += postRegister[6];
      aggregates_V5[1] += postRegister[7];
      aggregates_V5[2] += postRegister[8];
   }
   void computeGroup5()
   {
      size_t lower, upper;
      lower = (size_t)(Sales.size() * ((double)0/8));
      upper = (size_t)(Sales.size() * ((double)1/8)) - 1;
      std::thread thread0(computeGroup5Parallelized,0,lower,upper);

      lower = (size_t)(Sales.size() * ((double)1/8));
      upper = (size_t)(Sales.size() * ((double)2/8)) - 1;
      std::thread thread1(computeGroup5Parallelized,1,lower,upper);

      lower = (size_t)(Sales.size() * ((double)2/8));
      upper = (size_t)(Sales.size() * ((double)3/8)) - 1;
      std::thread thread2(computeGroup5Parallelized,2,lower,upper);

      lower = (size_t)(Sales.size() * ((double)3/8));
      upper = (size_t)(Sales.size() * ((double)4/8)) - 1;
      std::thread thread3(computeGroup5Parallelized,3,lower,upper);

      lower = (size_t)(Sales.size() * ((double)4/8));
      upper = (size_t)(Sales.size() * ((double)5/8)) - 1;
      std::thread thread4(computeGroup5Parallelized,4,lower,upper);

      lower = (size_t)(Sales.size() * ((double)5/8));
      upper = (size_t)(Sales.size() * ((double)6/8)) - 1;
      std::thread thread5(computeGroup5Parallelized,5,lower,upper);

      lower = (size_t)(Sales.size() * ((double)6/8));
      upper = (size_t)(Sales.size() * ((double)7/8)) - 1;
      std::thread thread6(computeGroup5Parallelized,6,lower,upper);

      lower = (size_t)(Sales.size() * ((double)7/8));
      upper = (size_t)(Sales.size() * ((double)8/8)) - 1;
      std::thread thread7(computeGroup5Parallelized,7,lower,upper);

      thread0.join();
      thread1.join();
      thread2.join();
      thread3.join();
      thread4.join();
      thread5.join();
      thread6.join();
      thread7.join();
      V5.insert(V5.end(), local_V5[0].begin(), local_V5[0].end());
      for (size_t agg = 0; agg < 3; ++agg)
         V5[0].aggregates[agg] += local_V5[1][0].aggregates[agg]+local_V5[2][0].aggregates[agg]+local_V5[3][0].aggregates[agg]+local_V5[4][0].aggregates[agg]+local_V5[5][0].aggregates[agg]+local_V5[6][0].aggregates[agg]+local_V5[7][0].aggregates[agg];
      V8.reserve(local_V8[0].size()+local_V8[1].size()+local_V8[2].size()+local_V8[3].size()+local_V8[4].size()+local_V8[5].size()+local_V8[6].size()+local_V8[7].size());
      V8.insert(V8.end(),local_V8[0].begin(), local_V8[0].end());
      for (size_t t = 1; t < 8; ++t)
      {
         std::vector<V8_tuple>& this_V8 = local_V8[t];
         if(V8.back().date==this_V8[0].date)
         {
            for (size_t agg = 0; agg < 3; ++agg)
               V8.back().aggregates[agg] += this_V8[0].aggregates[agg];
            V8.insert(V8.end(),this_V8.begin()+1,this_V8.end());
         }
         else
         {
            V8.insert(V8.end(), this_V8.begin(), this_V8.end());
         }
      }
      V10.reserve(local_V10[0].size()+local_V10[1].size()+local_V10[2].size()+local_V10[3].size()+local_V10[4].size()+local_V10[5].size()+local_V10[6].size()+local_V10[7].size());
      V10.insert(V10.end(),local_V10[0].begin(), local_V10[0].end());
      for (size_t t = 1; t < 8; ++t)
      {
         std::vector<V10_tuple>& this_V10 = local_V10[t];
         if(V10.back().date==this_V10[0].date)
         {
            for (size_t agg = 0; agg < 3; ++agg)
               V10.back().aggregates[agg] += this_V10[0].aggregates[agg];
            V10.insert(V10.end(),this_V10.begin()+1,this_V10.end());
         }
         else
         {
            V10.insert(V10.end(), this_V10.begin(), this_V10.end());
         }
      }
      V15.reserve(local_V15[0].size()+local_V15[1].size()+local_V15[2].size()+local_V15[3].size()+local_V15[4].size()+local_V15[5].size()+local_V15[6].size()+local_V15[7].size());
      V15.insert(V15.end(),local_V15[0].begin(), local_V15[0].end());
      for (size_t t = 1; t < 8; ++t)
      {
         std::vector<V15_tuple>& this_V15 = local_V15[t];
         if(V15.back().date==this_V15[0].date&&V15.back().store==this_V15[0].store)
         {
            for (size_t agg = 0; agg < 3; ++agg)
               V15.back().aggregates[agg] += this_V15[0].aggregates[agg];
            V15.insert(V15.end(),this_V15.begin()+1,this_V15.end());
         }
         else
         {
            V15.insert(V15.end(), this_V15.begin(), this_V15.end());
         }
      }
      std::unordered_map<V6_key,V6_value,V6_keyhash>& V6_map = local_V6_map[0];
      for (size_t t = 1; t < 8; ++t)
      {
         for (const std::pair<V6_key,V6_value>& key : local_V6_map[t])
         {
            auto it = V6_map.find(key.first);
            if (it != V6_map.end())
            {
               for (size_t agg = 0; agg < 3; ++agg)
                  it->second.aggregates[agg] += key.second.aggregates[agg];
            }
            else
            {
               V6_map[key.first] = key.second;
            }
         }
      }
      V6.reserve(V6_map.size());
      for (const auto& kv_pair : V6_map)
      {
         V6.emplace_back(kv_pair.first.store);
         memcpy(&V6.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V6.begin(),V6.end(),[ ](const V6_tuple& lhs, const V6_tuple& rhs)
      {
         if(lhs.store != rhs.store)
            return lhs.store < rhs.store;
         return false;
      });
      std::unordered_map<V7_key,V7_value,V7_keyhash>& V7_map = local_V7_map[0];
      for (size_t t = 1; t < 8; ++t)
      {
         for (const std::pair<V7_key,V7_value>& key : local_V7_map[t])
         {
            auto it = V7_map.find(key.first);
            if (it != V7_map.end())
            {
               for (size_t agg = 0; agg < 3; ++agg)
                  it->second.aggregates[agg] += key.second.aggregates[agg];
            }
            else
            {
               V7_map[key.first] = key.second;
            }
         }
      }
      V7.reserve(V7_map.size());
      for (const auto& kv_pair : V7_map)
      {
         V7.emplace_back(kv_pair.first.onpromotion);
         memcpy(&V7.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V7.begin(),V7.end(),[ ](const V7_tuple& lhs, const V7_tuple& rhs)
      {
         if(lhs.onpromotion != rhs.onpromotion)
            return lhs.onpromotion < rhs.onpromotion;
         return false;
      });
      std::unordered_map<V17_key,V17_value,V17_keyhash>& V17_map = local_V17_map[0];
      for (size_t t = 1; t < 8; ++t)
      {
         for (const std::pair<V17_key,V17_value>& key : local_V17_map[t])
         {
            auto it = V17_map.find(key.first);
            if (it != V17_map.end())
            {
               for (size_t agg = 0; agg < 3; ++agg)
                  it->second.aggregates[agg] += key.second.aggregates[agg];
            }
            else
            {
               V17_map[key.first] = key.second;
            }
         }
      }
      V17.reserve(V17_map.size());
      for (const auto& kv_pair : V17_map)
      {
         V17.emplace_back(kv_pair.first.store);
         memcpy(&V17.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V17.begin(),V17.end(),[ ](const V17_tuple& lhs, const V17_tuple& rhs)
      {
         if(lhs.store != rhs.store)
            return lhs.store < rhs.store;
         return false;
      });
      std::unordered_map<V22_key,V22_value,V22_keyhash>& V22_map = local_V22_map[0];
      for (size_t t = 1; t < 8; ++t)
      {
         for (const std::pair<V22_key,V22_value>& key : local_V22_map[t])
         {
            auto it = V22_map.find(key.first);
            if (it != V22_map.end())
            {
               for (size_t agg = 0; agg < 3; ++agg)
                  it->second.aggregates[agg] += key.second.aggregates[agg];
            }
            else
            {
               V22_map[key.first] = key.second;
            }
         }
      }
      V22.reserve(V22_map.size());
      for (const auto& kv_pair : V22_map)
      {
         V22.emplace_back(kv_pair.first.item);
         memcpy(&V22.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V22.begin(),V22.end(),[ ](const V22_tuple& lhs, const V22_tuple& rhs)
      {
         if(lhs.item != rhs.item)
            return lhs.item < rhs.item;
         return false;
      });
   }

}
