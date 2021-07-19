#include "ComputeGroup2.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup2()
   {
      int max_date;
      int max_store;
      bool found[2] = {}, atEnd[2] = {}, addTuple[2] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Transactions[2] = {}, upperptr_Transactions[2] = {}; 
      upperptr_Transactions[0] = Transactions.size()-1;
      size_t ptr_Transactions = 0;
      double *aggregates_V2 = nullptr;
      int min_date;
      int min_store;
      double aggregateRegister[2] = {};
      double localRegister[1] = {};
      size_t rel[2] = {}, numOfRel[2] = {1,1};
      max_date = Transactions[0].date;
      rel[0] = 0;
      atEnd[0] = false;
      while(!atEnd[0])
      {
         upperptr_Transactions[0] = lowerptr_Transactions[0];
         while(upperptr_Transactions[0]<Transactions.size()-1 && Transactions[upperptr_Transactions[0]+1].date == max_date)
         {
            ++upperptr_Transactions[0];
         }
         addTuple[0] = false;
         Transactions_tuple &TransactionsTuple = Transactions[lowerptr_Transactions[0]];
         upperptr_Transactions[1] = upperptr_Transactions[0];
         lowerptr_Transactions[1] = lowerptr_Transactions[0];
         max_store = Transactions[0].store;
         rel[1] = 0;
         atEnd[1] = false;
         while(!atEnd[1])
         {
            upperptr_Transactions[1] = lowerptr_Transactions[1];
            while(upperptr_Transactions[1]<upperptr_Transactions[0] && Transactions[upperptr_Transactions[1]+1].store == max_store)
            {
               ++upperptr_Transactions[1];
            }
            addTuple[1] = false;
            memset(&aggregateRegister[0], 0, sizeof(double) * 2);
            Transactions_tuple &TransactionsTuple = Transactions[lowerptr_Transactions[1]];
            double count = upperptr_Transactions[1] - lowerptr_Transactions[1] + 1;
            memset(&aggregateRegister[1], 0, sizeof(double) * 1);
            memset(&aggregateRegister[0], 0, sizeof(double) * 1);
            ptr_Transactions = lowerptr_Transactions[1];
            while(ptr_Transactions <= upperptr_Transactions[1])
            {
               Transactions_tuple &TransactionsTuple = Transactions[ptr_Transactions];
               localRegister[0] = f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               aggregateRegister[0] += localRegister[0];
               ++ptr_Transactions;
            }
            aggregateRegister[1] += aggregateRegister[0];
            memset(addTuple, true, sizeof(bool) * 2);
            V2.emplace_back(TransactionsTuple.date,TransactionsTuple.store);
            aggregates_V2 = V2.back().aggregates;
            aggregates_V2[0] += aggregateRegister[1];
            lowerptr_Transactions[1] = upperptr_Transactions[1];
            lowerptr_Transactions[1] += 1;
            if(lowerptr_Transactions[1] > upperptr_Transactions[0])
               atEnd[1] = true;
            else
               max_store = Transactions[lowerptr_Transactions[1]].store;
         }
         lowerptr_Transactions[0] = upperptr_Transactions[0];
         lowerptr_Transactions[0] += 1;
         if(lowerptr_Transactions[0] > Transactions.size()-1)
            atEnd[0] = true;
         else
            max_date = Transactions[lowerptr_Transactions[0]].date;
      }
   }

}
