#include "ComputeGroup3.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup3()
   {
      int max_store;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Stores[1] = {}, upperptr_Stores[1] = {}; 
      upperptr_Stores[0] = Stores.size()-1;
      size_t ptr_Stores = 0;
      double *aggregates_V3 = nullptr;
      int min_store;
      double aggregateRegister[2] = {};
      double localRegister[1] = {};
      size_t rel[1] = {}, numOfRel[1] = {1};
      max_store = Stores[0].store;
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         upperptr_Stores[0] = lowerptr_Stores[0];
         while(upperptr_Stores[0]<Stores.size()-1 && Stores[upperptr_Stores[0]+1].store == max_store)
         {
            ++upperptr_Stores[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 2);
         Stores_tuple &StoresTuple = Stores[lowerptr_Stores[0]];
         double count = upperptr_Stores[0] - lowerptr_Stores[0] + 1;
         memset(&aggregateRegister[1], 0, sizeof(double) * 1);
         memset(&aggregateRegister[0], 0, sizeof(double) * 1);
         ptr_Stores = lowerptr_Stores[0];
         while(ptr_Stores <= upperptr_Stores[0])
         {
            Stores_tuple &StoresTuple = Stores[ptr_Stores];
            localRegister[0] = f_Stores(StoresTuple.store,StoresTuple.city,StoresTuple.state,StoresTuple.store_type,StoresTuple.cluster);
            aggregateRegister[0] += localRegister[0];
            ++ptr_Stores;
         }
         aggregateRegister[1] += aggregateRegister[0];
         memset(addTuple, true, sizeof(bool) * 1);
         V3.emplace_back(StoresTuple.store);
         aggregates_V3 = V3.back().aggregates;
         aggregates_V3[0] += aggregateRegister[1];
         lowerptr_Stores[0] = upperptr_Stores[0];
         lowerptr_Stores[0] += 1;
         if(lowerptr_Stores[0] > Stores.size()-1)
            atEnd[0] = true;
         else
            max_store = Stores[lowerptr_Stores[0]].store;
      }
   }

}
