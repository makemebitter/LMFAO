#include "ComputeGroup9.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   struct V18_key
   {
      int city;
      V18_key(const int& city) : city(city)
      {  }
      bool operator==(const V18_key &other) const
      {
         return this->city == other.city ;
      }
   };

   struct V18_value
   {
      double aggregates[3];
   };

   struct V19_key
   {
      int state;
      V19_key(const int& state) : state(state)
      {  }
      bool operator==(const V19_key &other) const
      {
         return this->state == other.state ;
      }
   };

   struct V19_value
   {
      double aggregates[3];
   };

   struct V20_key
   {
      int store_type;
      V20_key(const int& store_type) : store_type(store_type)
      {  }
      bool operator==(const V20_key &other) const
      {
         return this->store_type == other.store_type ;
      }
   };

   struct V20_value
   {
      double aggregates[3];
   };

   struct V21_key
   {
      int cluster;
      V21_key(const int& cluster) : cluster(cluster)
      {  }
      bool operator==(const V21_key &other) const
      {
         return this->cluster == other.cluster ;
      }
   };

   struct V21_value
   {
      double aggregates[3];
   };

   struct V18_keyhash
   {
      size_t operator()(const V18_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.city)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V19_keyhash
   {
      size_t operator()(const V19_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.state)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V20_keyhash
   {
      size_t operator()(const V20_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.store_type)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V21_keyhash
   {
      size_t operator()(const V21_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.cluster)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   void computeGroup9()
   {
      std::unordered_map<V18_key,V18_value,V18_keyhash> V18_map;
      std::unordered_map<V18_key,V18_value,V18_keyhash>::iterator V18_iterator;
      std::pair<std::unordered_map<V18_key,V18_value,V18_keyhash>::iterator,bool> V18_pair;
      V18_map.reserve(500000);
      std::unordered_map<V19_key,V19_value,V19_keyhash> V19_map;
      std::unordered_map<V19_key,V19_value,V19_keyhash>::iterator V19_iterator;
      std::pair<std::unordered_map<V19_key,V19_value,V19_keyhash>::iterator,bool> V19_pair;
      V19_map.reserve(500000);
      std::unordered_map<V20_key,V20_value,V20_keyhash> V20_map;
      std::unordered_map<V20_key,V20_value,V20_keyhash>::iterator V20_iterator;
      std::pair<std::unordered_map<V20_key,V20_value,V20_keyhash>::iterator,bool> V20_pair;
      V20_map.reserve(500000);
      std::unordered_map<V21_key,V21_value,V21_keyhash> V21_map;
      std::unordered_map<V21_key,V21_value,V21_keyhash>::iterator V21_iterator;
      std::pair<std::unordered_map<V21_key,V21_value,V21_keyhash>::iterator,bool> V21_pair;
      V21_map.reserve(500000);
      int max_store;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Stores[1] = {}, upperptr_Stores[1] = {}; 
      upperptr_Stores[0] = Stores.size()-1;
      size_t lowerptr_V17[1] = {}, upperptr_V17[1] = {}; 
      upperptr_V17[0] = V17.size()-1;
      size_t ptr_Stores = 0;
      double *aggregates_V18 = nullptr, *aggregates_V19 = nullptr, *aggregates_V20 = nullptr, *aggregates_V21 = nullptr, *aggregates_V17 = nullptr;
      int min_store;
      double aggregateRegister[4] = {};
      double localRegister[1] = {};
      size_t rel[1] = {}, numOfRel[1] = {2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_store[2];
      if(Stores[lowerptr_Stores[0]].store < V17[lowerptr_V17[0]].store)
      {
         order_store[0] = std::make_pair(Stores[lowerptr_Stores[0]].store, Stores_ID);
         order_store[1] = std::make_pair(V17[lowerptr_V17[0]].store, V17_ID);
      }
      else
      {
         order_store[0] = std::make_pair(V17[lowerptr_V17[0]].store, V17_ID);
         order_store[1] = std::make_pair(Stores[lowerptr_Stores[0]].store, Stores_ID);
      }
      min_store = order_store[0].first;
      max_store = order_store[1].first;
      /*********** ORDERING RELATIONS *************/
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         found[0] = false;
         // Seek Value
         do
         {
            switch(order_store[rel[0]].second)
            {
            case Stores_ID:
               if(Stores[lowerptr_Stores[0]].store == max_store)
                  found[0] = true;
               else if(max_store > Stores[Stores.size()-1].store)
                  atEnd[0] = true;
               else
               {
                  min_store = Stores[lowerptr_Stores[0]].store;
                  size_t leap = 1;
                  while (min_store < max_store && lowerptr_Stores[0] <= Stores.size()-1)
                  {
                     lowerptr_Stores[0] += leap;
                     leap *= 2;
                     if(lowerptr_Stores[0] < Stores.size()-1)
                     {
                        min_store = Stores[lowerptr_Stores[0]].store;
                     }
                     else
                     {
                        lowerptr_Stores[0] = Stores.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_store <= Stores[lowerptr_Stores[0]].store)
                  {
                     leap /= 2;
                     size_t high = lowerptr_Stores[0], low = lowerptr_Stores[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_store > Stores[mid - 1].store && max_store <= Stores[mid].store)
                        {
                           lowerptr_Stores[0] = mid;
                           break;
                        }
                        else if (max_store <= Stores[mid].store)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (Stores[mid-1].store >= max_store)
                        mid -= 1;
                     lowerptr_Stores[0] = mid;
                  }
                  max_store = Stores[lowerptr_Stores[0]].store;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            case V17_ID:
               if(V17[lowerptr_V17[0]].store == max_store)
                  found[0] = true;
               else if(max_store > V17[V17.size()-1].store)
                  atEnd[0] = true;
               else
               {
                  min_store = V17[lowerptr_V17[0]].store;
                  size_t leap = 1;
                  while (min_store < max_store && lowerptr_V17[0] <= V17.size()-1)
                  {
                     lowerptr_V17[0] += leap;
                     leap *= 2;
                     if(lowerptr_V17[0] < V17.size()-1)
                     {
                        min_store = V17[lowerptr_V17[0]].store;
                     }
                     else
                     {
                        lowerptr_V17[0] = V17.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_store <= V17[lowerptr_V17[0]].store)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V17[0], low = lowerptr_V17[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_store > V17[mid - 1].store && max_store <= V17[mid].store)
                        {
                           lowerptr_V17[0] = mid;
                           break;
                        }
                        else if (max_store <= V17[mid].store)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V17[mid-1].store >= max_store)
                        mid -= 1;
                     lowerptr_V17[0] = mid;
                  }
                  max_store = V17[lowerptr_V17[0]].store;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            }
         } while (!found[0] && !atEnd[0]);
         // End Seek Value
         // If atEnd break loop
         if(atEnd[0])
            break;
         upperptr_Stores[0] = lowerptr_Stores[0];
         while(upperptr_Stores[0]<Stores.size()-1 && Stores[upperptr_Stores[0]+1].store == max_store)
         {
            ++upperptr_Stores[0];
         }
         upperptr_V17[0] = lowerptr_V17[0];
         while(upperptr_V17[0]<V17.size()-1 && V17[upperptr_V17[0]+1].store == max_store)
         {
            ++upperptr_V17[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         Stores_tuple &StoresTuple = Stores[lowerptr_Stores[0]];
         V17_tuple &V17Tuple = V17[lowerptr_V17[0]];
         double *aggregates_V17 = V17Tuple.aggregates;
         double count = upperptr_Stores[0] - lowerptr_Stores[0] + 1;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[0+i] += aggregates_V17[0+i];
         memset(addTuple, true, sizeof(bool) * 1);
         memset(&aggregateRegister[3], 0, sizeof(double) * 1);
         ptr_Stores = lowerptr_Stores[0];
         while(ptr_Stores <= upperptr_Stores[0])
         {
            Stores_tuple &StoresTuple = Stores[ptr_Stores];
            localRegister[0] = f_Stores(StoresTuple.store,StoresTuple.city,StoresTuple.state,StoresTuple.store_type,StoresTuple.cluster);
            aggregateRegister[3] += localRegister[0];
            V18_iterator = V18_map.find({StoresTuple.city});
            if (V18_iterator != V18_map.end())
               aggregates_V18 = &V18_iterator->second.aggregates[0];
            else
               aggregates_V18 = &V18_map.insert({{StoresTuple.city},{}}).first->second.aggregates[0];
            aggregates_V18[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V18[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V18[2] += aggregateRegister[2]*aggregateRegister[3];
            V19_iterator = V19_map.find({StoresTuple.state});
            if (V19_iterator != V19_map.end())
               aggregates_V19 = &V19_iterator->second.aggregates[0];
            else
               aggregates_V19 = &V19_map.insert({{StoresTuple.state},{}}).first->second.aggregates[0];
            aggregates_V19[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V19[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V19[2] += aggregateRegister[2]*aggregateRegister[3];
            V20_iterator = V20_map.find({StoresTuple.store_type});
            if (V20_iterator != V20_map.end())
               aggregates_V20 = &V20_iterator->second.aggregates[0];
            else
               aggregates_V20 = &V20_map.insert({{StoresTuple.store_type},{}}).first->second.aggregates[0];
            aggregates_V20[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V20[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V20[2] += aggregateRegister[2]*aggregateRegister[3];
            V21_iterator = V21_map.find({StoresTuple.cluster});
            if (V21_iterator != V21_map.end())
               aggregates_V21 = &V21_iterator->second.aggregates[0];
            else
               aggregates_V21 = &V21_map.insert({{StoresTuple.cluster},{}}).first->second.aggregates[0];
            aggregates_V21[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V21[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V21[2] += aggregateRegister[2]*aggregateRegister[3];
            ++ptr_Stores;
         }
         lowerptr_Stores[0] = upperptr_Stores[0];
         lowerptr_V17[0] = upperptr_V17[0];
         switch(order_store[rel[0]].second)
         {
         case Stores_ID:
            lowerptr_Stores[0] += 1;
            if(lowerptr_Stores[0] > Stores.size()-1)
               atEnd[0] = true;
            else
            {
               max_store = Stores[lowerptr_Stores[0]].store;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         case V17_ID:
            lowerptr_V17[0] += 1;
            if(lowerptr_V17[0] > V17.size()-1)
               atEnd[0] = true;
            else
            {
               max_store = V17[lowerptr_V17[0]].store;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V18.reserve(V18_map.size());
      for (const auto& kv_pair : V18_map)
      {
         V18.emplace_back(kv_pair.first.city);
         memcpy(&V18.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V18.begin(),V18.end(),[ ](const V18_tuple& lhs, const V18_tuple& rhs)
      {
         if(lhs.city != rhs.city)
            return lhs.city < rhs.city;
         return false;
      });
      V19.reserve(V19_map.size());
      for (const auto& kv_pair : V19_map)
      {
         V19.emplace_back(kv_pair.first.state);
         memcpy(&V19.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V19.begin(),V19.end(),[ ](const V19_tuple& lhs, const V19_tuple& rhs)
      {
         if(lhs.state != rhs.state)
            return lhs.state < rhs.state;
         return false;
      });
      V20.reserve(V20_map.size());
      for (const auto& kv_pair : V20_map)
      {
         V20.emplace_back(kv_pair.first.store_type);
         memcpy(&V20.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V20.begin(),V20.end(),[ ](const V20_tuple& lhs, const V20_tuple& rhs)
      {
         if(lhs.store_type != rhs.store_type)
            return lhs.store_type < rhs.store_type;
         return false;
      });
      V21.reserve(V21_map.size());
      for (const auto& kv_pair : V21_map)
      {
         V21.emplace_back(kv_pair.first.cluster);
         memcpy(&V21.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V21.begin(),V21.end(),[ ](const V21_tuple& lhs, const V21_tuple& rhs)
      {
         if(lhs.cluster != rhs.cluster)
            return lhs.cluster < rhs.cluster;
         return false;
      });
   }

}
