#include "ComputeGroup0.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   std::vector<V4_tuple> local_V4[8];

   void computeGroup0Parallelized(const size_t thread, const size_t lowerptr, const size_t upperptr)
   {
      std::vector<V4_tuple>& V4 = local_V4[thread];
      int max_date;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Sales[1] = {}, upperptr_Sales[1] = {}; 
      upperptr_Sales[0] = upperptr;
      lowerptr_Sales[0] = lowerptr;
      size_t ptr_Sales = 0;
      double *aggregates_V4 = nullptr;
      int min_date;
      double aggregateRegister[6] = {};
      double localRegister[3] = {};
      size_t rel[1] = {}, numOfRel[1] = {1};
      max_date = Sales[0].date;
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         upperptr_Sales[0] = lowerptr_Sales[0];
         while(upperptr_Sales[0]<upperptr && Sales[upperptr_Sales[0]+1].date == max_date)
         {
            ++upperptr_Sales[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 6);
         Sales_tuple &SalesTuple = Sales[lowerptr_Sales[0]];
         double count = upperptr_Sales[0] - lowerptr_Sales[0] + 1;
         memset(&aggregateRegister[3], 0, sizeof(double) * 3);
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
            aggregateRegister[3+i] += aggregateRegister[0+i];
         memset(addTuple, true, sizeof(bool) * 1);
         V4.emplace_back(SalesTuple.date);
         aggregates_V4 = V4.back().aggregates;
         aggregates_V4[0] += aggregateRegister[3];
         aggregates_V4[1] += aggregateRegister[4];
         aggregates_V4[2] += aggregateRegister[5];
         lowerptr_Sales[0] = upperptr_Sales[0];
         lowerptr_Sales[0] += 1;
         if(lowerptr_Sales[0] > upperptr)
            atEnd[0] = true;
         else
            max_date = Sales[lowerptr_Sales[0]].date;
      }
   }
   void computeGroup0()
   {
      size_t lower, upper;
      lower = (size_t)(Sales.size() * ((double)0/8));
      upper = (size_t)(Sales.size() * ((double)1/8)) - 1;
      std::thread thread0(computeGroup0Parallelized,0,lower,upper);

      lower = (size_t)(Sales.size() * ((double)1/8));
      upper = (size_t)(Sales.size() * ((double)2/8)) - 1;
      std::thread thread1(computeGroup0Parallelized,1,lower,upper);

      lower = (size_t)(Sales.size() * ((double)2/8));
      upper = (size_t)(Sales.size() * ((double)3/8)) - 1;
      std::thread thread2(computeGroup0Parallelized,2,lower,upper);

      lower = (size_t)(Sales.size() * ((double)3/8));
      upper = (size_t)(Sales.size() * ((double)4/8)) - 1;
      std::thread thread3(computeGroup0Parallelized,3,lower,upper);

      lower = (size_t)(Sales.size() * ((double)4/8));
      upper = (size_t)(Sales.size() * ((double)5/8)) - 1;
      std::thread thread4(computeGroup0Parallelized,4,lower,upper);

      lower = (size_t)(Sales.size() * ((double)5/8));
      upper = (size_t)(Sales.size() * ((double)6/8)) - 1;
      std::thread thread5(computeGroup0Parallelized,5,lower,upper);

      lower = (size_t)(Sales.size() * ((double)6/8));
      upper = (size_t)(Sales.size() * ((double)7/8)) - 1;
      std::thread thread6(computeGroup0Parallelized,6,lower,upper);

      lower = (size_t)(Sales.size() * ((double)7/8));
      upper = (size_t)(Sales.size() * ((double)8/8)) - 1;
      std::thread thread7(computeGroup0Parallelized,7,lower,upper);

      thread0.join();
      thread1.join();
      thread2.join();
      thread3.join();
      thread4.join();
      thread5.join();
      thread6.join();
      thread7.join();
      V4.reserve(local_V4[0].size()+local_V4[1].size()+local_V4[2].size()+local_V4[3].size()+local_V4[4].size()+local_V4[5].size()+local_V4[6].size()+local_V4[7].size());
      V4.insert(V4.end(),local_V4[0].begin(), local_V4[0].end());
      for (size_t t = 1; t < 8; ++t)
      {
         std::vector<V4_tuple>& this_V4 = local_V4[t];
         if(V4.back().date==this_V4[0].date)
         {
            for (size_t agg = 0; agg < 3; ++agg)
               V4.back().aggregates[agg] += this_V4[0].aggregates[agg];
            V4.insert(V4.end(),this_V4.begin()+1,this_V4.end());
         }
         else
         {
            V4.insert(V4.end(), this_V4.begin(), this_V4.end());
         }
      }
   }

}
