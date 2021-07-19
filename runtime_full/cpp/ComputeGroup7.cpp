#include "ComputeGroup7.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   struct V11_key
   {
      int holiday_type;
      V11_key(const int& holiday_type) : holiday_type(holiday_type)
      {  }
      bool operator==(const V11_key &other) const
      {
         return this->holiday_type == other.holiday_type ;
      }
   };

   struct V11_value
   {
      double aggregates[3];
   };

   struct V12_key
   {
      int locale;
      V12_key(const int& locale) : locale(locale)
      {  }
      bool operator==(const V12_key &other) const
      {
         return this->locale == other.locale ;
      }
   };

   struct V12_value
   {
      double aggregates[3];
   };

   struct V13_key
   {
      int locale_id;
      V13_key(const int& locale_id) : locale_id(locale_id)
      {  }
      bool operator==(const V13_key &other) const
      {
         return this->locale_id == other.locale_id ;
      }
   };

   struct V13_value
   {
      double aggregates[3];
   };

   struct V14_key
   {
      int transferred;
      V14_key(const int& transferred) : transferred(transferred)
      {  }
      bool operator==(const V14_key &other) const
      {
         return this->transferred == other.transferred ;
      }
   };

   struct V14_value
   {
      double aggregates[3];
   };

   struct V11_keyhash
   {
      size_t operator()(const V11_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.holiday_type)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V12_keyhash
   {
      size_t operator()(const V12_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.locale)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V13_keyhash
   {
      size_t operator()(const V13_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.locale_id)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   struct V14_keyhash
   {
      size_t operator()(const V14_key &key ) const
      {
         size_t h = 0;
         h ^= std::hash<int>()(key.transferred)+ 0x9e3779b9 + (h<<6) + (h>>2);
         return h;
      }
   };

   void computeGroup7()
   {
      std::unordered_map<V11_key,V11_value,V11_keyhash> V11_map;
      std::unordered_map<V11_key,V11_value,V11_keyhash>::iterator V11_iterator;
      std::pair<std::unordered_map<V11_key,V11_value,V11_keyhash>::iterator,bool> V11_pair;
      V11_map.reserve(500000);
      std::unordered_map<V12_key,V12_value,V12_keyhash> V12_map;
      std::unordered_map<V12_key,V12_value,V12_keyhash>::iterator V12_iterator;
      std::pair<std::unordered_map<V12_key,V12_value,V12_keyhash>::iterator,bool> V12_pair;
      V12_map.reserve(500000);
      std::unordered_map<V13_key,V13_value,V13_keyhash> V13_map;
      std::unordered_map<V13_key,V13_value,V13_keyhash>::iterator V13_iterator;
      std::pair<std::unordered_map<V13_key,V13_value,V13_keyhash>::iterator,bool> V13_pair;
      V13_map.reserve(500000);
      std::unordered_map<V14_key,V14_value,V14_keyhash> V14_map;
      std::unordered_map<V14_key,V14_value,V14_keyhash>::iterator V14_iterator;
      std::pair<std::unordered_map<V14_key,V14_value,V14_keyhash>::iterator,bool> V14_pair;
      V14_map.reserve(500000);
      int max_date;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Holiday[1] = {}, upperptr_Holiday[1] = {}; 
      upperptr_Holiday[0] = Holiday.size()-1;
      size_t lowerptr_V10[1] = {}, upperptr_V10[1] = {}; 
      upperptr_V10[0] = V10.size()-1;
      size_t ptr_Holiday = 0;
      double *aggregates_V11 = nullptr, *aggregates_V12 = nullptr, *aggregates_V13 = nullptr, *aggregates_V14 = nullptr, *aggregates_V10 = nullptr;
      int min_date;
      double aggregateRegister[4] = {};
      double localRegister[1] = {};
      size_t rel[1] = {}, numOfRel[1] = {2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_date[2];
      if(Holiday[lowerptr_Holiday[0]].date < V10[lowerptr_V10[0]].date)
      {
         order_date[0] = std::make_pair(Holiday[lowerptr_Holiday[0]].date, Holiday_ID);
         order_date[1] = std::make_pair(V10[lowerptr_V10[0]].date, V10_ID);
      }
      else
      {
         order_date[0] = std::make_pair(V10[lowerptr_V10[0]].date, V10_ID);
         order_date[1] = std::make_pair(Holiday[lowerptr_Holiday[0]].date, Holiday_ID);
      }
      min_date = order_date[0].first;
      max_date = order_date[1].first;
      /*********** ORDERING RELATIONS *************/
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         found[0] = false;
         // Seek Value
         do
         {
            switch(order_date[rel[0]].second)
            {
            case Holiday_ID:
               if(Holiday[lowerptr_Holiday[0]].date == max_date)
                  found[0] = true;
               else if(max_date > Holiday[Holiday.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = Holiday[lowerptr_Holiday[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_Holiday[0] <= Holiday.size()-1)
                  {
                     lowerptr_Holiday[0] += leap;
                     leap *= 2;
                     if(lowerptr_Holiday[0] < Holiday.size()-1)
                     {
                        min_date = Holiday[lowerptr_Holiday[0]].date;
                     }
                     else
                     {
                        lowerptr_Holiday[0] = Holiday.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= Holiday[lowerptr_Holiday[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_Holiday[0], low = lowerptr_Holiday[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > Holiday[mid - 1].date && max_date <= Holiday[mid].date)
                        {
                           lowerptr_Holiday[0] = mid;
                           break;
                        }
                        else if (max_date <= Holiday[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (Holiday[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_Holiday[0] = mid;
                  }
                  max_date = Holiday[lowerptr_Holiday[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            case V10_ID:
               if(V10[lowerptr_V10[0]].date == max_date)
                  found[0] = true;
               else if(max_date > V10[V10.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = V10[lowerptr_V10[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_V10[0] <= V10.size()-1)
                  {
                     lowerptr_V10[0] += leap;
                     leap *= 2;
                     if(lowerptr_V10[0] < V10.size()-1)
                     {
                        min_date = V10[lowerptr_V10[0]].date;
                     }
                     else
                     {
                        lowerptr_V10[0] = V10.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= V10[lowerptr_V10[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V10[0], low = lowerptr_V10[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > V10[mid - 1].date && max_date <= V10[mid].date)
                        {
                           lowerptr_V10[0] = mid;
                           break;
                        }
                        else if (max_date <= V10[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V10[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_V10[0] = mid;
                  }
                  max_date = V10[lowerptr_V10[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            }
         } while (!found[0] && !atEnd[0]);
         // End Seek Value
         // If atEnd break loop
         if(atEnd[0])
            break;
         upperptr_Holiday[0] = lowerptr_Holiday[0];
         while(upperptr_Holiday[0]<Holiday.size()-1 && Holiday[upperptr_Holiday[0]+1].date == max_date)
         {
            ++upperptr_Holiday[0];
         }
         upperptr_V10[0] = lowerptr_V10[0];
         while(upperptr_V10[0]<V10.size()-1 && V10[upperptr_V10[0]+1].date == max_date)
         {
            ++upperptr_V10[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         Holiday_tuple &HolidayTuple = Holiday[lowerptr_Holiday[0]];
         V10_tuple &V10Tuple = V10[lowerptr_V10[0]];
         double *aggregates_V10 = V10Tuple.aggregates;
         double count = upperptr_Holiday[0] - lowerptr_Holiday[0] + 1;
         memset(&aggregateRegister[0], 0, sizeof(double) * 3);
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[0+i] += aggregates_V10[0+i];
         memset(addTuple, true, sizeof(bool) * 1);
         memset(&aggregateRegister[3], 0, sizeof(double) * 1);
         ptr_Holiday = lowerptr_Holiday[0];
         while(ptr_Holiday <= upperptr_Holiday[0])
         {
            Holiday_tuple &HolidayTuple = Holiday[ptr_Holiday];
            localRegister[0] = f_Holiday(HolidayTuple.date,HolidayTuple.holiday_type,HolidayTuple.locale,HolidayTuple.locale_id,HolidayTuple.transferred);
            aggregateRegister[3] += localRegister[0];
            V11_iterator = V11_map.find({HolidayTuple.holiday_type});
            if (V11_iterator != V11_map.end())
               aggregates_V11 = &V11_iterator->second.aggregates[0];
            else
               aggregates_V11 = &V11_map.insert({{HolidayTuple.holiday_type},{}}).first->second.aggregates[0];
            aggregates_V11[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V11[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V11[2] += aggregateRegister[2]*aggregateRegister[3];
            V12_iterator = V12_map.find({HolidayTuple.locale});
            if (V12_iterator != V12_map.end())
               aggregates_V12 = &V12_iterator->second.aggregates[0];
            else
               aggregates_V12 = &V12_map.insert({{HolidayTuple.locale},{}}).first->second.aggregates[0];
            aggregates_V12[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V12[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V12[2] += aggregateRegister[2]*aggregateRegister[3];
            V13_iterator = V13_map.find({HolidayTuple.locale_id});
            if (V13_iterator != V13_map.end())
               aggregates_V13 = &V13_iterator->second.aggregates[0];
            else
               aggregates_V13 = &V13_map.insert({{HolidayTuple.locale_id},{}}).first->second.aggregates[0];
            aggregates_V13[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V13[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V13[2] += aggregateRegister[2]*aggregateRegister[3];
            V14_iterator = V14_map.find({HolidayTuple.transferred});
            if (V14_iterator != V14_map.end())
               aggregates_V14 = &V14_iterator->second.aggregates[0];
            else
               aggregates_V14 = &V14_map.insert({{HolidayTuple.transferred},{}}).first->second.aggregates[0];
            aggregates_V14[0] += aggregateRegister[0]*aggregateRegister[3];
            aggregates_V14[1] += aggregateRegister[1]*aggregateRegister[3];
            aggregates_V14[2] += aggregateRegister[2]*aggregateRegister[3];
            ++ptr_Holiday;
         }
         lowerptr_Holiday[0] = upperptr_Holiday[0];
         lowerptr_V10[0] = upperptr_V10[0];
         switch(order_date[rel[0]].second)
         {
         case Holiday_ID:
            lowerptr_Holiday[0] += 1;
            if(lowerptr_Holiday[0] > Holiday.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = Holiday[lowerptr_Holiday[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         case V10_ID:
            lowerptr_V10[0] += 1;
            if(lowerptr_V10[0] > V10.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = V10[lowerptr_V10[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V11.reserve(V11_map.size());
      for (const auto& kv_pair : V11_map)
      {
         V11.emplace_back(kv_pair.first.holiday_type);
         memcpy(&V11.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V11.begin(),V11.end(),[ ](const V11_tuple& lhs, const V11_tuple& rhs)
      {
         if(lhs.holiday_type != rhs.holiday_type)
            return lhs.holiday_type < rhs.holiday_type;
         return false;
      });
      V12.reserve(V12_map.size());
      for (const auto& kv_pair : V12_map)
      {
         V12.emplace_back(kv_pair.first.locale);
         memcpy(&V12.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V12.begin(),V12.end(),[ ](const V12_tuple& lhs, const V12_tuple& rhs)
      {
         if(lhs.locale != rhs.locale)
            return lhs.locale < rhs.locale;
         return false;
      });
      V13.reserve(V13_map.size());
      for (const auto& kv_pair : V13_map)
      {
         V13.emplace_back(kv_pair.first.locale_id);
         memcpy(&V13.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V13.begin(),V13.end(),[ ](const V13_tuple& lhs, const V13_tuple& rhs)
      {
         if(lhs.locale_id != rhs.locale_id)
            return lhs.locale_id < rhs.locale_id;
         return false;
      });
      V14.reserve(V14_map.size());
      for (const auto& kv_pair : V14_map)
      {
         V14.emplace_back(kv_pair.first.transferred);
         memcpy(&V14.back().aggregates[0],&kv_pair.second.aggregates[0],24);
      }
      std::sort(V14.begin(),V14.end(),[ ](const V14_tuple& lhs, const V14_tuple& rhs)
      {
         if(lhs.transferred != rhs.transferred)
            return lhs.transferred < rhs.transferred;
         return false;
      });
   }

}
