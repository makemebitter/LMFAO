#ifdef TESTING 
   #include <iomanip>
#endif
#include "DataHandler.h"
#include "ComputeGroup0.h"
#include "ComputeGroup1.h"
#include "ComputeGroup2.h"
#include "ApplicationHandler.h"

namespace lmfao
{
   std::vector<Sales_tuple> Sales;
   std::vector<Oil_tuple> Oil;
   std::vector<V0_tuple> V0;
   std::vector<V1_tuple> V1;
   std::vector<V2_tuple> V2;
   std::vector<V3_tuple> V3;
   std::vector<V4_tuple> V4;
   std::vector<V5_tuple> V5;
   void loadRelations()
   {
      std::ifstream input;
      std::string line;

      Sales.clear();
      input.open(PATH_TO_DATA + "/Sales.tbl");
      if (!input)
      {
         std::cerr << PATH_TO_DATA + "Sales.tbl does is not exist. \n";
         exit(1);
      }
      while(getline(input, line))
         Sales.push_back(Sales_tuple(line));
      input.close();

      Oil.clear();
      input.open(PATH_TO_DATA + "/Oil.tbl");
      if (!input)
      {
         std::cerr << PATH_TO_DATA + "Oil.tbl does is not exist. \n";
         exit(1);
      }
      while(getline(input, line))
         Oil.push_back(Oil_tuple(line));
      input.close();

      V0.reserve(1000000);
      V1.reserve(1000000);
      V2.reserve(1000000);
      V3.reserve(1000000);
      V4.reserve(1000000);
      V5.reserve(1000000);
   }

   void sortSales()
   {
      std::sort(Sales.begin(),Sales.end(),[ ](const Sales_tuple& lhs, const Sales_tuple& rhs)
      {
         if(lhs.date != rhs.date)
            return lhs.date < rhs.date;
         if(lhs.store != rhs.store)
            return lhs.store < rhs.store;
         if(lhs.item != rhs.item)
            return lhs.item < rhs.item;
         if(lhs.unit_sales != rhs.unit_sales)
            return lhs.unit_sales < rhs.unit_sales;
         if(lhs.onpromotion != rhs.onpromotion)
            return lhs.onpromotion < rhs.onpromotion;
         return false;
      });
   }

   void sortOil()
   {
      std::sort(Oil.begin(),Oil.end(),[ ](const Oil_tuple& lhs, const Oil_tuple& rhs)
      {
         if(lhs.date != rhs.date)
            return lhs.date < rhs.date;
         if(lhs.oilprize != rhs.oilprize)
            return lhs.oilprize < rhs.oilprize;
         return false;
      });
   }

