#ifdef TESTING 
   #include <iomanip>
#endif
#include "DataHandler.h"
#include "ComputeGroup0.h"
#include "ComputeGroup1.h"
#include "ComputeGroup2.h"
#include "ComputeGroup3.h"
#include "ComputeGroup4.h"
#include "ComputeGroup5.h"
#include "ComputeGroup6.h"
#include "ComputeGroup7.h"
#include "ComputeGroup8.h"
#include "ComputeGroup9.h"
#include "ComputeGroup10.h"
#include "ApplicationHandler.h"

namespace lmfao
{
   std::vector<Sales_tuple> Sales;
   std::vector<Oil_tuple> Oil;
   std::vector<Holiday_tuple> Holiday;
   std::vector<Transactions_tuple> Transactions;
   std::vector<Stores_tuple> Stores;
   std::vector<Items_tuple> Items;
   std::vector<V0_tuple> V0;
   std::vector<V1_tuple> V1;
   std::vector<V2_tuple> V2;
   std::vector<V3_tuple> V3;
   std::vector<V4_tuple> V4;
   std::vector<V5_tuple> V5;
   std::vector<V6_tuple> V6;
   std::vector<V7_tuple> V7;
   std::vector<V8_tuple> V8;
   std::vector<V9_tuple> V9;
   std::vector<V10_tuple> V10;
   std::vector<V11_tuple> V11;
   std::vector<V12_tuple> V12;
   std::vector<V13_tuple> V13;
   std::vector<V14_tuple> V14;
   std::vector<V15_tuple> V15;
   std::vector<V16_tuple> V16;
   std::vector<V17_tuple> V17;
   std::vector<V18_tuple> V18;
   std::vector<V19_tuple> V19;
   std::vector<V20_tuple> V20;
   std::vector<V21_tuple> V21;
   std::vector<V22_tuple> V22;
   std::vector<V23_tuple> V23;
   std::vector<V24_tuple> V24;
   std::vector<V25_tuple> V25;
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

      Holiday.clear();
      input.open(PATH_TO_DATA + "/Holiday.tbl");
      if (!input)
      {
         std::cerr << PATH_TO_DATA + "Holiday.tbl does is not exist. \n";
         exit(1);
      }
      while(getline(input, line))
         Holiday.push_back(Holiday_tuple(line));
      input.close();

      Transactions.clear();
      input.open(PATH_TO_DATA + "/Transactions.tbl");
      if (!input)
      {
         std::cerr << PATH_TO_DATA + "Transactions.tbl does is not exist. \n";
         exit(1);
      }
      while(getline(input, line))
         Transactions.push_back(Transactions_tuple(line));
      input.close();

      Stores.clear();
      input.open(PATH_TO_DATA + "/Stores.tbl");
      if (!input)
      {
         std::cerr << PATH_TO_DATA + "Stores.tbl does is not exist. \n";
         exit(1);
      }
      while(getline(input, line))
         Stores.push_back(Stores_tuple(line));
      input.close();

      Items.clear();
      input.open(PATH_TO_DATA + "/Items.tbl");
      if (!input)
      {
         std::cerr << PATH_TO_DATA + "Items.tbl does is not exist. \n";
         exit(1);
      }
      while(getline(input, line))
         Items.push_back(Items_tuple(line));
      input.close();

      V0.reserve(1000000);
      V1.reserve(1000000);
      V2.reserve(1000000);
      V3.reserve(1000000);
      V4.reserve(1000000);
      V5.reserve(1000000);
      V6.reserve(1000000);
      V7.reserve(1000000);
      V8.reserve(1000000);
      V9.reserve(1000000);
      V10.reserve(1000000);
      V11.reserve(1000000);
      V12.reserve(1000000);
      V13.reserve(1000000);
      V14.reserve(1000000);
      V15.reserve(1000000);
      V16.reserve(1000000);
      V17.reserve(1000000);
      V18.reserve(1000000);
      V19.reserve(1000000);
      V20.reserve(1000000);
      V21.reserve(1000000);
      V22.reserve(1000000);
      V23.reserve(1000000);
      V24.reserve(1000000);
      V25.reserve(1000000);
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

