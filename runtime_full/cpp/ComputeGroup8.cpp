#include "ComputeGroup8.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup8()
   {
      int max_date;
      int max_store;
      bool found[2] = {}, atEnd[2] = {}, addTuple[2] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Transactions[2] = {}, upperptr_Transactions[2] = {}; 
      upperptr_Transactions[0] = Transactions.size()-1;
      size_t lowerptr_V15[2] = {}, upperptr_V15[2] = {}; 
      upperptr_V15[0] = V15.size()-1;
      size_t ptr_Transactions = 0;
      double *aggregates_V16 = nullptr, *aggregates_V15 = nullptr;
      int min_date;
      int min_store;
      double aggregateRegister[152] = {};
      double localRegister[38] = {};
      double postRegister[228] = {};
      size_t rel[2] = {}, numOfRel[2] = {2,2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_date[2];
      if(Transactions[lowerptr_Transactions[0]].date < V15[lowerptr_V15[0]].date)
      {
         order_date[0] = std::make_pair(Transactions[lowerptr_Transactions[0]].date, Transactions_ID);
         order_date[1] = std::make_pair(V15[lowerptr_V15[0]].date, V15_ID);
      }
      else
      {
         order_date[0] = std::make_pair(V15[lowerptr_V15[0]].date, V15_ID);
         order_date[1] = std::make_pair(Transactions[lowerptr_Transactions[0]].date, Transactions_ID);
      }
      min_date = order_date[0].first;
      max_date = order_date[1].first;
      /*********** ORDERING RELATIONS *************/
      rel[0] = 0;
      atEnd[0] = false;
      memset(&postRegister[114], 0, sizeof(double) * 114);
      while(!atEnd[0])
      {
         found[0] = false;
         // Seek Value
         do
         {
            switch(order_date[rel[0]].second)
            {
            case Transactions_ID:
               if(Transactions[lowerptr_Transactions[0]].date == max_date)
                  found[0] = true;
               else if(max_date > Transactions[Transactions.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = Transactions[lowerptr_Transactions[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_Transactions[0] <= Transactions.size()-1)
                  {
                     lowerptr_Transactions[0] += leap;
                     leap *= 2;
                     if(lowerptr_Transactions[0] < Transactions.size()-1)
                     {
                        min_date = Transactions[lowerptr_Transactions[0]].date;
                     }
                     else
                     {
                        lowerptr_Transactions[0] = Transactions.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= Transactions[lowerptr_Transactions[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_Transactions[0], low = lowerptr_Transactions[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > Transactions[mid - 1].date && max_date <= Transactions[mid].date)
                        {
                           lowerptr_Transactions[0] = mid;
                           break;
                        }
                        else if (max_date <= Transactions[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (Transactions[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_Transactions[0] = mid;
                  }
                  max_date = Transactions[lowerptr_Transactions[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            case V15_ID:
               if(V15[lowerptr_V15[0]].date == max_date)
                  found[0] = true;
               else if(max_date > V15[V15.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = V15[lowerptr_V15[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_V15[0] <= V15.size()-1)
                  {
                     lowerptr_V15[0] += leap;
                     leap *= 2;
                     if(lowerptr_V15[0] < V15.size()-1)
                     {
                        min_date = V15[lowerptr_V15[0]].date;
                     }
                     else
                     {
                        lowerptr_V15[0] = V15.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= V15[lowerptr_V15[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V15[0], low = lowerptr_V15[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > V15[mid - 1].date && max_date <= V15[mid].date)
                        {
                           lowerptr_V15[0] = mid;
                           break;
                        }
                        else if (max_date <= V15[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V15[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_V15[0] = mid;
                  }
                  max_date = V15[lowerptr_V15[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            }
         } while (!found[0] && !atEnd[0]);
         // End Seek Value
         // If atEnd break loop
         if(atEnd[0])
            break;
         upperptr_Transactions[0] = lowerptr_Transactions[0];
         while(upperptr_Transactions[0]<Transactions.size()-1 && Transactions[upperptr_Transactions[0]+1].date == max_date)
         {
            ++upperptr_Transactions[0];
         }
         upperptr_V15[0] = lowerptr_V15[0];
         while(upperptr_V15[0]<V15.size()-1 && V15[upperptr_V15[0]+1].date == max_date)
         {
            ++upperptr_V15[0];
         }
         addTuple[0] = false;
         Transactions_tuple &TransactionsTuple = Transactions[lowerptr_Transactions[0]];
         V15_tuple &V15Tuple = V15[lowerptr_V15[0]];
         double *aggregates_V15 = V15Tuple.aggregates;
         upperptr_Transactions[1] = upperptr_Transactions[0];
         lowerptr_Transactions[1] = lowerptr_Transactions[0];
         upperptr_V15[1] = upperptr_V15[0];
         lowerptr_V15[1] = lowerptr_V15[0];
         /*********** ORDERING RELATIONS *************/
         std::pair<int, int> order_store[2];
         if(Transactions[lowerptr_Transactions[1]].store < V15[lowerptr_V15[1]].store)
         {
            order_store[0] = std::make_pair(Transactions[lowerptr_Transactions[1]].store, Transactions_ID);
            order_store[1] = std::make_pair(V15[lowerptr_V15[1]].store, V15_ID);
         }
         else
         {
            order_store[0] = std::make_pair(V15[lowerptr_V15[1]].store, V15_ID);
            order_store[1] = std::make_pair(Transactions[lowerptr_Transactions[1]].store, Transactions_ID);
         }
         min_store = order_store[0].first;
         max_store = order_store[1].first;
         /*********** ORDERING RELATIONS *************/
         rel[1] = 0;
         atEnd[1] = false;
         memset(&postRegister[0], 0, sizeof(double) * 114);
         while(!atEnd[1])
         {
            found[1] = false;
            // Seek Value
            do
            {
               switch(order_store[rel[1]].second)
               {
               case Transactions_ID:
                  if(Transactions[lowerptr_Transactions[1]].store == max_store)
                     found[1] = true;
                  else if(max_store > Transactions[upperptr_Transactions[0]].store)
                     atEnd[1] = true;
                  else
                  {
                     min_store = Transactions[lowerptr_Transactions[1]].store;
                     size_t leap = 1;
                     while (min_store < max_store && lowerptr_Transactions[1] <= upperptr_Transactions[0])
                     {
                        lowerptr_Transactions[1] += leap;
                        leap *= 2;
                        if(lowerptr_Transactions[1] < upperptr_Transactions[0])
                        {
                           min_store = Transactions[lowerptr_Transactions[1]].store;
                        }
                        else
                        {
                           lowerptr_Transactions[1] = upperptr_Transactions[0];
                           break;
                        }
                     }
                     /* Backtrack with binary search */
                     if (leap > 2 && max_store <= Transactions[lowerptr_Transactions[1]].store)
                     {
                        leap /= 2;
                        size_t high = lowerptr_Transactions[1], low = lowerptr_Transactions[1] - leap, mid = 0;
                        while (high > low && high != low)
                        {
                           mid = (high + low) / 2;
                           if (max_store > Transactions[mid - 1].store && max_store <= Transactions[mid].store)
                           {
                              lowerptr_Transactions[1] = mid;
                              break;
                           }
                           else if (max_store <= Transactions[mid].store)
                              high = mid - 1;
                           else 
                              low = mid + 1;
                        }
                        mid = (high + low) / 2;
                        if (Transactions[mid-1].store >= max_store)
                           mid -= 1;
                        lowerptr_Transactions[1] = mid;
                     }
                     max_store = Transactions[lowerptr_Transactions[1]].store;
                     rel[1] = (rel[1]+1) % numOfRel[1];
                  }
                  break;
               case V15_ID:
                  if(V15[lowerptr_V15[1]].store == max_store)
                     found[1] = true;
                  else if(max_store > V15[upperptr_V15[0]].store)
                     atEnd[1] = true;
                  else
                  {
                     min_store = V15[lowerptr_V15[1]].store;
                     size_t leap = 1;
                     while (min_store < max_store && lowerptr_V15[1] <= upperptr_V15[0])
                     {
                        lowerptr_V15[1] += leap;
                        leap *= 2;
                        if(lowerptr_V15[1] < upperptr_V15[0])
                        {
                           min_store = V15[lowerptr_V15[1]].store;
                        }
                        else
                        {
                           lowerptr_V15[1] = upperptr_V15[0];
                           break;
                        }
                     }
                     /* Backtrack with binary search */
                     if (leap > 2 && max_store <= V15[lowerptr_V15[1]].store)
                     {
                        leap /= 2;
                        size_t high = lowerptr_V15[1], low = lowerptr_V15[1] - leap, mid = 0;
                        while (high > low && high != low)
                        {
                           mid = (high + low) / 2;
                           if (max_store > V15[mid - 1].store && max_store <= V15[mid].store)
                           {
                              lowerptr_V15[1] = mid;
                              break;
                           }
                           else if (max_store <= V15[mid].store)
                              high = mid - 1;
                           else 
                              low = mid + 1;
                        }
                        mid = (high + low) / 2;
                        if (V15[mid-1].store >= max_store)
                           mid -= 1;
                        lowerptr_V15[1] = mid;
                     }
                     max_store = V15[lowerptr_V15[1]].store;
                     rel[1] = (rel[1]+1) % numOfRel[1];
                  }
                  break;
               }
            } while (!found[1] && !atEnd[1]);
            // End Seek Value
            // If atEnd break loop
            if(atEnd[1])
               break;
            upperptr_Transactions[1] = lowerptr_Transactions[1];
            while(upperptr_Transactions[1]<upperptr_Transactions[0] && Transactions[upperptr_Transactions[1]+1].store == max_store)
            {
               ++upperptr_Transactions[1];
            }
            upperptr_V15[1] = lowerptr_V15[1];
            while(upperptr_V15[1]<upperptr_V15[0] && V15[upperptr_V15[1]+1].store == max_store)
            {
               ++upperptr_V15[1];
            }
            addTuple[1] = false;
            memset(&aggregateRegister[0], 0, sizeof(double) * 152);
            Transactions_tuple &TransactionsTuple = Transactions[lowerptr_Transactions[1]];
            V15_tuple &V15Tuple = V15[lowerptr_V15[1]];
            double *aggregates_V15 = V15Tuple.aggregates;
            double count = upperptr_Transactions[1] - lowerptr_Transactions[1] + 1;
            memset(&aggregateRegister[38], 0, sizeof(double) * 114);
            memset(&aggregateRegister[0], 0, sizeof(double) * 38);
            ptr_Transactions = lowerptr_Transactions[1];
            while(ptr_Transactions <= upperptr_Transactions[1])
            {
               Transactions_tuple &TransactionsTuple = Transactions[ptr_Transactions];
               localRegister[0] = (TransactionsTuple.transactions <= 711.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[1] = (TransactionsTuple.transactions > 711.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[2] = (TransactionsTuple.transactions <= 856.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[3] = (TransactionsTuple.transactions > 856.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[4] = (TransactionsTuple.transactions <= 973.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[5] = (TransactionsTuple.transactions > 973.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[6] = (TransactionsTuple.transactions <= 1070.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[7] = (TransactionsTuple.transactions > 1070.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[8] = (TransactionsTuple.transactions <= 1157.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[9] = (TransactionsTuple.transactions > 1157.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[10] = (TransactionsTuple.transactions <= 1235.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[11] = (TransactionsTuple.transactions > 1235.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[12] = (TransactionsTuple.transactions <= 1304.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[13] = (TransactionsTuple.transactions > 1304.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[14] = (TransactionsTuple.transactions <= 1373.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[15] = (TransactionsTuple.transactions > 1373.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[16] = (TransactionsTuple.transactions <= 1453.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[17] = (TransactionsTuple.transactions > 1453.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[18] = (TransactionsTuple.transactions <= 1554.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[19] = (TransactionsTuple.transactions > 1554.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[20] = (TransactionsTuple.transactions <= 1681.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[21] = (TransactionsTuple.transactions > 1681.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[22] = (TransactionsTuple.transactions <= 1804.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[23] = (TransactionsTuple.transactions > 1804.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[24] = (TransactionsTuple.transactions <= 1945.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[25] = (TransactionsTuple.transactions > 1945.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[26] = (TransactionsTuple.transactions <= 2151.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[27] = (TransactionsTuple.transactions > 2151.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[28] = (TransactionsTuple.transactions <= 2390.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[29] = (TransactionsTuple.transactions > 2390.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[30] = (TransactionsTuple.transactions <= 2679.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[31] = (TransactionsTuple.transactions > 2679.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[32] = (TransactionsTuple.transactions <= 2997.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[33] = (TransactionsTuple.transactions > 2997.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[34] = (TransactionsTuple.transactions <= 3408.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[35] = (TransactionsTuple.transactions > 3408.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[36] = (TransactionsTuple.transactions <= 4070.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               localRegister[37] = (TransactionsTuple.transactions > 4070.000000)*f_Transactions(TransactionsTuple.date,TransactionsTuple.store,TransactionsTuple.transactions);
               for (size_t i = 0; i < 38;++i)
                  aggregateRegister[0+i] += localRegister[0+i];
               ++ptr_Transactions;
            }
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[38+i] += aggregates_V15[0+i]*aggregateRegister[0];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[41+i] += aggregates_V15[0+i]*aggregateRegister[1];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[44+i] += aggregates_V15[0+i]*aggregateRegister[2];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[47+i] += aggregates_V15[0+i]*aggregateRegister[3];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[50+i] += aggregates_V15[0+i]*aggregateRegister[4];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[53+i] += aggregates_V15[0+i]*aggregateRegister[5];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[56+i] += aggregates_V15[0+i]*aggregateRegister[6];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[59+i] += aggregates_V15[0+i]*aggregateRegister[7];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[62+i] += aggregates_V15[0+i]*aggregateRegister[8];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[65+i] += aggregates_V15[0+i]*aggregateRegister[9];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[68+i] += aggregates_V15[0+i]*aggregateRegister[10];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[71+i] += aggregates_V15[0+i]*aggregateRegister[11];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[74+i] += aggregates_V15[0+i]*aggregateRegister[12];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[77+i] += aggregates_V15[0+i]*aggregateRegister[13];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[80+i] += aggregates_V15[0+i]*aggregateRegister[14];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[83+i] += aggregates_V15[0+i]*aggregateRegister[15];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[86+i] += aggregates_V15[0+i]*aggregateRegister[16];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[89+i] += aggregates_V15[0+i]*aggregateRegister[17];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[92+i] += aggregates_V15[0+i]*aggregateRegister[18];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[95+i] += aggregates_V15[0+i]*aggregateRegister[19];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[98+i] += aggregates_V15[0+i]*aggregateRegister[20];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[101+i] += aggregates_V15[0+i]*aggregateRegister[21];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[104+i] += aggregates_V15[0+i]*aggregateRegister[22];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[107+i] += aggregates_V15[0+i]*aggregateRegister[23];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[110+i] += aggregates_V15[0+i]*aggregateRegister[24];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[113+i] += aggregates_V15[0+i]*aggregateRegister[25];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[116+i] += aggregates_V15[0+i]*aggregateRegister[26];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[119+i] += aggregates_V15[0+i]*aggregateRegister[27];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[122+i] += aggregates_V15[0+i]*aggregateRegister[28];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[125+i] += aggregates_V15[0+i]*aggregateRegister[29];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[128+i] += aggregates_V15[0+i]*aggregateRegister[30];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[131+i] += aggregates_V15[0+i]*aggregateRegister[31];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[134+i] += aggregates_V15[0+i]*aggregateRegister[32];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[137+i] += aggregates_V15[0+i]*aggregateRegister[33];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[140+i] += aggregates_V15[0+i]*aggregateRegister[34];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[143+i] += aggregates_V15[0+i]*aggregateRegister[35];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[146+i] += aggregates_V15[0+i]*aggregateRegister[36];
            for (size_t i = 0; i < 3;++i)
               aggregateRegister[149+i] += aggregates_V15[0+i]*aggregateRegister[37];
            memset(addTuple, true, sizeof(bool) * 2);
            for (size_t i = 0; i < 114;++i)
               postRegister[0+i] += aggregateRegister[38+i];
            lowerptr_Transactions[1] = upperptr_Transactions[1];
            lowerptr_V15[1] = upperptr_V15[1];
            switch(order_store[rel[1]].second)
            {
            case Transactions_ID:
               lowerptr_Transactions[1] += 1;
               if(lowerptr_Transactions[1] > upperptr_Transactions[0])
                  atEnd[1] = true;
               else
               {
                  max_store = Transactions[lowerptr_Transactions[1]].store;
                  rel[1] = (rel[1]+ 1) % numOfRel[1];
               }
               break;
            case V15_ID:
               lowerptr_V15[1] += 1;
               if(lowerptr_V15[1] > upperptr_V15[0])
                  atEnd[1] = true;
               else
               {
                  max_store = V15[lowerptr_V15[1]].store;
                  rel[1] = (rel[1]+ 1) % numOfRel[1];
               }
               break;
            }
         }
         if (addTuple[0]) 
         {
            for (size_t i = 0; i < 114;++i)
               postRegister[114+i] += postRegister[0+i];
         }
         lowerptr_Transactions[0] = upperptr_Transactions[0];
         lowerptr_V15[0] = upperptr_V15[0];
         switch(order_date[rel[0]].second)
         {
         case Transactions_ID:
            lowerptr_Transactions[0] += 1;
            if(lowerptr_Transactions[0] > Transactions.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = Transactions[lowerptr_Transactions[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         case V15_ID:
            lowerptr_V15[0] += 1;
            if(lowerptr_V15[0] > V15.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = V15[lowerptr_V15[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V16.emplace_back();
      aggregates_V16 = V16.back().aggregates;
      for (size_t i = 0; i < 114;++i)
         aggregates_V16[0+i] += postRegister[114+i];
   }

}
