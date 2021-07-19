#include "ComputeGroup4.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup4()
   {
      int max_item;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Items[1] = {}, upperptr_Items[1] = {}; 
      upperptr_Items[0] = Items.size()-1;
      size_t ptr_Items = 0;
      double *aggregates_V4 = nullptr;
      int min_item;
      double aggregateRegister[2] = {};
      double localRegister[1] = {};
      size_t rel[1] = {}, numOfRel[1] = {1};
      max_item = Items[0].item;
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         upperptr_Items[0] = lowerptr_Items[0];
         while(upperptr_Items[0]<Items.size()-1 && Items[upperptr_Items[0]+1].item == max_item)
         {
            ++upperptr_Items[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 2);
         Items_tuple &ItemsTuple = Items[lowerptr_Items[0]];
         double count = upperptr_Items[0] - lowerptr_Items[0] + 1;
         memset(&aggregateRegister[1], 0, sizeof(double) * 1);
         memset(&aggregateRegister[0], 0, sizeof(double) * 1);
         ptr_Items = lowerptr_Items[0];
         while(ptr_Items <= upperptr_Items[0])
         {
            Items_tuple &ItemsTuple = Items[ptr_Items];
            localRegister[0] = f_Items(ItemsTuple.item,ItemsTuple.family,ItemsTuple.itemclass,ItemsTuple.perishable);
            aggregateRegister[0] += localRegister[0];
            ++ptr_Items;
         }
         aggregateRegister[1] += aggregateRegister[0];
         memset(addTuple, true, sizeof(bool) * 1);
         V4.emplace_back(ItemsTuple.item);
         aggregates_V4 = V4.back().aggregates;
         aggregates_V4[0] += aggregateRegister[1];
         lowerptr_Items[0] = upperptr_Items[0];
         lowerptr_Items[0] += 1;
         if(lowerptr_Items[0] > Items.size()-1)
            atEnd[0] = true;
         else
            max_item = Items[lowerptr_Items[0]].item;
      }
   }

}