   void sortHoliday()
   {
      std::sort(Holiday.begin(),Holiday.end(),[ ](const Holiday_tuple& lhs, const Holiday_tuple& rhs)
      {
         if(lhs.date != rhs.date)
            return lhs.date < rhs.date;
         if(lhs.holiday_type != rhs.holiday_type)
            return lhs.holiday_type < rhs.holiday_type;
         if(lhs.locale != rhs.locale)
            return lhs.locale < rhs.locale;
         if(lhs.locale_id != rhs.locale_id)
            return lhs.locale_id < rhs.locale_id;
         if(lhs.transferred != rhs.transferred)
            return lhs.transferred < rhs.transferred;
         return false;
      });
   }

   void sortTransactions()
   {
      std::sort(Transactions.begin(),Transactions.end(),[ ](const Transactions_tuple& lhs, const Transactions_tuple& rhs)
      {
         if(lhs.date != rhs.date)
            return lhs.date < rhs.date;
         if(lhs.store != rhs.store)
            return lhs.store < rhs.store;
         if(lhs.transactions != rhs.transactions)
            return lhs.transactions < rhs.transactions;
         return false;
      });
   }

   void sortStores()
   {
      std::sort(Stores.begin(),Stores.end(),[ ](const Stores_tuple& lhs, const Stores_tuple& rhs)
      {
         if(lhs.store != rhs.store)
            return lhs.store < rhs.store;
         if(lhs.city != rhs.city)
            return lhs.city < rhs.city;
         if(lhs.state != rhs.state)
            return lhs.state < rhs.state;
         if(lhs.store_type != rhs.store_type)
            return lhs.store_type < rhs.store_type;
         if(lhs.cluster != rhs.cluster)
            return lhs.cluster < rhs.cluster;
         return false;
      });
   }

