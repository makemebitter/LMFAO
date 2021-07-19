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
      numberOfThresholds = V2.size() + V3.size() + 19;
      variance = new double[numberOfThresholds];
      thresholdMap = new Threshold[numberOfThresholds];
      thresholdMap[0].set(5,35.360000,0,&V5[0].aggregates[0],&V5[0].aggregates[3]);
      thresholdMap[1].set(5,40.050000,0,&V5[0].aggregates[6],&V5[0].aggregates[9]);
      thresholdMap[2].set(5,43.040000,0,&V5[0].aggregates[12],&V5[0].aggregates[15]);
      thresholdMap[3].set(5,44.470000,0,&V5[0].aggregates[18],&V5[0].aggregates[21]);
      thresholdMap[4].set(5,45.470000,0,&V5[0].aggregates[24],&V5[0].aggregates[27]);
      thresholdMap[5].set(5,46.120000,0,&V5[0].aggregates[30],&V5[0].aggregates[33]);
      thresholdMap[6].set(5,47.170000,0,&V5[0].aggregates[36],&V5[0].aggregates[39]);
      thresholdMap[7].set(5,48.130000,0,&V5[0].aggregates[42],&V5[0].aggregates[45]);
      thresholdMap[8].set(5,49.070000,0,&V5[0].aggregates[48],&V5[0].aggregates[51]);
      thresholdMap[9].set(5,49.850000,0,&V5[0].aggregates[54],&V5[0].aggregates[57]);
      thresholdMap[10].set(5,51.610000,0,&V5[0].aggregates[60],&V5[0].aggregates[63]);
      thresholdMap[11].set(5,53.010000,0,&V5[0].aggregates[66],&V5[0].aggregates[69]);
      thresholdMap[12].set(5,54.590000,0,&V5[0].aggregates[72],&V5[0].aggregates[75]);
      thresholdMap[13].set(5,60.250000,0,&V5[0].aggregates[78],&V5[0].aggregates[81]);
      thresholdMap[14].set(5,90.880000,0,&V5[0].aggregates[84],&V5[0].aggregates[87]);
      thresholdMap[15].set(5,93.840000,0,&V5[0].aggregates[90],&V5[0].aggregates[93]);
      thresholdMap[16].set(5,97.030000,0,&V5[0].aggregates[96],&V5[0].aggregates[99]);
      thresholdMap[17].set(5,100.520000,0,&V5[0].aggregates[102],&V5[0].aggregates[105]);
      thresholdMap[18].set(5,104.060000,0,&V5[0].aggregates[108],&V5[0].aggregates[111]);
      size_t categIdx = 19;
      for (V2_tuple& tuple : V2)
         thresholdMap[categIdx++].set(1,tuple.store,1,&tuple.aggregates[0],&V1[0].aggregates[0]);
      for (V3_tuple& tuple : V3)
         thresholdMap[categIdx++].set(4,tuple.onpromotion,1,&tuple.aggregates[0],&V1[0].aggregates[0]);
   }

   void computeCost()
   {
      V5_tuple& V5tuple = V5[0];
      variance[0] = ((V5tuple.aggregates[0] > 0  && V5tuple.aggregates[3] > 0) ? V5tuple.aggregates[2] - (V5tuple.aggregates[1] * V5tuple.aggregates[1]) / V5tuple.aggregates[0] + V5tuple.aggregates[5] - (V5tuple.aggregates[4] * V5tuple.aggregates[4]) / V5tuple.aggregates[3] : 1.79769e+308);
      variance[1] = ((V5tuple.aggregates[6] > 0  && V5tuple.aggregates[9] > 0) ? V5tuple.aggregates[8] - (V5tuple.aggregates[7] * V5tuple.aggregates[7]) / V5tuple.aggregates[6] + V5tuple.aggregates[11] - (V5tuple.aggregates[10] * V5tuple.aggregates[10]) / V5tuple.aggregates[9] : 1.79769e+308);
      variance[2] = ((V5tuple.aggregates[12] > 0  && V5tuple.aggregates[15] > 0) ? V5tuple.aggregates[14] - (V5tuple.aggregates[13] * V5tuple.aggregates[13]) / V5tuple.aggregates[12] + V5tuple.aggregates[17] - (V5tuple.aggregates[16] * V5tuple.aggregates[16]) / V5tuple.aggregates[15] : 1.79769e+308);
      variance[3] = ((V5tuple.aggregates[18] > 0  && V5tuple.aggregates[21] > 0) ? V5tuple.aggregates[20] - (V5tuple.aggregates[19] * V5tuple.aggregates[19]) / V5tuple.aggregates[18] + V5tuple.aggregates[23] - (V5tuple.aggregates[22] * V5tuple.aggregates[22]) / V5tuple.aggregates[21] : 1.79769e+308);
      variance[4] = ((V5tuple.aggregates[24] > 0  && V5tuple.aggregates[27] > 0) ? V5tuple.aggregates[26] - (V5tuple.aggregates[25] * V5tuple.aggregates[25]) / V5tuple.aggregates[24] + V5tuple.aggregates[29] - (V5tuple.aggregates[28] * V5tuple.aggregates[28]) / V5tuple.aggregates[27] : 1.79769e+308);
      variance[5] = ((V5tuple.aggregates[30] > 0  && V5tuple.aggregates[33] > 0) ? V5tuple.aggregates[32] - (V5tuple.aggregates[31] * V5tuple.aggregates[31]) / V5tuple.aggregates[30] + V5tuple.aggregates[35] - (V5tuple.aggregates[34] * V5tuple.aggregates[34]) / V5tuple.aggregates[33] : 1.79769e+308);
      variance[6] = ((V5tuple.aggregates[36] > 0  && V5tuple.aggregates[39] > 0) ? V5tuple.aggregates[38] - (V5tuple.aggregates[37] * V5tuple.aggregates[37]) / V5tuple.aggregates[36] + V5tuple.aggregates[41] - (V5tuple.aggregates[40] * V5tuple.aggregates[40]) / V5tuple.aggregates[39] : 1.79769e+308);
      variance[7] = ((V5tuple.aggregates[42] > 0  && V5tuple.aggregates[45] > 0) ? V5tuple.aggregates[44] - (V5tuple.aggregates[43] * V5tuple.aggregates[43]) / V5tuple.aggregates[42] + V5tuple.aggregates[47] - (V5tuple.aggregates[46] * V5tuple.aggregates[46]) / V5tuple.aggregates[45] : 1.79769e+308);
      variance[8] = ((V5tuple.aggregates[48] > 0  && V5tuple.aggregates[51] > 0) ? V5tuple.aggregates[50] - (V5tuple.aggregates[49] * V5tuple.aggregates[49]) / V5tuple.aggregates[48] + V5tuple.aggregates[53] - (V5tuple.aggregates[52] * V5tuple.aggregates[52]) / V5tuple.aggregates[51] : 1.79769e+308);
      variance[9] = ((V5tuple.aggregates[54] > 0  && V5tuple.aggregates[57] > 0) ? V5tuple.aggregates[56] - (V5tuple.aggregates[55] * V5tuple.aggregates[55]) / V5tuple.aggregates[54] + V5tuple.aggregates[59] - (V5tuple.aggregates[58] * V5tuple.aggregates[58]) / V5tuple.aggregates[57] : 1.79769e+308);
      variance[10] = ((V5tuple.aggregates[60] > 0  && V5tuple.aggregates[63] > 0) ? V5tuple.aggregates[62] - (V5tuple.aggregates[61] * V5tuple.aggregates[61]) / V5tuple.aggregates[60] + V5tuple.aggregates[65] - (V5tuple.aggregates[64] * V5tuple.aggregates[64]) / V5tuple.aggregates[63] : 1.79769e+308);
      variance[11] = ((V5tuple.aggregates[66] > 0  && V5tuple.aggregates[69] > 0) ? V5tuple.aggregates[68] - (V5tuple.aggregates[67] * V5tuple.aggregates[67]) / V5tuple.aggregates[66] + V5tuple.aggregates[71] - (V5tuple.aggregates[70] * V5tuple.aggregates[70]) / V5tuple.aggregates[69] : 1.79769e+308);
      variance[12] = ((V5tuple.aggregates[72] > 0  && V5tuple.aggregates[75] > 0) ? V5tuple.aggregates[74] - (V5tuple.aggregates[73] * V5tuple.aggregates[73]) / V5tuple.aggregates[72] + V5tuple.aggregates[77] - (V5tuple.aggregates[76] * V5tuple.aggregates[76]) / V5tuple.aggregates[75] : 1.79769e+308);
      variance[13] = ((V5tuple.aggregates[78] > 0  && V5tuple.aggregates[81] > 0) ? V5tuple.aggregates[80] - (V5tuple.aggregates[79] * V5tuple.aggregates[79]) / V5tuple.aggregates[78] + V5tuple.aggregates[83] - (V5tuple.aggregates[82] * V5tuple.aggregates[82]) / V5tuple.aggregates[81] : 1.79769e+308);
      variance[14] = ((V5tuple.aggregates[84] > 0  && V5tuple.aggregates[87] > 0) ? V5tuple.aggregates[86] - (V5tuple.aggregates[85] * V5tuple.aggregates[85]) / V5tuple.aggregates[84] + V5tuple.aggregates[89] - (V5tuple.aggregates[88] * V5tuple.aggregates[88]) / V5tuple.aggregates[87] : 1.79769e+308);
      variance[15] = ((V5tuple.aggregates[90] > 0  && V5tuple.aggregates[93] > 0) ? V5tuple.aggregates[92] - (V5tuple.aggregates[91] * V5tuple.aggregates[91]) / V5tuple.aggregates[90] + V5tuple.aggregates[95] - (V5tuple.aggregates[94] * V5tuple.aggregates[94]) / V5tuple.aggregates[93] : 1.79769e+308);
      variance[16] = ((V5tuple.aggregates[96] > 0  && V5tuple.aggregates[99] > 0) ? V5tuple.aggregates[98] - (V5tuple.aggregates[97] * V5tuple.aggregates[97]) / V5tuple.aggregates[96] + V5tuple.aggregates[101] - (V5tuple.aggregates[100] * V5tuple.aggregates[100]) / V5tuple.aggregates[99] : 1.79769e+308);
      variance[17] = ((V5tuple.aggregates[102] > 0  && V5tuple.aggregates[105] > 0) ? V5tuple.aggregates[104] - (V5tuple.aggregates[103] * V5tuple.aggregates[103]) / V5tuple.aggregates[102] + V5tuple.aggregates[107] - (V5tuple.aggregates[106] * V5tuple.aggregates[106]) / V5tuple.aggregates[105] : 1.79769e+308);
      variance[18] = ((V5tuple.aggregates[108] > 0  && V5tuple.aggregates[111] > 0) ? V5tuple.aggregates[110] - (V5tuple.aggregates[109] * V5tuple.aggregates[109]) / V5tuple.aggregates[108] + V5tuple.aggregates[113] - (V5tuple.aggregates[112] * V5tuple.aggregates[112]) / V5tuple.aggregates[111] : 1.79769e+308);
      size_t categIdx = 19;
      double difference[3], *compaggs;
      compaggs = &V1[0].aggregates[0];
      for (V2_tuple& V2tuple : V2)
      {
         if(V2tuple.aggregates[0] == 0 || V2tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V2tuple.aggregates[i];
         variance[categIdx++] = V2tuple.aggregates[2] - (V2tuple.aggregates[1] * V2tuple.aggregates[1]) / V2tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
      }
      compaggs = &V1[0].aggregates[0];
      for (V3_tuple& V3tuple : V3)
      {
         if(V3tuple.aggregates[0] == 0 || V3tuple.aggregates[0] == compaggs[0])
         {
            variance[categIdx++] = 1.79769e+308;
            continue;
         }
         for (size_t i=0; i < 3; ++i)
            difference[i] = compaggs[i] - V3tuple.aggregates[i];
         variance[categIdx++] = V3tuple.aggregates[2] - (V3tuple.aggregates[1] * V3tuple.aggregates[1]) / V3tuple.aggregates[0] + difference[2] - (difference[1] * difference[1]) / difference[0];
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
