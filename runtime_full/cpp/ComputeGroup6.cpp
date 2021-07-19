#include "ComputeGroup6.h"
#include "DynamicFunctions.h"
namespace lmfao
{
   void computeGroup6()
   {
      int max_date;
      bool found[1] = {}, atEnd[1] = {}, addTuple[1] = {};
      size_t leap, low, mid, high;
      size_t lowerptr_Oil[1] = {}, upperptr_Oil[1] = {}; 
      upperptr_Oil[0] = Oil.size()-1;
      size_t lowerptr_V8[1] = {}, upperptr_V8[1] = {}; 
      upperptr_V8[0] = V8.size()-1;
      size_t ptr_Oil = 0;
      double *aggregates_V9 = nullptr, *aggregates_V8 = nullptr;
      int min_date;
      double aggregateRegister[152] = {};
      double localRegister[38] = {};
      double postRegister[114] = {};
      size_t rel[1] = {}, numOfRel[1] = {2};
      /*********** ORDERING RELATIONS *************/
      std::pair<int, int> order_date[2];
      if(Oil[lowerptr_Oil[0]].date < V8[lowerptr_V8[0]].date)
      {
         order_date[0] = std::make_pair(Oil[lowerptr_Oil[0]].date, Oil_ID);
         order_date[1] = std::make_pair(V8[lowerptr_V8[0]].date, V8_ID);
      }
      else
      {
         order_date[0] = std::make_pair(V8[lowerptr_V8[0]].date, V8_ID);
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
            case V8_ID:
               if(V8[lowerptr_V8[0]].date == max_date)
                  found[0] = true;
               else if(max_date > V8[V8.size()-1].date)
                  atEnd[0] = true;
               else
               {
                  min_date = V8[lowerptr_V8[0]].date;
                  size_t leap = 1;
                  while (min_date < max_date && lowerptr_V8[0] <= V8.size()-1)
                  {
                     lowerptr_V8[0] += leap;
                     leap *= 2;
                     if(lowerptr_V8[0] < V8.size()-1)
                     {
                        min_date = V8[lowerptr_V8[0]].date;
                     }
                     else
                     {
                        lowerptr_V8[0] = V8.size()-1;
                        break;
                     }
                  }
                  /* Backtrack with binary search */
                  if (leap > 2 && max_date <= V8[lowerptr_V8[0]].date)
                  {
                     leap /= 2;
                     size_t high = lowerptr_V8[0], low = lowerptr_V8[0] - leap, mid = 0;
                     while (high > low && high != low)
                     {
                        mid = (high + low) / 2;
                        if (max_date > V8[mid - 1].date && max_date <= V8[mid].date)
                        {
                           lowerptr_V8[0] = mid;
                           break;
                        }
                        else if (max_date <= V8[mid].date)
                           high = mid - 1;
                        else 
                           low = mid + 1;
                     }
                     mid = (high + low) / 2;
                     if (V8[mid-1].date >= max_date)
                        mid -= 1;
                     lowerptr_V8[0] = mid;
                  }
                  max_date = V8[lowerptr_V8[0]].date;
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
         upperptr_V8[0] = lowerptr_V8[0];
         while(upperptr_V8[0]<V8.size()-1 && V8[upperptr_V8[0]+1].date == max_date)
         {
            ++upperptr_V8[0];
         }
         addTuple[0] = false;
         memset(&aggregateRegister[0], 0, sizeof(double) * 152);
         Oil_tuple &OilTuple = Oil[lowerptr_Oil[0]];
         V8_tuple &V8Tuple = V8[lowerptr_V8[0]];
         double *aggregates_V8 = V8Tuple.aggregates;
         double count = upperptr_Oil[0] - lowerptr_Oil[0] + 1;
         memset(&aggregateRegister[38], 0, sizeof(double) * 114);
         memset(&aggregateRegister[0], 0, sizeof(double) * 38);
         ptr_Oil = lowerptr_Oil[0];
         while(ptr_Oil <= upperptr_Oil[0])
         {
            Oil_tuple &OilTuple = Oil[ptr_Oil];
            localRegister[0] = (OilTuple.oilprize <= 35.360000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[1] = (OilTuple.oilprize > 35.360000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[2] = (OilTuple.oilprize <= 40.050000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[3] = (OilTuple.oilprize > 40.050000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[4] = (OilTuple.oilprize <= 43.040000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[5] = (OilTuple.oilprize > 43.040000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[6] = (OilTuple.oilprize <= 44.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[7] = (OilTuple.oilprize > 44.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[8] = (OilTuple.oilprize <= 45.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[9] = (OilTuple.oilprize > 45.470000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[10] = (OilTuple.oilprize <= 46.120000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[11] = (OilTuple.oilprize > 46.120000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[12] = (OilTuple.oilprize <= 47.170000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[13] = (OilTuple.oilprize > 47.170000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[14] = (OilTuple.oilprize <= 48.130000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[15] = (OilTuple.oilprize > 48.130000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[16] = (OilTuple.oilprize <= 49.070000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[17] = (OilTuple.oilprize > 49.070000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[18] = (OilTuple.oilprize <= 49.850000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[19] = (OilTuple.oilprize > 49.850000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[20] = (OilTuple.oilprize <= 51.610000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[21] = (OilTuple.oilprize > 51.610000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[22] = (OilTuple.oilprize <= 53.010000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[23] = (OilTuple.oilprize > 53.010000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[24] = (OilTuple.oilprize <= 54.590000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[25] = (OilTuple.oilprize > 54.590000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[26] = (OilTuple.oilprize <= 60.250000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[27] = (OilTuple.oilprize > 60.250000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[28] = (OilTuple.oilprize <= 90.880000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[29] = (OilTuple.oilprize > 90.880000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[30] = (OilTuple.oilprize <= 93.840000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[31] = (OilTuple.oilprize > 93.840000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[32] = (OilTuple.oilprize <= 97.030000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[33] = (OilTuple.oilprize > 97.030000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[34] = (OilTuple.oilprize <= 100.520000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[35] = (OilTuple.oilprize > 100.520000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[36] = (OilTuple.oilprize <= 104.060000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            localRegister[37] = (OilTuple.oilprize > 104.060000)*f_Oil(OilTuple.date,OilTuple.oilprize);
            for (size_t i = 0; i < 38;++i)
               aggregateRegister[0+i] += localRegister[0+i];
            ++ptr_Oil;
         }
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[38+i] += aggregates_V8[0+i]*aggregateRegister[0];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[41+i] += aggregates_V8[0+i]*aggregateRegister[1];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[44+i] += aggregates_V8[0+i]*aggregateRegister[2];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[47+i] += aggregates_V8[0+i]*aggregateRegister[3];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[50+i] += aggregates_V8[0+i]*aggregateRegister[4];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[53+i] += aggregates_V8[0+i]*aggregateRegister[5];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[56+i] += aggregates_V8[0+i]*aggregateRegister[6];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[59+i] += aggregates_V8[0+i]*aggregateRegister[7];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[62+i] += aggregates_V8[0+i]*aggregateRegister[8];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[65+i] += aggregates_V8[0+i]*aggregateRegister[9];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[68+i] += aggregates_V8[0+i]*aggregateRegister[10];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[71+i] += aggregates_V8[0+i]*aggregateRegister[11];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[74+i] += aggregates_V8[0+i]*aggregateRegister[12];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[77+i] += aggregates_V8[0+i]*aggregateRegister[13];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[80+i] += aggregates_V8[0+i]*aggregateRegister[14];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[83+i] += aggregates_V8[0+i]*aggregateRegister[15];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[86+i] += aggregates_V8[0+i]*aggregateRegister[16];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[89+i] += aggregates_V8[0+i]*aggregateRegister[17];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[92+i] += aggregates_V8[0+i]*aggregateRegister[18];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[95+i] += aggregates_V8[0+i]*aggregateRegister[19];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[98+i] += aggregates_V8[0+i]*aggregateRegister[20];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[101+i] += aggregates_V8[0+i]*aggregateRegister[21];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[104+i] += aggregates_V8[0+i]*aggregateRegister[22];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[107+i] += aggregates_V8[0+i]*aggregateRegister[23];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[110+i] += aggregates_V8[0+i]*aggregateRegister[24];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[113+i] += aggregates_V8[0+i]*aggregateRegister[25];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[116+i] += aggregates_V8[0+i]*aggregateRegister[26];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[119+i] += aggregates_V8[0+i]*aggregateRegister[27];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[122+i] += aggregates_V8[0+i]*aggregateRegister[28];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[125+i] += aggregates_V8[0+i]*aggregateRegister[29];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[128+i] += aggregates_V8[0+i]*aggregateRegister[30];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[131+i] += aggregates_V8[0+i]*aggregateRegister[31];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[134+i] += aggregates_V8[0+i]*aggregateRegister[32];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[137+i] += aggregates_V8[0+i]*aggregateRegister[33];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[140+i] += aggregates_V8[0+i]*aggregateRegister[34];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[143+i] += aggregates_V8[0+i]*aggregateRegister[35];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[146+i] += aggregates_V8[0+i]*aggregateRegister[36];
         for (size_t i = 0; i < 3;++i)
            aggregateRegister[149+i] += aggregates_V8[0+i]*aggregateRegister[37];
         memset(addTuple, true, sizeof(bool) * 1);
         for (size_t i = 0; i < 114;++i)
            postRegister[0+i] += aggregateRegister[38+i];
         lowerptr_Oil[0] = upperptr_Oil[0];
         lowerptr_V8[0] = upperptr_V8[0];
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
         case V8_ID:
            lowerptr_V8[0] += 1;
            if(lowerptr_V8[0] > V8.size()-1)
               atEnd[0] = true;
            else
            {
               max_date = V8[lowerptr_V8[0]].date;
               rel[0] = (rel[0]+ 1) % numOfRel[0];
            }
            break;
         }
      }
      V9.emplace_back();
      aggregates_V9 = V9.back().aggregates;
      for (size_t i = 0; i < 114;++i)
         aggregates_V9[0+i] += postRegister[0+i];
   }

}