   void run()
   {
      int64_t startLoading = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

      loadRelations();

      int64_t loadTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-startLoading;
      std::cout << "Data loading: "+std::to_string(loadTime)+"ms.\n";
      std::ofstream ofs("times.txt",std::ofstream::out | std::ofstream::app);
      ofs << loadTime;
      ofs.close();

      int64_t startSorting = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

      std::thread sortSalesThread(sortSales);
      std::thread sortOilThread(sortOil);
      sortSalesThread.join();
      sortOilThread.join();

      int64_t sortingTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-startSorting;
      std::cout << "Data sorting: " + std::to_string(sortingTime)+"ms.\n";

      ofs.open("times.txt",std::ofstream::out | std::ofstream::app);
      ofs << "\t" << sortingTime;
      ofs.close();

      int64_t startProcess = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

      std::thread group0Thread(computeGroup0);
      group0Thread.join();
      std::thread group1Thread(computeGroup1);
      group1Thread.join();
      std::thread group2Thread(computeGroup2);
      group2Thread.join();

      int64_t processTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-startProcess;
      std::cout << "Data process: "+std::to_string(processTime)+"ms.\n";
      ofs.open("times.txt",std::ofstream::out | std::ofstream::app);
      ofs << "\t" << processTime;
      std::cout << "Size of each computed View: " << std::endl;
      std::cout << "V0: " << V0.size() << std::endl;
      std::cout << "V1: " << V1.size() << std::endl;
      std::cout << "V2: " << V2.size() << std::endl;
      std::cout << "V3: " << V3.size() << std::endl;
      std::cout << "V4: " << V4.size() << std::endl;
      std::cout << "V5: " << V5.size() << std::endl;
      ofs.close();

      int64_t appProcess = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

      runApplication();
   }

#ifdef TESTING
   void ouputViewsForTesting()
   {
      std::ofstream ofs("test.out");
      ofs << std::fixed << std::setprecision(2);
      for (size_t i=0; i < V1.size(); ++i)
      {
         V1_tuple& tuple = V1[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V2.size(); ++i)
      {
         V2_tuple& tuple = V2[i];
         ofs  << tuple.store <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V3.size(); ++i)
      {
         V3_tuple& tuple = V3[i];
         ofs  << tuple.onpromotion <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V5.size(); ++i)
      {
         V5_tuple& tuple = V5[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "|" << tuple.aggregates[3] << "|" << tuple.aggregates[4] << "|" << tuple.aggregates[5] << "|" << tuple.aggregates[6] << "|" << tuple.aggregates[7] << "|" << tuple.aggregates[8] << "|" << tuple.aggregates[9] << "|" << tuple.aggregates[10] << "|" << tuple.aggregates[11] << "|" << tuple.aggregates[12] << "|" << tuple.aggregates[13] << "|" << tuple.aggregates[14] << "|" << tuple.aggregates[15] << "|" << tuple.aggregates[16] << "|" << tuple.aggregates[17] << "|" << tuple.aggregates[18] << "|" << tuple.aggregates[19] << "|" << tuple.aggregates[20] << "|" << tuple.aggregates[21] << "|" << tuple.aggregates[22] << "|" << tuple.aggregates[23] << "|" << tuple.aggregates[24] << "|" << tuple.aggregates[25] << "|" << tuple.aggregates[26] << "|" << tuple.aggregates[27] << "|" << tuple.aggregates[28] << "|" << tuple.aggregates[29] << "|" << tuple.aggregates[30] << "|" << tuple.aggregates[31] << "|" << tuple.aggregates[32] << "|" << tuple.aggregates[33] << "|" << tuple.aggregates[34] << "|" << tuple.aggregates[35] << "|" << tuple.aggregates[36] << "|" << tuple.aggregates[37] << "|" << tuple.aggregates[38] << "|" << tuple.aggregates[39] << "|" << tuple.aggregates[40] << "|" << tuple.aggregates[41] << "|" << tuple.aggregates[42] << "|" << tuple.aggregates[43] << "|" << tuple.aggregates[44] << "|" << tuple.aggregates[45] << "|" << tuple.aggregates[46] << "|" << tuple.aggregates[47] << "|" << tuple.aggregates[48] << "|" << tuple.aggregates[49] << "|" << tuple.aggregates[50] << "|" << tuple.aggregates[51] << "|" << tuple.aggregates[52] << "|" << tuple.aggregates[53] << "|" << tuple.aggregates[54] << "|" << tuple.aggregates[55] << "|" << tuple.aggregates[56] << "|" << tuple.aggregates[57] << "|" << tuple.aggregates[58] << "|" << tuple.aggregates[59] << "|" << tuple.aggregates[60] << "|" << tuple.aggregates[61] << "|" << tuple.aggregates[62] << "|" << tuple.aggregates[63] << "|" << tuple.aggregates[64] << "|" << tuple.aggregates[65] << "|" << tuple.aggregates[66] << "|" << tuple.aggregates[67] << "|" << tuple.aggregates[68] << "|" << tuple.aggregates[69] << "|" << tuple.aggregates[70] << "|" << tuple.aggregates[71] << "|" << tuple.aggregates[72] << "|" << tuple.aggregates[73] << "|" << tuple.aggregates[74] << "|" << tuple.aggregates[75] << "|" << tuple.aggregates[76] << "|" << tuple.aggregates[77] << "|" << tuple.aggregates[78] << "|" << tuple.aggregates[79] << "|" << tuple.aggregates[80] << "|" << tuple.aggregates[81] << "|" << tuple.aggregates[82] << "|" << tuple.aggregates[83] << "|" << tuple.aggregates[84] << "|" << tuple.aggregates[85] << "|" << tuple.aggregates[86] << "|" << tuple.aggregates[87] << "|" << tuple.aggregates[88] << "|" << tuple.aggregates[89] << "|" << tuple.aggregates[90] << "|" << tuple.aggregates[91] << "|" << tuple.aggregates[92] << "|" << tuple.aggregates[93] << "|" << tuple.aggregates[94] << "|" << tuple.aggregates[95] << "|" << tuple.aggregates[96] << "|" << tuple.aggregates[97] << "|" << tuple.aggregates[98] << "|" << tuple.aggregates[99] << "|" << tuple.aggregates[100] << "|" << tuple.aggregates[101] << "|" << tuple.aggregates[102] << "|" << tuple.aggregates[103] << "|" << tuple.aggregates[104] << "|" << tuple.aggregates[105] << "|" << tuple.aggregates[106] << "|" << tuple.aggregates[107] << "|" << tuple.aggregates[108] << "|" << tuple.aggregates[109] << "|" << tuple.aggregates[110] << "|" << tuple.aggregates[111] << "|" << tuple.aggregates[112] << "|" << tuple.aggregates[113] << "\n";
      }
      ofs.close();
   }
#endif
#ifdef DUMP_OUTPUT
   void dumpOutputViews()
   {
      std::ofstream ofs;
      ofs.open("output/V1.tbl");
      ofs << "0 3\n";
      for (size_t i=0; i < V1.size(); ++i)
      {
         V1_tuple& tuple = V1[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V2.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V2.size(); ++i)
      {
         V2_tuple& tuple = V2[i];
         ofs  << tuple.store <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V3.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V3.size(); ++i)
      {
         V3_tuple& tuple = V3[i];
         ofs  << tuple.onpromotion <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V5.tbl");
      ofs << "0 114\n";
      for (size_t i=0; i < V5.size(); ++i)
      {
         V5_tuple& tuple = V5[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "|" << tuple.aggregates[3] << "|" << tuple.aggregates[4] << "|" << tuple.aggregates[5] << "|" << tuple.aggregates[6] << "|" << tuple.aggregates[7] << "|" << tuple.aggregates[8] << "|" << tuple.aggregates[9] << "|" << tuple.aggregates[10] << "|" << tuple.aggregates[11] << "|" << tuple.aggregates[12] << "|" << tuple.aggregates[13] << "|" << tuple.aggregates[14] << "|" << tuple.aggregates[15] << "|" << tuple.aggregates[16] << "|" << tuple.aggregates[17] << "|" << tuple.aggregates[18] << "|" << tuple.aggregates[19] << "|" << tuple.aggregates[20] << "|" << tuple.aggregates[21] << "|" << tuple.aggregates[22] << "|" << tuple.aggregates[23] << "|" << tuple.aggregates[24] << "|" << tuple.aggregates[25] << "|" << tuple.aggregates[26] << "|" << tuple.aggregates[27] << "|" << tuple.aggregates[28] << "|" << tuple.aggregates[29] << "|" << tuple.aggregates[30] << "|" << tuple.aggregates[31] << "|" << tuple.aggregates[32] << "|" << tuple.aggregates[33] << "|" << tuple.aggregates[34] << "|" << tuple.aggregates[35] << "|" << tuple.aggregates[36] << "|" << tuple.aggregates[37] << "|" << tuple.aggregates[38] << "|" << tuple.aggregates[39] << "|" << tuple.aggregates[40] << "|" << tuple.aggregates[41] << "|" << tuple.aggregates[42] << "|" << tuple.aggregates[43] << "|" << tuple.aggregates[44] << "|" << tuple.aggregates[45] << "|" << tuple.aggregates[46] << "|" << tuple.aggregates[47] << "|" << tuple.aggregates[48] << "|" << tuple.aggregates[49] << "|" << tuple.aggregates[50] << "|" << tuple.aggregates[51] << "|" << tuple.aggregates[52] << "|" << tuple.aggregates[53] << "|" << tuple.aggregates[54] << "|" << tuple.aggregates[55] << "|" << tuple.aggregates[56] << "|" << tuple.aggregates[57] << "|" << tuple.aggregates[58] << "|" << tuple.aggregates[59] << "|" << tuple.aggregates[60] << "|" << tuple.aggregates[61] << "|" << tuple.aggregates[62] << "|" << tuple.aggregates[63] << "|" << tuple.aggregates[64] << "|" << tuple.aggregates[65] << "|" << tuple.aggregates[66] << "|" << tuple.aggregates[67] << "|" << tuple.aggregates[68] << "|" << tuple.aggregates[69] << "|" << tuple.aggregates[70] << "|" << tuple.aggregates[71] << "|" << tuple.aggregates[72] << "|" << tuple.aggregates[73] << "|" << tuple.aggregates[74] << "|" << tuple.aggregates[75] << "|" << tuple.aggregates[76] << "|" << tuple.aggregates[77] << "|" << tuple.aggregates[78] << "|" << tuple.aggregates[79] << "|" << tuple.aggregates[80] << "|" << tuple.aggregates[81] << "|" << tuple.aggregates[82] << "|" << tuple.aggregates[83] << "|" << tuple.aggregates[84] << "|" << tuple.aggregates[85] << "|" << tuple.aggregates[86] << "|" << tuple.aggregates[87] << "|" << tuple.aggregates[88] << "|" << tuple.aggregates[89] << "|" << tuple.aggregates[90] << "|" << tuple.aggregates[91] << "|" << tuple.aggregates[92] << "|" << tuple.aggregates[93] << "|" << tuple.aggregates[94] << "|" << tuple.aggregates[95] << "|" << tuple.aggregates[96] << "|" << tuple.aggregates[97] << "|" << tuple.aggregates[98] << "|" << tuple.aggregates[99] << "|" << tuple.aggregates[100] << "|" << tuple.aggregates[101] << "|" << tuple.aggregates[102] << "|" << tuple.aggregates[103] << "|" << tuple.aggregates[104] << "|" << tuple.aggregates[105] << "|" << tuple.aggregates[106] << "|" << tuple.aggregates[107] << "|" << tuple.aggregates[108] << "|" << tuple.aggregates[109] << "|" << tuple.aggregates[110] << "|" << tuple.aggregates[111] << "|" << tuple.aggregates[112] << "|" << tuple.aggregates[113] << "\n";
      }
      ofs.close();
   }
#endif
}

int main(int argc, char *argv[])
{
   std::cout << "run lmfao" << std::endl;
   lmfao::run();
#ifdef TESTING
   lmfao::ouputViewsForTesting();
#endif
#ifdef DUMP_OUTPUT
   lmfao::dumpOutputViews();
#endif
   return 0;
};