   void sortItems()
   {
      std::sort(Items.begin(),Items.end(),[ ](const Items_tuple& lhs, const Items_tuple& rhs)
      {
         if(lhs.item != rhs.item)
            return lhs.item < rhs.item;
         if(lhs.family != rhs.family)
            return lhs.family < rhs.family;
         if(lhs.itemclass != rhs.itemclass)
            return lhs.itemclass < rhs.itemclass;
         if(lhs.perishable != rhs.perishable)
            return lhs.perishable < rhs.perishable;
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
      std::thread sortHolidayThread(sortHoliday);
      std::thread sortTransactionsThread(sortTransactions);
      std::thread sortStoresThread(sortStores);
      std::thread sortItemsThread(sortItems);
      sortSalesThread.join();
      sortOilThread.join();
      sortHolidayThread.join();
      sortTransactionsThread.join();
      sortStoresThread.join();
      sortItemsThread.join();

      int64_t sortingTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-startSorting;
      std::cout << "Data sorting: " + std::to_string(sortingTime)+"ms.\n";

      ofs.open("times.txt",std::ofstream::out | std::ofstream::app);
      ofs << "\t" << sortingTime;
      ofs.close();

      int64_t startProcess = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

      std::thread group0Thread(computeGroup0);
      std::thread group1Thread(computeGroup1);
      std::thread group2Thread(computeGroup2);
      std::thread group3Thread(computeGroup3);
      std::thread group4Thread(computeGroup4);
      group0Thread.join();
      group1Thread.join();
      group2Thread.join();
      group3Thread.join();
      group4Thread.join();
      std::thread group5Thread(computeGroup5);
      group5Thread.join();
      std::thread group6Thread(computeGroup6);
      std::thread group7Thread(computeGroup7);
      std::thread group8Thread(computeGroup8);
      std::thread group9Thread(computeGroup9);
      std::thread group10Thread(computeGroup10);
      group6Thread.join();
      group7Thread.join();
      group8Thread.join();
      group9Thread.join();
      group10Thread.join();

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
      std::cout << "V6: " << V6.size() << std::endl;
      std::cout << "V7: " << V7.size() << std::endl;
      std::cout << "V8: " << V8.size() << std::endl;
      std::cout << "V9: " << V9.size() << std::endl;
      std::cout << "V10: " << V10.size() << std::endl;
      std::cout << "V11: " << V11.size() << std::endl;
      std::cout << "V12: " << V12.size() << std::endl;
      std::cout << "V13: " << V13.size() << std::endl;
      std::cout << "V14: " << V14.size() << std::endl;
      std::cout << "V15: " << V15.size() << std::endl;
      std::cout << "V16: " << V16.size() << std::endl;
      std::cout << "V17: " << V17.size() << std::endl;
      std::cout << "V18: " << V18.size() << std::endl;
      std::cout << "V19: " << V19.size() << std::endl;
      std::cout << "V20: " << V20.size() << std::endl;
      std::cout << "V21: " << V21.size() << std::endl;
      std::cout << "V22: " << V22.size() << std::endl;
      std::cout << "V23: " << V23.size() << std::endl;
      std::cout << "V24: " << V24.size() << std::endl;
      std::cout << "V25: " << V25.size() << std::endl;
      ofs.close();

      int64_t appProcess = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

      runApplication();
   }

#ifdef TESTING
   void ouputViewsForTesting()
   {
      std::ofstream ofs("test.out");
      ofs << std::fixed << std::setprecision(2);
      for (size_t i=0; i < V5.size(); ++i)
      {
         V5_tuple& tuple = V5[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V6.size(); ++i)
      {
         V6_tuple& tuple = V6[i];
         ofs  << tuple.store <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V7.size(); ++i)
      {
         V7_tuple& tuple = V7[i];
         ofs  << tuple.onpromotion <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V9.size(); ++i)
      {
         V9_tuple& tuple = V9[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "|" << tuple.aggregates[3] << "|" << tuple.aggregates[4] << "|" << tuple.aggregates[5] << "|" << tuple.aggregates[6] << "|" << tuple.aggregates[7] << "|" << tuple.aggregates[8] << "|" << tuple.aggregates[9] << "|" << tuple.aggregates[10] << "|" << tuple.aggregates[11] << "|" << tuple.aggregates[12] << "|" << tuple.aggregates[13] << "|" << tuple.aggregates[14] << "|" << tuple.aggregates[15] << "|" << tuple.aggregates[16] << "|" << tuple.aggregates[17] << "|" << tuple.aggregates[18] << "|" << tuple.aggregates[19] << "|" << tuple.aggregates[20] << "|" << tuple.aggregates[21] << "|" << tuple.aggregates[22] << "|" << tuple.aggregates[23] << "|" << tuple.aggregates[24] << "|" << tuple.aggregates[25] << "|" << tuple.aggregates[26] << "|" << tuple.aggregates[27] << "|" << tuple.aggregates[28] << "|" << tuple.aggregates[29] << "|" << tuple.aggregates[30] << "|" << tuple.aggregates[31] << "|" << tuple.aggregates[32] << "|" << tuple.aggregates[33] << "|" << tuple.aggregates[34] << "|" << tuple.aggregates[35] << "|" << tuple.aggregates[36] << "|" << tuple.aggregates[37] << "|" << tuple.aggregates[38] << "|" << tuple.aggregates[39] << "|" << tuple.aggregates[40] << "|" << tuple.aggregates[41] << "|" << tuple.aggregates[42] << "|" << tuple.aggregates[43] << "|" << tuple.aggregates[44] << "|" << tuple.aggregates[45] << "|" << tuple.aggregates[46] << "|" << tuple.aggregates[47] << "|" << tuple.aggregates[48] << "|" << tuple.aggregates[49] << "|" << tuple.aggregates[50] << "|" << tuple.aggregates[51] << "|" << tuple.aggregates[52] << "|" << tuple.aggregates[53] << "|" << tuple.aggregates[54] << "|" << tuple.aggregates[55] << "|" << tuple.aggregates[56] << "|" << tuple.aggregates[57] << "|" << tuple.aggregates[58] << "|" << tuple.aggregates[59] << "|" << tuple.aggregates[60] << "|" << tuple.aggregates[61] << "|" << tuple.aggregates[62] << "|" << tuple.aggregates[63] << "|" << tuple.aggregates[64] << "|" << tuple.aggregates[65] << "|" << tuple.aggregates[66] << "|" << tuple.aggregates[67] << "|" << tuple.aggregates[68] << "|" << tuple.aggregates[69] << "|" << tuple.aggregates[70] << "|" << tuple.aggregates[71] << "|" << tuple.aggregates[72] << "|" << tuple.aggregates[73] << "|" << tuple.aggregates[74] << "|" << tuple.aggregates[75] << "|" << tuple.aggregates[76] << "|" << tuple.aggregates[77] << "|" << tuple.aggregates[78] << "|" << tuple.aggregates[79] << "|" << tuple.aggregates[80] << "|" << tuple.aggregates[81] << "|" << tuple.aggregates[82] << "|" << tuple.aggregates[83] << "|" << tuple.aggregates[84] << "|" << tuple.aggregates[85] << "|" << tuple.aggregates[86] << "|" << tuple.aggregates[87] << "|" << tuple.aggregates[88] << "|" << tuple.aggregates[89] << "|" << tuple.aggregates[90] << "|" << tuple.aggregates[91] << "|" << tuple.aggregates[92] << "|" << tuple.aggregates[93] << "|" << tuple.aggregates[94] << "|" << tuple.aggregates[95] << "|" << tuple.aggregates[96] << "|" << tuple.aggregates[97] << "|" << tuple.aggregates[98] << "|" << tuple.aggregates[99] << "|" << tuple.aggregates[100] << "|" << tuple.aggregates[101] << "|" << tuple.aggregates[102] << "|" << tuple.aggregates[103] << "|" << tuple.aggregates[104] << "|" << tuple.aggregates[105] << "|" << tuple.aggregates[106] << "|" << tuple.aggregates[107] << "|" << tuple.aggregates[108] << "|" << tuple.aggregates[109] << "|" << tuple.aggregates[110] << "|" << tuple.aggregates[111] << "|" << tuple.aggregates[112] << "|" << tuple.aggregates[113] << "\n";
      }
      for (size_t i=0; i < V11.size(); ++i)
      {
         V11_tuple& tuple = V11[i];
         ofs  << tuple.holiday_type <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V12.size(); ++i)
      {
         V12_tuple& tuple = V12[i];
         ofs  << tuple.locale <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V13.size(); ++i)
      {
         V13_tuple& tuple = V13[i];
         ofs  << tuple.locale_id <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V14.size(); ++i)
      {
         V14_tuple& tuple = V14[i];
         ofs  << tuple.transferred <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V16.size(); ++i)
      {
         V16_tuple& tuple = V16[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "|" << tuple.aggregates[3] << "|" << tuple.aggregates[4] << "|" << tuple.aggregates[5] << "|" << tuple.aggregates[6] << "|" << tuple.aggregates[7] << "|" << tuple.aggregates[8] << "|" << tuple.aggregates[9] << "|" << tuple.aggregates[10] << "|" << tuple.aggregates[11] << "|" << tuple.aggregates[12] << "|" << tuple.aggregates[13] << "|" << tuple.aggregates[14] << "|" << tuple.aggregates[15] << "|" << tuple.aggregates[16] << "|" << tuple.aggregates[17] << "|" << tuple.aggregates[18] << "|" << tuple.aggregates[19] << "|" << tuple.aggregates[20] << "|" << tuple.aggregates[21] << "|" << tuple.aggregates[22] << "|" << tuple.aggregates[23] << "|" << tuple.aggregates[24] << "|" << tuple.aggregates[25] << "|" << tuple.aggregates[26] << "|" << tuple.aggregates[27] << "|" << tuple.aggregates[28] << "|" << tuple.aggregates[29] << "|" << tuple.aggregates[30] << "|" << tuple.aggregates[31] << "|" << tuple.aggregates[32] << "|" << tuple.aggregates[33] << "|" << tuple.aggregates[34] << "|" << tuple.aggregates[35] << "|" << tuple.aggregates[36] << "|" << tuple.aggregates[37] << "|" << tuple.aggregates[38] << "|" << tuple.aggregates[39] << "|" << tuple.aggregates[40] << "|" << tuple.aggregates[41] << "|" << tuple.aggregates[42] << "|" << tuple.aggregates[43] << "|" << tuple.aggregates[44] << "|" << tuple.aggregates[45] << "|" << tuple.aggregates[46] << "|" << tuple.aggregates[47] << "|" << tuple.aggregates[48] << "|" << tuple.aggregates[49] << "|" << tuple.aggregates[50] << "|" << tuple.aggregates[51] << "|" << tuple.aggregates[52] << "|" << tuple.aggregates[53] << "|" << tuple.aggregates[54] << "|" << tuple.aggregates[55] << "|" << tuple.aggregates[56] << "|" << tuple.aggregates[57] << "|" << tuple.aggregates[58] << "|" << tuple.aggregates[59] << "|" << tuple.aggregates[60] << "|" << tuple.aggregates[61] << "|" << tuple.aggregates[62] << "|" << tuple.aggregates[63] << "|" << tuple.aggregates[64] << "|" << tuple.aggregates[65] << "|" << tuple.aggregates[66] << "|" << tuple.aggregates[67] << "|" << tuple.aggregates[68] << "|" << tuple.aggregates[69] << "|" << tuple.aggregates[70] << "|" << tuple.aggregates[71] << "|" << tuple.aggregates[72] << "|" << tuple.aggregates[73] << "|" << tuple.aggregates[74] << "|" << tuple.aggregates[75] << "|" << tuple.aggregates[76] << "|" << tuple.aggregates[77] << "|" << tuple.aggregates[78] << "|" << tuple.aggregates[79] << "|" << tuple.aggregates[80] << "|" << tuple.aggregates[81] << "|" << tuple.aggregates[82] << "|" << tuple.aggregates[83] << "|" << tuple.aggregates[84] << "|" << tuple.aggregates[85] << "|" << tuple.aggregates[86] << "|" << tuple.aggregates[87] << "|" << tuple.aggregates[88] << "|" << tuple.aggregates[89] << "|" << tuple.aggregates[90] << "|" << tuple.aggregates[91] << "|" << tuple.aggregates[92] << "|" << tuple.aggregates[93] << "|" << tuple.aggregates[94] << "|" << tuple.aggregates[95] << "|" << tuple.aggregates[96] << "|" << tuple.aggregates[97] << "|" << tuple.aggregates[98] << "|" << tuple.aggregates[99] << "|" << tuple.aggregates[100] << "|" << tuple.aggregates[101] << "|" << tuple.aggregates[102] << "|" << tuple.aggregates[103] << "|" << tuple.aggregates[104] << "|" << tuple.aggregates[105] << "|" << tuple.aggregates[106] << "|" << tuple.aggregates[107] << "|" << tuple.aggregates[108] << "|" << tuple.aggregates[109] << "|" << tuple.aggregates[110] << "|" << tuple.aggregates[111] << "|" << tuple.aggregates[112] << "|" << tuple.aggregates[113] << "\n";
      }
      for (size_t i=0; i < V18.size(); ++i)
      {
         V18_tuple& tuple = V18[i];
         ofs  << tuple.city <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V19.size(); ++i)
      {
         V19_tuple& tuple = V19[i];
         ofs  << tuple.state <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V20.size(); ++i)
      {
         V20_tuple& tuple = V20[i];
         ofs  << tuple.store_type <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V21.size(); ++i)
      {
         V21_tuple& tuple = V21[i];
         ofs  << tuple.cluster <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V23.size(); ++i)
      {
         V23_tuple& tuple = V23[i];
         ofs  << tuple.family <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V24.size(); ++i)
      {
         V24_tuple& tuple = V24[i];
         ofs  << tuple.itemclass <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      for (size_t i=0; i < V25.size(); ++i)
      {
         V25_tuple& tuple = V25[i];
         ofs  << tuple.perishable <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
   }
#endif
#ifdef DUMP_OUTPUT
   void dumpOutputViews()
   {
      std::ofstream ofs;
      ofs.open("output/V5.tbl");
      ofs << "0 3\n";
      for (size_t i=0; i < V5.size(); ++i)
      {
         V5_tuple& tuple = V5[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V6.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V6.size(); ++i)
      {
         V6_tuple& tuple = V6[i];
         ofs  << tuple.store <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V7.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V7.size(); ++i)
      {
         V7_tuple& tuple = V7[i];
         ofs  << tuple.onpromotion <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V9.tbl");
      ofs << "0 114\n";
      for (size_t i=0; i < V9.size(); ++i)
      {
         V9_tuple& tuple = V9[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "|" << tuple.aggregates[3] << "|" << tuple.aggregates[4] << "|" << tuple.aggregates[5] << "|" << tuple.aggregates[6] << "|" << tuple.aggregates[7] << "|" << tuple.aggregates[8] << "|" << tuple.aggregates[9] << "|" << tuple.aggregates[10] << "|" << tuple.aggregates[11] << "|" << tuple.aggregates[12] << "|" << tuple.aggregates[13] << "|" << tuple.aggregates[14] << "|" << tuple.aggregates[15] << "|" << tuple.aggregates[16] << "|" << tuple.aggregates[17] << "|" << tuple.aggregates[18] << "|" << tuple.aggregates[19] << "|" << tuple.aggregates[20] << "|" << tuple.aggregates[21] << "|" << tuple.aggregates[22] << "|" << tuple.aggregates[23] << "|" << tuple.aggregates[24] << "|" << tuple.aggregates[25] << "|" << tuple.aggregates[26] << "|" << tuple.aggregates[27] << "|" << tuple.aggregates[28] << "|" << tuple.aggregates[29] << "|" << tuple.aggregates[30] << "|" << tuple.aggregates[31] << "|" << tuple.aggregates[32] << "|" << tuple.aggregates[33] << "|" << tuple.aggregates[34] << "|" << tuple.aggregates[35] << "|" << tuple.aggregates[36] << "|" << tuple.aggregates[37] << "|" << tuple.aggregates[38] << "|" << tuple.aggregates[39] << "|" << tuple.aggregates[40] << "|" << tuple.aggregates[41] << "|" << tuple.aggregates[42] << "|" << tuple.aggregates[43] << "|" << tuple.aggregates[44] << "|" << tuple.aggregates[45] << "|" << tuple.aggregates[46] << "|" << tuple.aggregates[47] << "|" << tuple.aggregates[48] << "|" << tuple.aggregates[49] << "|" << tuple.aggregates[50] << "|" << tuple.aggregates[51] << "|" << tuple.aggregates[52] << "|" << tuple.aggregates[53] << "|" << tuple.aggregates[54] << "|" << tuple.aggregates[55] << "|" << tuple.aggregates[56] << "|" << tuple.aggregates[57] << "|" << tuple.aggregates[58] << "|" << tuple.aggregates[59] << "|" << tuple.aggregates[60] << "|" << tuple.aggregates[61] << "|" << tuple.aggregates[62] << "|" << tuple.aggregates[63] << "|" << tuple.aggregates[64] << "|" << tuple.aggregates[65] << "|" << tuple.aggregates[66] << "|" << tuple.aggregates[67] << "|" << tuple.aggregates[68] << "|" << tuple.aggregates[69] << "|" << tuple.aggregates[70] << "|" << tuple.aggregates[71] << "|" << tuple.aggregates[72] << "|" << tuple.aggregates[73] << "|" << tuple.aggregates[74] << "|" << tuple.aggregates[75] << "|" << tuple.aggregates[76] << "|" << tuple.aggregates[77] << "|" << tuple.aggregates[78] << "|" << tuple.aggregates[79] << "|" << tuple.aggregates[80] << "|" << tuple.aggregates[81] << "|" << tuple.aggregates[82] << "|" << tuple.aggregates[83] << "|" << tuple.aggregates[84] << "|" << tuple.aggregates[85] << "|" << tuple.aggregates[86] << "|" << tuple.aggregates[87] << "|" << tuple.aggregates[88] << "|" << tuple.aggregates[89] << "|" << tuple.aggregates[90] << "|" << tuple.aggregates[91] << "|" << tuple.aggregates[92] << "|" << tuple.aggregates[93] << "|" << tuple.aggregates[94] << "|" << tuple.aggregates[95] << "|" << tuple.aggregates[96] << "|" << tuple.aggregates[97] << "|" << tuple.aggregates[98] << "|" << tuple.aggregates[99] << "|" << tuple.aggregates[100] << "|" << tuple.aggregates[101] << "|" << tuple.aggregates[102] << "|" << tuple.aggregates[103] << "|" << tuple.aggregates[104] << "|" << tuple.aggregates[105] << "|" << tuple.aggregates[106] << "|" << tuple.aggregates[107] << "|" << tuple.aggregates[108] << "|" << tuple.aggregates[109] << "|" << tuple.aggregates[110] << "|" << tuple.aggregates[111] << "|" << tuple.aggregates[112] << "|" << tuple.aggregates[113] << "\n";
      }
      ofs.close();
      ofs.open("output/V11.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V11.size(); ++i)
      {
         V11_tuple& tuple = V11[i];
         ofs  << tuple.holiday_type <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V12.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V12.size(); ++i)
      {
         V12_tuple& tuple = V12[i];
         ofs  << tuple.locale <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V13.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V13.size(); ++i)
      {
         V13_tuple& tuple = V13[i];
         ofs  << tuple.locale_id <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V14.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V14.size(); ++i)
      {
         V14_tuple& tuple = V14[i];
         ofs  << tuple.transferred <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V16.tbl");
      ofs << "0 114\n";
      for (size_t i=0; i < V16.size(); ++i)
      {
         V16_tuple& tuple = V16[i];
         ofs  << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "|" << tuple.aggregates[3] << "|" << tuple.aggregates[4] << "|" << tuple.aggregates[5] << "|" << tuple.aggregates[6] << "|" << tuple.aggregates[7] << "|" << tuple.aggregates[8] << "|" << tuple.aggregates[9] << "|" << tuple.aggregates[10] << "|" << tuple.aggregates[11] << "|" << tuple.aggregates[12] << "|" << tuple.aggregates[13] << "|" << tuple.aggregates[14] << "|" << tuple.aggregates[15] << "|" << tuple.aggregates[16] << "|" << tuple.aggregates[17] << "|" << tuple.aggregates[18] << "|" << tuple.aggregates[19] << "|" << tuple.aggregates[20] << "|" << tuple.aggregates[21] << "|" << tuple.aggregates[22] << "|" << tuple.aggregates[23] << "|" << tuple.aggregates[24] << "|" << tuple.aggregates[25] << "|" << tuple.aggregates[26] << "|" << tuple.aggregates[27] << "|" << tuple.aggregates[28] << "|" << tuple.aggregates[29] << "|" << tuple.aggregates[30] << "|" << tuple.aggregates[31] << "|" << tuple.aggregates[32] << "|" << tuple.aggregates[33] << "|" << tuple.aggregates[34] << "|" << tuple.aggregates[35] << "|" << tuple.aggregates[36] << "|" << tuple.aggregates[37] << "|" << tuple.aggregates[38] << "|" << tuple.aggregates[39] << "|" << tuple.aggregates[40] << "|" << tuple.aggregates[41] << "|" << tuple.aggregates[42] << "|" << tuple.aggregates[43] << "|" << tuple.aggregates[44] << "|" << tuple.aggregates[45] << "|" << tuple.aggregates[46] << "|" << tuple.aggregates[47] << "|" << tuple.aggregates[48] << "|" << tuple.aggregates[49] << "|" << tuple.aggregates[50] << "|" << tuple.aggregates[51] << "|" << tuple.aggregates[52] << "|" << tuple.aggregates[53] << "|" << tuple.aggregates[54] << "|" << tuple.aggregates[55] << "|" << tuple.aggregates[56] << "|" << tuple.aggregates[57] << "|" << tuple.aggregates[58] << "|" << tuple.aggregates[59] << "|" << tuple.aggregates[60] << "|" << tuple.aggregates[61] << "|" << tuple.aggregates[62] << "|" << tuple.aggregates[63] << "|" << tuple.aggregates[64] << "|" << tuple.aggregates[65] << "|" << tuple.aggregates[66] << "|" << tuple.aggregates[67] << "|" << tuple.aggregates[68] << "|" << tuple.aggregates[69] << "|" << tuple.aggregates[70] << "|" << tuple.aggregates[71] << "|" << tuple.aggregates[72] << "|" << tuple.aggregates[73] << "|" << tuple.aggregates[74] << "|" << tuple.aggregates[75] << "|" << tuple.aggregates[76] << "|" << tuple.aggregates[77] << "|" << tuple.aggregates[78] << "|" << tuple.aggregates[79] << "|" << tuple.aggregates[80] << "|" << tuple.aggregates[81] << "|" << tuple.aggregates[82] << "|" << tuple.aggregates[83] << "|" << tuple.aggregates[84] << "|" << tuple.aggregates[85] << "|" << tuple.aggregates[86] << "|" << tuple.aggregates[87] << "|" << tuple.aggregates[88] << "|" << tuple.aggregates[89] << "|" << tuple.aggregates[90] << "|" << tuple.aggregates[91] << "|" << tuple.aggregates[92] << "|" << tuple.aggregates[93] << "|" << tuple.aggregates[94] << "|" << tuple.aggregates[95] << "|" << tuple.aggregates[96] << "|" << tuple.aggregates[97] << "|" << tuple.aggregates[98] << "|" << tuple.aggregates[99] << "|" << tuple.aggregates[100] << "|" << tuple.aggregates[101] << "|" << tuple.aggregates[102] << "|" << tuple.aggregates[103] << "|" << tuple.aggregates[104] << "|" << tuple.aggregates[105] << "|" << tuple.aggregates[106] << "|" << tuple.aggregates[107] << "|" << tuple.aggregates[108] << "|" << tuple.aggregates[109] << "|" << tuple.aggregates[110] << "|" << tuple.aggregates[111] << "|" << tuple.aggregates[112] << "|" << tuple.aggregates[113] << "\n";
      }
      ofs.close();
      ofs.open("output/V18.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V18.size(); ++i)
      {
         V18_tuple& tuple = V18[i];
         ofs  << tuple.city <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V19.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V19.size(); ++i)
      {
         V19_tuple& tuple = V19[i];
         ofs  << tuple.state <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V20.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V20.size(); ++i)
      {
         V20_tuple& tuple = V20[i];
         ofs  << tuple.store_type <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V21.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V21.size(); ++i)
      {
         V21_tuple& tuple = V21[i];
         ofs  << tuple.cluster <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V23.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V23.size(); ++i)
      {
         V23_tuple& tuple = V23[i];
         ofs  << tuple.family <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V24.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V24.size(); ++i)
      {
         V24_tuple& tuple = V24[i];
         ofs  << tuple.itemclass <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
      }
      ofs.close();
      ofs.open("output/V25.tbl");
      ofs << "1 3\n";
      for (size_t i=0; i < V25.size(); ++i)
      {
         V25_tuple& tuple = V25[i];
         ofs  << tuple.perishable <<"|" << tuple.aggregates[0] << "|" << tuple.aggregates[1] << "|" << tuple.aggregates[2] << "\n";
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
