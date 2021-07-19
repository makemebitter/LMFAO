#include "ComputeGroup1.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup1()
   {
      int max_date;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Holiday[1] = {}, upperptr_Holiday[1] = {}; 
      upperptr_Holiday[0] = Holiday.size()-1;
      size_t ptr_Holiday = 0;
      double *aggregates_V1 = nullptr;
      int min_date;
      double aggregateRegister[2] = {};
      double localRegister[1] = {};
      size_t rel[1] = {}, numOfRel[1] = {1};
      max_date = Holiday[0].date;
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         upperptr_Holiday[0] = lowerptr_Holiday[0];
         while(upperptr_Holiday[0]<Holiday.size()-1 && Holiday[upperptr_Holiday[0]+1].date == max_date)
         {
            ++upperptr_Holiday[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 2);
         Holiday_tuple &HolidayTuple = Holiday[lowerptr_Holiday[0]];
         double count = upperptr_Holiday[0] - lowerptr_Holiday[0] + 1;
         memset(&aggregateRegister[1], 0, sizeof(double) * 1);
         memset(&aggregateRegister[0], 0, sizeof(double) * 1);
         ptr_Holiday = lowerptr_Holiday[0];
         while(ptr_Holiday <= upperptr_Holiday[0])
         {
            Holiday_tuple &HolidayTuple = Holiday[ptr_Holiday];
            localRegister[0] = f_Holiday(HolidayTuple.date,HolidayTuple.holiday_type,HolidayTuple.locale,HolidayTuple.locale_id,HolidayTuple.transferred);
            aggregateRegister[0] += localRegister[0];
            ++ptr_Holiday;
         }
         aggregateRegister[1] += aggregateRegister[0];
         memset(addTuple, true, sizeof(bool) * 1);
         V1.emplace_back(HolidayTuple.date);
         aggregates_V1 = V1.back().aggregates;
         aggregates_V1[0] += aggregateRegister[1];
         lowerptr_Holiday[0] = upperptr_Holiday[0];
         lowerptr_Holiday[0] += 1;
         if(lowerptr_Holiday[0] > Holiday.size()-1)
            atEnd[0] = true;
         else
            max_date = Holiday[lowerptr_Holiday[0]].date;
      }
   }

}
