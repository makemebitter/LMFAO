#include "ComputeGroup0.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup0()
   {
      int max_date;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Oil[1] = {}, upperptr_Oil[1] = {}; 
      upperptr_Oil[0] = Oil.size()-1;
      size_t ptr_Oil = 0;
      double *aggregates_V0 = nullptr;
      int min_date;
      double aggregateRegister[2] = {};
      double localRegister[1] = {};
      size_t rel[1] = {}, numOfRel[1] = {1};
      max_date = Oil[0].date;
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         upperptr_Oil[0] = lowerptr_Oil[0];
         while(upperptr_Oil[0]<Oil.size()-1 && Oil[upperptr_Oil[0]+1].date == max_date)
         {
            ++upperptr_Oil[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 2);
         Oil_tuple &OilTuple = Oil[lowerptr_Oil[0]];
         double count = upperptr_Oil[0] - lowerptr_Oil[0] + 1;
         memset(&aggregateRegister[1], 0, sizeof(double) * 1);
         memset(&aggregateRegister[0], 0, sizeof(double) * 1);
         ptr_Oil = lowerptr_Oil[0];
         while(ptr_Oil <= upperptr_Oil[0])
         {
            Oil_tuple &OilTuple = Oil[ptr_Oil];
            localRegister[0] = f_Oil(OilTuple.date,OilTuple.oilprize);
            aggregateRegister[0] += localRegister[0];
            ++ptr_Oil;
         }
         aggregateRegister[1] += aggregateRegister[0];
         memset(addTuple, true, sizeof(bool) * 1);
         V0.emplace_back(OilTuple.date);
         aggregates_V0 = V0.back().aggregates;
         aggregates_V0[0] += aggregateRegister[1];
         lowerptr_Oil[0] = upperptr_Oil[0];
         lowerptr_Oil[0] += 1;
         if(lowerptr_Oil[0] > Oil.size()-1)
            atEnd[0] = true;
         else
            max_date = Oil[lowerptr_Oil[0]].date;
      }
   }

}
