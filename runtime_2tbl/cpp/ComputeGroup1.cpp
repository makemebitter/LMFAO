#include "ComputeGroup1.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup1()
   {
      int max_date;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Oil[1] = {}, upperptr_Oil[1] = {}; 
      upperptr_Oil[0] = Oil.size()-1;
      size_t lowerptr_V4[1] = {}, upperptr_V4[1] = {}; 
      upperptr_V4[0] = V4.size()-1;
      size_t ptr_Oil = 0;
      double *aggregates_V0 = nullptr, *aggregates_V5 = nullptr, *aggregates_V4 = nullptr;
      int min_date;
      double aggregateRegister[154] = {};
      double localRegister[39] = {};
      double postRegister[114] = {};
      size_t rel[1] = {}, numOfRel[1] = {2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_date[2];
      if(Oil[lowerptr_Oil[0]].date < V4[lowerptr_V4[0]].date)
      {
         order_date[0] = std::make_pair(Oil[lowerptr_Oil[0]].date, Oil_ID);
         order_date[1] = std::make_pair(V4[lowerptr_V4[0]].date, V4_ID);
      }
      else
      {
         order_date[0] = std::make_pair(V4[lowerptr_V4[0]].date, V4_ID);
         order_date[1] = std::make_pair(Oil[lowerptr_Oil[0]].date, Oil_ID);
      }
      min_date = order_date[0].first;
      max_date = order_date[1].first;
      /*********** ORDERING RELATIONS *************/
      rel[0] = 0;
      atEnd[0] = false;
      memset(&postRegister[0], 0, sizeof(double) * 114);
      while(!atEnd[0])
      {
         found[0] = false;
         // Seek Value
         do
         {
            switch(order_date[rel[0]].second)
            {
            case Oil_ID:
               if(Oil[lowerptr_Oil[0]].date == max_date)
                  found[0] = true;
               else if(max_date > Oil[Oil.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = Oil[lowerptr_Oil[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_Oil[0] <= Oil.size()-1)
                  {
                     lowerptr_Oil[0] += leap;
                     leap *= 2;
                     if(lowerptr_Oil[0] < Oil.size()-1)
                     {
                        min_date = Oil[lowerptr_Oil[0]].date;
                     }
                     else
                     {
                        lowerptr_Oil[0] = Oil.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= Oil[lowerptr_Oil[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_Oil[0], low = lowerptr_Oil[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > Oil[mid - 1].date && max_date <= Oil[mid].date)
                        {
                           lowerptr_Oil[0] = mid;
                           break;
                        }
                        else if (max_date <= Oil[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (Oil[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_Oil[0] = mid;
                  }
                  max_date = Oil[lowerptr_Oil[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            case V4_ID:
               if(V4[lowerptr_V4[0]].date == max_date)
                  found[0] = true;
               else if(max_date > V4[V4.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = V4[lowerptr_V4[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_V4[0] <= V4.size()-1)
                  {
                     lowerptr_V4[0] += leap;
                     leap *= 2;
                     if(lowerptr_V4[0] < V4.size()-1)
                     {
                        min_date = V4[lowerptr_V4[0]].date;
                     }
                     else
                     {
                        lowerptr_V4[0] = V4.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= V4[lowerptr_V4[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V4[0], low = lowerptr_V4[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > V4[mid - 1].date && max_date <= V4[mid].date)
                        {
                           lowerptr_V4[0] = mid;
                           break;
                        }
                        else if (max_date <= V4[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V4[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_V4[0] = mid;
                  }
                  max_date = V4[lowerptr_V4[0]].date;
                  rel[0] = (rel[0]+1) % numOfRel[0];
               }
               break;
            }
         } while (!found[0] && !atEnd[0]);
         // End Seek Value
         // If atEnd break loop
         if(atEnd[0])
            break;
         upperptr_Oil[0] = lowerptr_Oil[0];
         while(upperptr_Oil[0]<Oil.size()-1 && Oil[upperptr_Oil[0]+1].date == max_date)
         {
            ++upperptr_Oil[0];
         }
         upperptr_V4[0] = lowerptr_V4[0];
         while(upperptr_V4[0]<V4.size()-1 && V4[upperptr_V4[0]+1].date == max_date)
         {
            ++upperptr_V4[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 154);
         Oil_tuple &OilTuple = Oil[lowerptr_Oil[0]];
         V4_tuple &V4Tuple = V4[lowerptr_V4[0]];
         double *aggregates_V4 = V4Tuple.aggregates;
         double count = upperptr_Oil[0] - lowerptr_Oil[0] + 1;
         memset(&aggregateRegister[39], 0, sizeof(double) * 115);
         memset(&aggregateRegister[0], 0, sizeof(double) * 39);
         ptr_Oil = lowerptr_Oil[0];
         while(ptr_Oil <= upperptr_Oil[0])
         {
            Oil_tuple &OilTuple = Oil[ptr_Oil];
            localRegister[0] = f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[1] = (OilTuple.oilprize <= 35.360000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[2] = (OilTuple.oilprize > 35.360000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[3] = (OilTuple.oilprize <= 40.050000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[4] = (OilTuple.oilprize > 40.050000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[5] = (OilTuple.oilprize <= 43.040000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[6] = (OilTuple.oilprize > 43.040000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[7] = (OilTuple.oilprize <= 44.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[8] = (OilTuple.oilprize > 44.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[9] = (OilTuple.oilprize <= 45.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[10] = (OilTuple.oilprize > 45.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[11] = (OilTuple.oilprize <= 46.120000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[12] = (OilTuple.oilprize > 46.120000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[13] = (OilTuple.oilprize <= 47.170000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[14] = (OilTuple.oilprize > 47.170000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[15] = (OilTuple.oilprize <= 48.130000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[16] = (OilTuple.oilprize > 48.130000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[17] = (OilTuple.oilprize <= 49.070000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[18] = (OilTuple.oilprize > 49.070000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[19] = (OilTuple.oilprize <= 49.850000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[20] = (OilTuple.oilprize > 49.850000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[21] = (OilTuple.oilprize <= 51.610000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[22] = (OilTuple.oilprize > 51.610000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[23] = (OilTuple.oilprize <= 53.010000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[24] = (OilTuple.oilprize > 53.010000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[25] = (OilTuple.oilprize <= 54.590000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[26] = (OilTuple.oilprize > 54.590000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[27] = (OilTuple.oilprize <= 60.250000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[28] = (OilTuple.oilprize > 60.250000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[29] = (OilTuple.oilprize <= 90.880000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[30] = (OilTuple.oilprize > 90.880000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[31] = (OilTuple.oilprize <= 93.840000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[32] = (OilTuple.oilprize > 93.840000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[33] = (OilTuple.oilprize <= 97.030000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[34] = (OilTuple.oilprize > 97.030000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[35] = (OilTuple.oilprize <= 100.520000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[36] = (OilTuple.oilprize > 100.520000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[37] = (OilTuple.oilprize <= 104.060000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[38] = (OilTuple.oilprize > 104.060000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            for (size_t i = 0; i < 39;++i)
               aggregateRegister[0+i] += localRegister[0+i];
            ++ptr_Oil;
         }
         aggregateRegister[39] += aggregateRegister[0];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[40+i] += aggregates_V4[0+i]*aggregateRegister[1];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[43+i] += aggregates_V4[0+i]*aggregateRegister[2];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[46+i] += aggregates_V4[0+i]*aggregateRegister[3];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[49+i] += aggregates_V4[0+i]*aggregateRegister[4];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[52+i] += aggregates_V4[0+i]*aggregateRegister[5];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[55+i] += aggregates_V4[0+i]*aggregateRegister[6];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[58+i] += aggregates_V4[0+i]*aggregateRegister[7];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[61+i] += aggregates_V4[0+i]*aggregateRegister[8];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[64+i] += aggregates_V4[0+i]*aggregateRegister[9];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[67+i] += aggregates_V4[0+i]*aggregateRegister[10];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[70+i] += aggregates_V4[0+i]*aggregateRegister[11];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[73+i] += aggregates_V4[0+i]*aggregateRegister[12];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[76+i] += aggregates_V4[0+i]*aggregateRegister[13];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[79+i] += aggregates_V4[0+i]*aggregateRegister[14];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[82+i] += aggregates_V4[0+i]*aggregateRegister[15];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[85+i] += aggregates_V4[0+i]*aggregateRegister[16];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[88+i] += aggregates_V4[0+i]*aggregateRegister[17];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[91+i] += aggregates_V4[0+i]*aggregateRegister[18];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[94+i] += aggregates_V4[0+i]*aggregateRegister[19];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[97+i] += aggregates_V4[0+i]*aggregateRegister[20];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[100+i] += aggregates_V4[0+i]*aggregateRegister[21];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[103+i] += aggregates_V4[0+i]*aggregateRegister[22];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[106+i] += aggregates_V4[0+i]*aggregateRegister[23];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[109+i] += aggregates_V4[0+i]*aggregateRegister[24];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[112+i] += aggregates_V4[0+i]*aggregateRegister[25];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[115+i] += aggregates_V4[0+i]*aggregateRegister[26];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[118+i] += aggregates_V4[0+i]*aggregateRegister[27];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[121+i] += aggregates_V4[0+i]*aggregateRegister[28];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[124+i] += aggregates_V4[0+i]*aggregateRegister[29];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[127+i] += aggregates_V4[0+i]*aggregateRegister[30];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[130+i] += aggregates_V4[0+i]*aggregateRegister[31];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[133+i] += aggregates_V4[0+i]*aggregateRegister[32];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[136+i] += aggregates_V4[0+i]*aggregateRegister[33];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[139+i] += aggregates_V4[0+i]*aggregateRegister[34];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[142+i] += aggregates_V4[0+i]*aggregateRegister[35];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[145+i] += aggregates_V4[0+i]*aggregateRegister[36];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[148+i] += aggregates_V4[0+i]*aggregateRegister[37];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[151+i] += aggregates_V4[0+i]*aggregateRegister[38];
         memset(addTuple, true, sizeof(bool) * 1);
         for (size_t i = 0; i < 114;++i)
            postRegister[0+i] += aggregateRegister[40+i];
         V0.emplace_back(OilTuple.date);
         aggregates_V0 = V0.back().aggregates;
         aggregates_V0[0] += aggregateRegister[39];
         lowerptr_Oil[0] = upperptr_Oil[0];
         lowerptr_V4[0] = upperptr_V4[0];
         switch(order_date[rel[0]].second)
         {
         case Oil_ID:
            lowerptr_Oil[0] += 1;
            if(lowerptr_Oil[0] > Oil.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = Oil[lowerptr_Oil[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         case V4_ID:
            lowerptr_V4[0] += 1;
            if(lowerptr_V4[0] > V4.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = V4[lowerptr_V4[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V5.emplace_back();
      aggregates_V5 = V5.back().aggregates;
      for (size_t i = 0; i < 114;++i)
         aggregates_V5[0+i] += postRegister[0+i];
   }

}
