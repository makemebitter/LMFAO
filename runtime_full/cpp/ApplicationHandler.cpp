#include "ApplicationHandler.h"
namespace lmfao
{
   struct Threshold
   {
      size_t varID;
      double threshold;
      bool categorical;
      double* aggregates;
      double* compAggregates;
      Threshold() : varID(0), threshold(0), categorical(false), aggregates(nullptr), compAggregates(nullptr) {}
      void set(size_t var, double t, bool c, double* agg, double *cagg)
      {
         varID = var;
         threshold = t;
         categorical = c;
         aggregates = agg;
         compAggregates = cagg;
      }
   };

   size_t numberOfThresholds;
   double* variance = nullptr;
   Threshold* thresholdMap = nullptr;

   void initCostArray()
   {
      numberOfThresholds = V6.size() + V7.size() + V11.size() + V12.size() + V13.size() + V14.size() + V18.size() + V19.size() + V20.size() + V21.size() + V23.size() + V24.size() + V25.size() + 38;
      variance = new double[numberOfThresholds];
      thresholdMap = new Threshold[numberOfThresholds];
      thresholdMap[0].set(5,35.360000,0,&V9[0].aggregates[0],&V9[0].aggregates[3]);
      thresholdMap[1].set(5,40.050000,0,&V9[0].aggregates[6],&V9[0].aggregates[9]);
      thresholdMap[2].set(5,43.040000,0,&V9[0].aggregates[12],&V9[0].aggregates[15]);
      thresholdMap[3].set(5,44.470000,0,&V9[0].aggregates[18],&V9[0].aggregates[21]);
      thresholdMap[4].set(5,45.470000,0,&V9[0].aggregates[24],&V9[0].aggregates[27]);
      thresholdMap[5].set(5,46.120000,0,&V9[0].aggregates[30],&V9[0].aggregates[33]);
      thresholdMap[6].set(5,47.170000,0,&V9[0].aggregates[36],&V9[0].aggregates[39]);
      thresholdMap[7].set(5,48.130000,0,&V9[0].aggregates[42],&V9[0].aggregates[45]);
      thresholdMap[8].set(5,49.070000,0,&V9[0].aggregates[48],&V9[0].aggregates[51]);
      thresholdMap[9].set(5,49.850000,0,&V9[0].aggregates[54],&V9[0].aggregates[57]);
      thresholdMap[10].set(5,51.610000,0,&V9[0].aggregates[60],&V9[0].aggregates[63]);
      thresholdMap[11].set(5,53.010000,0,&V9[0].aggregates[66],&V9[0].aggregates[69]);
      thresholdMap[12].set(5,54.590000,0,&V9[0].aggregates[72],&V9[0].aggregates[75]);
      thresholdMap[13].set(5,60.250000,0,&V9[0].aggregates[78],&V9[0].aggregates[81]);
      thresholdMap[14].set(5,90.880000,0,&V9[0].aggregates[84],&V9[0].aggregates[87]);
      thresholdMap[15].set(5,93.840000,0,&V9[0].aggregates[90],&V9[0].aggregates[93]);
      thresholdMap[16].set(5,97.030000,0,&V9[0].aggregates[96],&V9[0].aggregates[99]);
      thresholdMap[17].set(5,100.520000,0,&V9[0].aggregates[102],&V9[0].aggregates[105]);
      thresholdMap[18].set(5,104.060000,0,&V9[0].aggregates[108],&V9[0].aggregates[111]);
      thresholdMap[19].set(10,711.000000,0,&V16[0].aggregates[0],&V16[0].aggregates[3]);
      thresholdMap[20].set(10,856.000000,0,&V16[0].aggregates[6],&V16[0].aggregates[9]);
      thresholdMap[21].set(10,973.000000,0,&V16[0].aggregates[12],&V16[0].aggregates[15]);
      thresholdMap[22].set(10,1070.000000,0,&V16[0].aggregates[18],&V16[0].aggregates[21]);
      thresholdMap[23].set(10,1157.000000,0,&V16[0].aggregates[24],&V16[0].aggregates[27]);
      thresholdMap[24].set(10,1235.000000,0,&V16[0].aggregates[30],&V16[0].aggregates[33]);
      thresholdMap[25].set(10,1304.000000,0,&V16[0].aggregates[36],&V16[0].aggregates[39]);
      thresholdMap[26].set(10,1373.000000,0,&V16[0].aggregates[42],&V16[0].aggregates[45]);
      thresholdMap[27].set(10,1453.000000,0,&V16[0].aggregates[48],&V16[0].aggregates[51]);
      thresholdMap[28].set(10,1554.000000,0,&V16[0].aggregates[54],&V16[0].aggregates[57]);
      thresholdMap[29].set(10,1681.000000,0,&V16[0].aggregates[60],&V16[0].aggregates[63]);
      thresholdMap[30].set(10,1804.000000,0,&V16[0].aggregates[66],&V16[0].aggregates[69]);
      thresholdMap[31].set(10,1945.000000,0,&V16[0].aggregates[72],&V16[0].aggregates[75]);
      thresholdMap[32].set(10,2151.000000,0,&V16[0].aggregates[78],&V16[0].aggregates[81]);
      thresholdMap[33].set(10,2390.000000,0,&V16[0].aggregates[84],&V16[0].aggregates[87]);
      thresholdMap[34].set(10,2679.000000,0,&V16[0].aggregates[90],&V16[0].aggregates[93]);
      thresholdMap[35].set(10,2997.000000,0,&V16[0].aggregates[96],&V16[0].aggregates[99]);
      thresholdMap[36].set(10,3408.000000,0,&V16[0].aggregates[102],&V16[0].aggregates[105]);
      thresholdMap[37].set(10,4070.000000,0,&V16[0].aggregates[108],&V16[0].aggregates[111]);
      size_t categIdx = 38;
      for (V6_tuple& tuple : V6)
         thresholdMap[categIdx++].set(1,tuple.store,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V7_tuple& tuple : V7)
         thresholdMap[categIdx++].set(4,tuple.onpromotion,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V11_tuple& tuple : V11)
         thresholdMap[categIdx++].set(6,tuple.holiday_type,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V12_tuple& tuple : V12)
         thresholdMap[categIdx++].set(7,tuple.locale,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V13_tuple& tuple : V13)
         thresholdMap[categIdx++].set(8,tuple.locale_id,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V14_tuple& tuple : V14)
         thresholdMap[categIdx++].set(9,tuple.transferred,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V18_tuple& tuple : V18)
         thresholdMap[categIdx++].set(11,tuple.city,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V19_tuple& tuple : V19)
         thresholdMap[categIdx++].set(12,tuple.state,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V20_tuple& tuple : V20)
         thresholdMap[categIdx++].set(13,tuple.store_type,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V21_tuple& tuple : V21)
         thresholdMap[categIdx++].set(14,tuple.cluster,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V23_tuple& tuple : V23)
         thresholdMap[categIdx++].set(15,tuple.family,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V24_tuple& tuple : V24)
         thresholdMap[categIdx++].set(16,tuple.itemclass,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
      for (V25_tuple& tuple : V25)
         thresholdMap[categIdx++].set(17,tuple.perishable,1,&tuple.aggregates[0],&V5[0].aggregates[0]);
   }

   void computeCost()
   {
      V9_tuple& V9tuple = V9[0];
      variance[0] = ((V9tuple.aggregates[0] > 0  && V9tuple.aggregates[3] > 0) ? V9tuple.aggregates[2] - (V9tuple.aggregates[1] * V9tuple.aggregates[1]) / V9tuple.aggregates[0] + V9tuple.aggregates[5] - (V9tuple.aggregates[4] * V9tuple.aggregates[4]) / V9tuple.aggregates[3] : 1.79769e+308);
      variance[1] = ((V9tuple.aggregates[6] > 0  && V9tuple.aggregates[9] > 0) ? V9tuple.aggregates[8] - (V9tuple.aggregates[7] * V9tuple.aggregates[7]) / V9tuple.aggregates[6] + V9tuple.aggregates[11] - (V9tuple.aggregates[10] * V9tuple.aggregates[10]) / V9tuple.aggregates[9] : 1.79769e+308);
      variance[2] = ((V9tuple.aggregates[12] > 0  && V9tuple.aggregates[15] > 0) ? V9tuple.aggregates[14] - (V9tuple.aggregates[13] * V9tuple.aggregates[13]) / V9tuple.aggregates[12] + V9tuple.aggregates[17] - (V9tuple.aggregates[16] * V9tuple.aggregates[16]) / V9tuple.aggregates[15] : 1.79769e+308);
      variance[3] = ((V9tuple.aggregates[18] > 0  && V9tuple.aggregates[21] > 0) ? V9tuple.aggregates[20] - (V9tuple.aggregates[19] * V9tuple.aggregates[19]) / V9tuple.aggregates[18] + V9tuple.aggregates[23] - (V9tuple.aggregates[22] * V9tuple.aggregates[22]) / V9tuple.aggregates[21] : 1.79769e+308);
      variance[4] = ((V9tuple.aggregates[24] > 0  && V9tuple.aggregates[27] > 0) ? V9tuple.aggregates[26] - (V9tuple.aggregates[25] * V9tuple.aggregates[25]) / V9tuple.aggregates[24] + V9tuple.aggregates[29] - (V9tuple.aggregates[28] * V9tuple.aggregates[28]) / V9tuple.aggregates[27] : 1.79769e+308);
      variance[5] = ((V9tuple.aggregates[30] > 0  && V9tuple.aggregates[33] > 0) ? V9tuple.aggregates[32] - (V9tuple.aggregates[31] * V9tuple.aggregates[31]) / V9tuple.aggregates[30] + V9tuple.aggregates[35] - (V9tuple.aggregates[34] * V9tuple.aggregates[34]) / V9tuple.aggregates[33] : 1.79769e+308);
      variance[6] = ((V9tuple.aggregates[36] > 0  && V9tuple.aggregates[39] > 0) ? V9tuple.aggregates[38] - (V9tuple.aggregates[37] * V9tuple.aggregates[37]) / V9tuple.aggregates[36] + V9tuple.aggregates[41] - (V9tuple.aggregates[40] * V9tuple.aggregates[40]) / V9tuple.aggregates[39] : 1.79769e+308);
      variance[7] = ((V9tuple.aggregates[42] > 0  && V9tuple.aggregates[45] > 0) ? V9tuple.aggregates[44] - (V9tuple.aggregates[43] * V9tuple.aggregates[43]) / V9tuple.aggregates[42] + V9tuple.aggregates[47] - (V9tuple.aggregates[46] * V9tuple.aggregates[46]) / V9tuple.aggregates[45] : 1.79769e+308);
      variance[8] = ((V9tuple.aggregates[48] > 0  && V9tuple.aggregates[51] > 0) ? V9tuple.aggregates[50] - (V9tuple.aggregates[49] * V9tuple.aggregates[49]) / V9tuple.aggregates[48] + V9tuple.aggregates[53] - (V9tuple.aggregates[52] * V9tuple.aggregates[52]) / V9tuple.aggregates[51] : 1.79769e+308);
      variance[9] = ((V9tuple.aggregates[54] > 0  && V9tuple.aggregates[57] > 0) ? V9tuple.aggregates[56] - (V9tuple.aggregates[55] * V9tuple.aggregates[55]) / V9tuple.aggregates[54] + V9tuple.aggregates[59] - (V9tuple.aggregates[58] * V9tuple.aggregates[58]) / V9tuple.aggregates[57] : 1.79769e+308);
      variance[10] = ((V9tuple.aggregates[60] > 0  && V9tuple.aggregates[63] > 0) ? V9tuple.aggregates[62] - (V9tuple.aggregates[61] * V9tuple.aggregates[61]) / V9tuple.aggregates[60] + V9tuple.aggregates[65] - (V9tuple.aggregates[64] * V9tuple.aggregates[64]) / V9tuple.aggregates[63] : 1.79769e+308);
      variance[11] = ((V9tuple.aggregates[66] > 0  && V9tuple.aggregates[69] > 0) ? V9tuple.aggregates[68] - (V9tuple.aggregates[67] * V9tuple.aggregates[67]) / V9tuple.aggregates[66] + V9tuple.aggregates[71] - (V9tuple.aggregates[70] * V9tuple.aggregates[70]) / V9tuple.aggregates[69] : 1.79769e+308);
      variance[12] = ((V9tuple.aggregates[72] > 0  && V9tuple.aggregates[75] > 0) ? V9tuple.aggregates[74] - (V9tuple.aggregates[73] * V9tuple.aggregates[73]) / V9tuple.aggregates[72] + V9tuple.aggregates[77] - (V9tuple.aggregates[76] * V9tuple.aggregates[76]) / V9tuple.aggregates[75] : 1.79769e+308);
      variance[13] = ((V9tuple.aggregates[78] > 0  && V9tuple.aggregates[81] > 0) ? V9tuple.aggregates[80] - (V9tuple.aggregates[79] * V9tuple.aggregates[79]) / V9tuple.aggregates[78] + V9tuple.aggregates[83] - (V9tuple.aggregates[82] * V9tuple.aggregates[82]) / V9tuple.aggregates[81] : 1.79769e+308);
      variance[14] = ((V9tuple.aggregates[84] > 0  && V9tuple.aggregates[87] > 0) ? V9tuple.aggregates[86] - (V9tuple.aggregates[85] * V9tuple.aggregates[85]) / V9tuple.aggregates[84] + V9tuple.aggregates[89] - (V9tuple.aggregates[88] * V9tuple.aggregates[88]) / V9tuple.aggregates[87] : 1.79769e+308);
      variance[15] = ((V9tuple.aggregates[90] > 0  && V9tuple.aggregates[93] > 0) ? V9tuple.aggregates[92] - (V9tuple.aggregates[91] * V9tuple.aggregates[91]) / V9tuple.aggregates[90] + V9tuple.aggregates[95] - (V9tuple.aggregates[94] * V9tuple.aggregates[94]) / V9tuple.aggregates[93] : 1.79769e+308);
      variance[16] = ((V9tuple.aggregates[96] > 0  && V9tuple.aggregates[99] > 0) ? V9tuple.aggregates[98] - (V9tuple.aggregates[97] * V9tuple.aggregates[97]) / V9tuple.aggregates[96] + V9tuple.aggregates[101] - (V9tuple.aggregates[100] * V9tuple.aggregates[100]) / V9tuple.aggregates[99] : 1.79769e+308);
      variance[17] = ((V9tuple.aggregates[102] > 0  && V9tuple.aggregates[105] > 0) ? V9tuple.aggregates[104] - (V9tuple.aggregates[103] * V9tuple.aggregates[103]) / V9tuple.aggregates[102] + V9tuple.aggregates[107] - (V9tuple.aggregates[106] * V9tuple.aggregates[106]) / V9tuple.aggregates[105] : 1.79769e+308);
      variance[18] = ((V9tuple.aggregates[108] > 0  && V9tuple.aggregates[111] > 0) ? V9tuple.aggregates[110] - (V9tuple.aggregates[109] * V9tuple.aggregates[109]) / V9tuple.aggregates[108] + V9tuple.aggregates[113] - (V9tuple.aggregates[112] * V9tuple.aggregates[112]) / V9tuple.aggregates[111] : 1.79769e+308);
      V16_tuple& V16tuple = V16[0];
      variance[19] = ((V16tuple.aggregates[0] > 0  && V16tuple.aggregates[3] > 0) ? V16tuple.aggregates[2] - (V16tuple.aggregates[1] * V16tuple.aggregates[1]) / V16tuple.aggregates[0] + V16tuple.aggregates[5] - (V16tuple.aggregates[4] * V16tuple.aggregates[4]) / V16tuple.aggregates[3] : 1.79769e+308);
      variance[20] = ((V16tuple.aggregates[6] > 0  && V16tuple.aggregates[9] > 0) ? V16tuple.aggregates[8] - (V16tuple.aggregates[7] * V16tuple.aggregates[7]) / V16tuple.aggregates[6] + V16tuple.aggregates[11] - (V16tuple.aggregates[10] * V16tuple.aggregates[10]) / V16tuple.aggregates[9] : 1.79769e+308);
      variance[21] = ((V16tuple.aggregates[12] > 0  && V16tuple.aggregates[15] > 0) ? V16tuple.aggregates[14] - (V16tuple.aggregates[13] * V16tuple.aggregates[13]) / V16tuple.aggregates[12] + V16tuple.aggregates[17] - (V16tuple.aggregates[16] * V16tuple.aggregates[16]) / V16tuple.aggregates[15] : 1.79769e+308);
      variance[22] = ((V16tuple.aggregates[18] > 0  && V16tuple.aggregates[21] > 0) ? V16tuple.aggregates[20] - (V16tuple.aggregates[19] * V16tuple.aggregates[19]) / V16tuple.aggregates[18] + V16tuple.aggregates[23] - (V16tuple.aggregates[22] * V16tuple.aggregates[22]) / V16tuple.aggregates[21] : 1.79769e+308);
      variance[23] = ((V16tuple.aggregates[24] > 0  && V16tuple.aggregates[27] > 0) ? V16tuple.aggregates[26] - (V16tuple.aggregates[25] * V16tuple.aggregates[25]) / V16tuple.aggregates[24] + V16tuple.aggregates[29] - (V16tuple.aggregates[28] * V16tuple.aggregates[28]) / V16tuple.aggregates[27] : 1.79769e+308);
      variance[24] = ((V16tuple.aggregates[30] > 0  && V16tuple.aggregates[33] > 0) ? V16tuple.aggregates[32] - (V16tuple.aggregates[31] * V16tuple.aggregates[31]) / V16tuple.aggregates[30] + V16tuple.aggregates[35] - (V16tuple.aggregates[34] * V16tuple.aggregates[34]) / V16tuple.aggregates[33] : 1.79769e+308);
      variance[25] = ((V16tuple.aggregates[36] > 0  && V16tuple.aggregates[39] > 0) ? V16tuple.aggregates[38] - (V16tuple.aggregates[37] * V16tuple.aggregates[37]) / V16tuple.aggregates[36] + V16tuple.aggregates[41] - (V16tuple.aggregates[40] * V16tuple.aggregates[40]) / V16tuple.aggregates[39] : 1.79769e+308);
      variance[26] = ((V16tuple.aggregates[42] > 0  && V16tuple.aggregates[45] > 0) ? V16tuple.aggregates[44] - (V16tuple.aggregates[43] * V16tuple.aggregates[43]) / V16tuple.aggregates[42] + V16tuple.aggregates[47] - (V16tuple.aggregates[46] * V16tuple.aggregates[46]) / V16tuple.aggregates[45] : 1.79769e+308);
      variance[27] = ((V16tuple.aggregates[48] > 0  && V16tuple.aggregates[51] > 0) ? V16tuple.aggregates[50] - (V16tuple.aggregates[49] * V16tuple.aggregates[49]) / V16tuple.aggregates[48] + V16tuple.aggregates[53] - (V16tuple.aggregates[52] * V16tuple.aggregates[52]) / V16tuple.aggregates[51] : 1.79769e+308);
      variance[28] = ((V16tuple.aggregates[54] > 0  && V16tuple.aggregates[57] > 0) ? V16tuple.aggregates[56] - (V16tuple.aggregates[55] * V16tuple.aggregates[55]) / V16tuple.aggregates[54] + V16tuple.aggregates[59] - (V16tuple.aggregates[58] * V16tuple.aggregates[58]) / V16tuple.aggregates[57] : 1.79769e+308);
      variance[29] = ((V16tuple.aggregates[60] > 0  && V16tuple.aggregates[63] > 0) ? V16tuple.aggregates[62] - (V16tuple.aggregates[61] * V16tuple.aggregates[61]) / V16tuple.aggregates[60] + V16tuple.aggregates[65] - (V16tuple.aggregates[64] * V16tuple.aggregates[64]) / V16tuple.aggregates[63] : 1.79769e+308);
      variance[30] = ((V16tuple.aggregates[66] > 0  && V16tuple.aggregates[69] > 0) ? V16tuple.aggregates[68] - (V16tuple.aggregates[67] * V16tuple.aggregates[67]) / V16tuple.aggregates[66] + V16tuple.aggregates[71] - (V16tuple.aggregates[70] * V16tuple.aggregates[70]) / V16tuple.aggregates[69] : 1.79769e+308);
      variance[31] = ((V16tuple.aggregates[72] > 0  && V16tuple.aggregates[75] > 0) ? V16tuple.aggregates[74] - (V16tuple.aggregates[73] * V16tuple.aggregates[73]) / V16tuple.aggregates[72] + V16tuple.aggregates[77] - (V16tuple.aggregates[76] * V16tuple.aggregates[76]) / V16tuple.aggregates[75] : 1.79769e+308);
      variance[32] = ((V16tuple.aggregates[78] > 0  && V16tuple.aggregates[81] > 0) ? V16tuple.aggregates[80] - (V16tuple.aggregates[79] * V16tuple.aggregates[79]) / V16tuple.aggregates[78] + V16tuple.aggregates[83] - (V16tuple.aggregates[82] * V16tuple.aggregates[82]) / V16tuple.aggregates[81] : 1.79769e+308);
      variance[33] = ((V16tuple.aggregates[84] > 0  && V16tuple.aggregates[87] > 0) ? V16tuple.aggregates[86] - (V16tuple.aggregates[85] * V16tuple.aggregates[85]) / V16tuple.aggregates[84] + V16tuple.aggregates[89] - (V16tuple.aggregates[88] * V16tuple.aggregates[88]) / V16tuple.aggregates[87] : 1.79769e+308);
      variance[34] = ((V16tuple.aggregates[90] > 0  && V16tuple.aggregates[93] > 0) ? V16tuple.aggregates[92] - (V16tuple.aggregates[91] * V16tuple.aggregates[91]) / V16tuple.aggregates[90] + V16tuple.aggregates[95] - (V16tuple.aggregates[94] * V16tuple.aggregates[94]) / V16tuple.aggregates[93] : 1.79769e+308);
      variance[35] = ((V16tuple.aggregates[96] > 0  && V16tuple.aggregates[99] > 0) ? V16tuple.aggregates[98] - (V16tuple.aggregates[97] * V16tuple.aggregates[97]) / V16tuple.aggregates[96] + V16tuple.aggregates[101] - (V16tuple.aggregates[100] * V16tuple.aggregates[100]) / V16tuple.aggregates[99] : 1.79769e+308);
      variance[36] = ((V16tuple.aggregates[102] > 0  && V16tuple.aggregates[105] > 0) ? V16tuple.aggregates[104] - (V16tuple.aggregates[103] * V16tuple.aggregates[103]) / V16tuple.aggregates[102] + V16tuple.aggregates[107] - (V16tuple.aggregates[106] * V16tuple.aggregates[106]) / V16tuple.aggregates[105] : 1.79769e+308);
      variance[37] = ((V16tuple.aggregates[108] > 0  && V16tuple.aggregates[111] > 0) ? V16tuple.aggregates[110] - (V16tuple.aggregates[109] * V16tuple.aggregates[109]) / V16tuple.aggregates[108] + V16tuple.aggregates[113] - (V16tuple.aggregates[112] * V16tuple.aggregates[112]) / V16tuple.aggregates[111] : 1.79769e+308);
      size_t categIdx = 38;
      double difference[3], *compaggs;
      compaggs = &V5[0].aggregates[0];
      for (V6_tuple& V6tuple : V6)
      {
         if(V6tuple.aggregates[0] == 0 || V6tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V6tuple.aggregates[i];
         variance[categIdx++] = V6tuple.aggregates[2] - (V6tuple.aggregates[1] * V6tuple.aggregates[1]) / V6tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V7_tuple& V7tuple : V7)
      {
         if(V7tuple.aggregates[0] == 0 || V7tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V7tuple.aggregates[i];
         variance[categIdx++] = V7tuple.aggregates[2] - (V7tuple.aggregates[1] * V7tuple.aggregates[1]) / V7tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V11_tuple& V11tuple : V11)
      {
         if(V11tuple.aggregates[0] == 0 || V11tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V11tuple.aggregates[i];
         variance[categIdx++] = V11tuple.aggregates[2] - (V11tuple.aggregates[1] * V11tuple.aggregates[1]) / V11tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V12_tuple& V12tuple : V12)
      {
         if(V12tuple.aggregates[0] == 0 || V12tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V12tuple.aggregates[i];
         variance[categIdx++] = V12tuple.aggregates[2] - (V12tuple.aggregates[1] * V12tuple.aggregates[1]) / V12tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V13_tuple& V13tuple : V13)
      {
         if(V13tuple.aggregates[0] == 0 || V13tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V13tuple.aggregates[i];
         variance[categIdx++] = V13tuple.aggregates[2] - (V13tuple.aggregates[1] * V13tuple.aggregates[1]) / V13tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V14_tuple& V14tuple : V14)
      {
         if(V14tuple.aggregates[0] == 0 || V14tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V14tuple.aggregates[i];
         variance[categIdx++] = V14tuple.aggregates[2] - (V14tuple.aggregates[1] * V14tuple.aggregates[1]) / V14tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V18_tuple& V18tuple : V18)
      {
         if(V18tuple.aggregates[0] == 0 || V18tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V18tuple.aggregates[i];
         variance[categIdx++] = V18tuple.aggregates[2] - (V18tuple.aggregates[1] * V18tuple.aggregates[1]) / V18tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V19_tuple& V19tuple : V19)
      {
         if(V19tuple.aggregates[0] == 0 || V19tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V19tuple.aggregates[i];
         variance[categIdx++] = V19tuple.aggregates[2] - (V19tuple.aggregates[1] * V19tuple.aggregates[1]) / V19tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V20_tuple& V20tuple : V20)
      {
         if(V20tuple.aggregates[0] == 0 || V20tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V20tuple.aggregates[i];
         variance[categIdx++] = V20tuple.aggregates[2] - (V20tuple.aggregates[1] * V20tuple.aggregates[1]) / V20tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V21_tuple& V21tuple : V21)
      {
         if(V21tuple.aggregates[0] == 0 || V21tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V21tuple.aggregates[i];
         variance[categIdx++] = V21tuple.aggregates[2] - (V21tuple.aggregates[1] * V21tuple.aggregates[1]) / V21tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V23_tuple& V23tuple : V23)
      {
         if(V23tuple.aggregates[0] == 0 || V23tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V23tuple.aggregates[i];
         variance[categIdx++] = V23tuple.aggregates[2] - (V23tuple.aggregates[1] * V23tuple.aggregates[1]) / V23tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V24_tuple& V24tuple : V24)
      {
         if(V24tuple.aggregates[0] == 0 || V24tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V24tuple.aggregates[i];
         variance[categIdx++] = V24tuple.aggregates[2] - (V24tuple.aggregates[1] * V24tuple.aggregates[1]) / V24tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V5[0].aggregates[0];
      for (V25_tuple& V25tuple : V25)
      {
         if(V25tuple.aggregates[0] == 0 || V25tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V25tuple.aggregates[i];
         variance[categIdx++] = V25tuple.aggregates[2] - (V25tuple.aggregates[1] * V25tuple.aggregates[1]) / V25tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }

      double min_variance = variance[0];
      size_t threshold = 0;

      for (size_t t=1; t < numberOfThresholds; ++t)
      {
         if (variance[t] < min_variance)
         {
            min_variance = variance[t];
            threshold = t;
         }
      }
      std::cout << "The minimum variance is: " << min_variance <<" for variable " << thresholdMap[threshold].varID << " and threshold: " << thresholdMap[threshold].threshold << std::endl;
      std::ofstream ofs("bestsplit.out",std::ofstream::out);
      ofs << std::fixed << min_variance << "\t" << thresholdMap[threshold].varID << "\t" << thresholdMap[threshold].threshold  << "\t" << thresholdMap[threshold].categorical  << "\t" << thresholdMap[threshold].aggregates[0]  << "\t" << thresholdMap[threshold].compAggregates[0] << "\t" << thresholdMap[threshold].aggregates[1]/thresholdMap[threshold].aggregates[0] << "\t" << thresholdMap[threshold].compAggregates[1]/thresholdMap[threshold].compAggregates[0] << std::endl;
      ofs.close();
   }

   void runApplication()
   {
      int64_t startProcess = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
      initCostArray();
      computeCost();

      int64_t endProcess = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-startProcess;
      std::cout << "Run Application: "+std::to_string(endProcess)+"ms.\n";

      std::ofstream ofs("times.txt",std::ofstream::out | std::ofstream::app);
      ofs << "\t" << endProcess << std::endl;
      ofs.close();

   }

}
