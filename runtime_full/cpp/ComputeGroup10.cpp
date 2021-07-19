#include "ComputeGroup10.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   struct V23_key
   {
      int family;
      V23_key(const int& family) : family(family)
      {  }
      bool operator==(const V23_key &other) const
      {
         return this->family == other.family ;
      }
   };

   struct V23_value
   {
      double aggregates[3];
   };

   struct V24_key
   {
      int itemclass;
      V24_key(const int& itemclass) : itemclass(itemclass)
      {  }
      bool operator==(const V24_key &other) const
      {
         return this->itemclass == other.itemclass ;
      }
   };

   struct V24_value
   {
      double aggregates[3];
   };

   struct V25_key
   {
      int perishable;
      V25_key(const int& perishable) : perishable(perishable)
      {  }
      bool operator==(const V25_key &other) const
      {
         return this->perishable == other.perishable ;
      }
   };

   struct V25_value
   {
      double aggregates[3];
   };

   struct V23_keyhash
   {
      size_t operator()(const V23_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.family)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V24_keyhash
   {
      size_t operator()(const V24_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.itemclass)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V25_keyhash
   {
      size_t operator()(const V25_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.perishable)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   void computeGroup10()
   {
      std::unordered_map<V23_key,V23_value,V23_keyhash> V23_map;
      std::unordered_map<V23_key,V23_value,V23_keyhash>::iterator V23_iterator;
      std::pair<std::unordered_map<V23_key,V23_value,V23_keyhash>::iterator,bool> V23_pair;
      V23_map.reserve(500000);
      std::unordered_map<V24_key,V24_value,V24_keyhash> V24_map;
      std::unordered_map<V24_key,V24_value,V24_keyhash>::iterator V24_iterator;
      std::pair<std::unordered_map<V24_key,V24_value,V24_keyhash>::iterator,bool> V24_pair;
      V24_map.reserve(500000);
      std::unordered_map<V25_key,V25_value,V25_keyhash> V25_map;
      std::unordered_map<V25_key,V25_value,V25_keyhash>::iterator V25_iterator;
      std::pair<std::unordered_map<V25_key,V25_value,V25_keyhash>::iterator,bool> V25_pair;
      V25_map.reserve(500000);
      int max_item;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Items[1] = {}, upperptr_Items[1] = {}; 
      upperptr_Items[0] = Items.size()-1;
      size_t lowerptr_V22[1] = {}, upperptr_V22[1] = {}; 
      upperptr_V22[0] = V22.size()-1;
      size_t ptr_Items = 0;
      double *aggregates_V23 = nullptr, *aggregates_V24 = nullptr, *aggregates_V25 = nullptr, *aggregates_V22 = nullptr;
      int min_item;
      double aggregateRegister[4] = {};
      double localRegister[1] = {};
      size_t rel[1] = {}, numOfRel[1] = {2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_item[2];
      if(Items[lowerptr_Items[0]].item < V22[lowerptr_V22[0]].item)
      {
         order_item[0] = std::make_pair(Items[lowerptr_Items[0]].item, Items_ID);
         order_item[1] = std::make_pair(V22[lowerptr_V22[0]].item, V22_ID);
      }
      else
      {
         order_item[0] = std::make_pair(V22[lowerptr_V22[0]].item, V22_ID);
         order_item[1] = std::make_pair(Items[lowerptr_Items[0]].item, Items_ID);
      }
      min_item = order_item[0].first;
      max_item = order_item[1].first;
      /*********** ORDERING RELATIONS *************/
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         found[0] = false;
         // Seek Value
         do
         {
            switch(order_item[rel[0]].second)
            {
            case Items_ID:
               if(Items[lowerptr_Items[0]].item == max_item)
                  found[0] = true;
               else if(max_item > Items[Items.size()-1].item)
                  atEnd[0] = true;
               else
               {
                  min_item = Items[lowerptr_Items[0]].item;
                  size_t leap = 1;
                  while (min_item < max_item && lowerptr_Items[0] <= Items.size()-1)
                  {
                     lowerptr_Items[0] += leap;
                     leap *= 2;
                     if(lowerptr_Items[0] < Items.size()-1)
                     {
                        min_item = Items[lowerptr_Items[0]].item;
                     }
                     else
                     {
                        lowerptr_Items[0] = Items.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_item <= Items[lowerptr_Items[0]].item)
                  {
                     leap /= 2;
                     size_t high = lowerptr_Items[0], low = lowerptr_Items[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_item > Items[mid - 1].item && max_item <= Items[mid].item)
                        {
                           lowerptr_Items[0] = mid;
                           break;
                        }
                        else if (max_item <= Items[mid].item)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (Items[mid-1].item >= max_item)
                        mid -= 1;
                     lowerptr_Items[0] = mid;
                  }
                  max_item = Items[lowerptr_Items[0]].item;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            case V22_ID:
               if(V22[lowerptr_V22[0]].item == max_item)
                  found[0] = true;
               else if(max_item > V22[V22.size()-1].item)
                  atEnd[0] = true;
               else
               {
                  min_item = V22[lowerptr_V22[0]].item;
                  size_t leap = 1;
                  while (min_item < max_item && lowerptr_V22[0] <= V22.size()-1)
                  {
                     lowerptr_V22[0] += leap;
                     leap *= 2;
                     if(lowerptr_V22[0] < V22.size()-1)
                     {
                        min_item = V22[lowerptr_V22[0]].item;
                     }
                     else
                     {
                        lowerptr_V22[0] = V22.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_item <= V22[lowerptr_V22[0]].item)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V22[0], low = lowerptr_V22[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_item > V22[mid - 1].item && max_item <= V22[mid].item)
                        {
                           lowerptr_V22[0] = mid;
                           break;
                        }
                        else if (max_item <= V22[mid].item)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V22[mid-1].item >= max_item)
                        mid -= 1;
                     lowerptr_V22[0] = mid;
                  }
                  max_item = V22[lowerptr_V22[0]].item;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            }
         } while (!found[0] && !atEnd[0]);
         // End Seek Value
         // If atEnd break loop
         if(atEnd[0])
            break;
         upperptr_Items[0] = lowerptr_Items[0];
         while(upperptr_Items[0]<Items.size()-1 && Items[upperptr_Items[0]+1].item == max_item)
         {
            ++upperptr_Items[0];
         }
         upperptr_V22[0] = lowerptr_V22[0];
         while(upperptr_V22[0]<V22.size()-1 && V22[upperptr_V22[0]+1].item == max_item)
         {
            ++upperptr_V22[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         Items_tuple &ItemsTuple = Items[lowerptr_Items[0]];
         V22_tuple &V22Tuple = V22[lowerptr_V22[0]];
         double *aggregates_V22 = V22Tuple.aggregates;
         double count = upperptr_Items[0] - lowerptr_Items[0] + 1;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[0+i] += aggregates_V22[0+i];
         memset(addTuple, true, sizeof(bool) * 1);
         memset(&aggregateRegister[3], 0, sizeof(double) * 1);
         ptr_Items = lowerptr_Items[0];
         while(ptr_Items <= upperptr_Items[0])
         {
            Items_tuple &ItemsTuple = Items[ptr_Items];
            localRegister[0] = f_Items(ItemsTuple.item,ItemsTuple.family,ItemsTuple.itemclass,ItemsTuple.perishable);
            aggregateRegister[3] += localRegister[0];
            V23_iterator = V23_map.find({ItemsTuple.family});
            if (V23_iterator != V23_map.end())
               aggregates_V23 = &V23_iterator->second.aggregates[0];
            else
               aggregates_V23 = &V23_map.insert({{ItemsTuple.family},{}}).first->second.aggregates[0];
            aggregates_V23[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V23[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V23[2] += aggregateRegister[2]*aggregateRegister[3];
            V24_iterator = V24_map.find({ItemsTuple.itemclass});
            if (V24_iterator != V24_map.end())
               aggregates_V24 = &V24_iterator->second.aggregates[0];
            else
               aggregates_V24 = &V24_map.insert({{ItemsTuple.itemclass},{}}).first->second.aggregates[0];
            aggregates_V24[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V24[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V24[2] += aggregateRegister[2]*aggregateRegister[3];
            V25_iterator = V25_map.find({ItemsTuple.perishable});
            if (V25_iterator != V25_map.end())
               aggregates_V25 = &V25_iterator->second.aggregates[0];
            else
               aggregates_V25 = &V25_map.insert({{ItemsTuple.perishable},{}}).first->second.aggregates[0];
            aggregates_V25[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V25[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V25[2] += aggregateRegister[2]*aggregateRegister[3];
            ++ptr_Items;
         }
         lowerptr_Items[0] = upperptr_Items[0];
         lowerptr_V22[0] = upperptr_V22[0];
         switch(order_item[rel[0]].second)
         {
         case Items_ID:
            lowerptr_Items[0] += 1;
            if(lowerptr_Items[0] > Items.size()-1)
               atEnd[0] = true;
            else
            {
               max_item = Items[lowerptr_Items[0]].item;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         case V22_ID:
            lowerptr_V22[0] += 1;
            if(lowerptr_V22[0] > V22.size()-1)
               atEnd[0] = true;
            else
            {
               max_item = V22[lowerptr_V22[0]].item;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V23.reserve(V23_map.size());
      for (const auto& kv_pair : V23_map)
      {
         V23.emplace_back(kv_pair.first.family);
         memcpy(&V23.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V23.begin(),V23.end(),[ ](const V23_tuple& lhs, const V23_tuple& rhs)
      {
         if(lhs.family != rhs.family)
            return lhs.family < rhs.family;
         return false;
      });
      V24.reserve(V24_map.size());
      for (const auto& kv_pair : V24_map)
      {
         V24.emplace_back(kv_pair.first.itemclass);
         memcpy(&V24.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V24.begin(),V24.end(),[ ](const V24_tuple& lhs, const V24_tuple& rhs)
      {
         if(lhs.itemclass != rhs.itemclass)
            return lhs.itemclass < rhs.itemclass;
         return false;
      });
      V25.reserve(V25_map.size());
      for (const auto& kv_pair : V25_map)
      {
         V25.emplace_back(kv_pair.first.perishable);
         memcpy(&V25.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V25.begin(),V25.end(),[ ](const V25_tuple& lhs, const V25_tuple& rhs)
      {
         if(lhs.perishable != rhs.perishable)
            return lhs.perishable < rhs.perishable;
         return false;
      });
   }

}
