#ifndef INCLUDE_DATAHANDLER_HPP_
#define INCLUDE_DATAHANDLER_HPP_

#include <algorithm>
#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std::chrono;

namespace lmfao
{
   const std::string PATH_TO_DATA = "/Users/yuhao/LMFAO/data/favorita-small";

   struct Sales_tuple
   {
      int date;
      int store;
      int item;
      double unit_sales;
      int onpromotion;
      Sales_tuple(const std::string& tuple);
   };

   extern std::vector<Sales_tuple> Sales;

   struct Oil_tuple
   {
      int date;
      double oilprize;
      Oil_tuple(const std::string& tuple);
   };

   extern std::vector<Oil_tuple> Oil;

   struct Holiday_tuple
   {
      int date;
      int holiday_type;
      int locale;
      int locale_id;
      int transferred;
      Holiday_tuple(const std::string& tuple);
   };

   extern std::vector<Holiday_tuple> Holiday;

   struct Transactions_tuple
   {
      int date;
      int store;
      int transactions;
      Transactions_tuple(const std::string& tuple);
   };

   extern std::vector<Transactions_tuple> Transactions;

   struct Stores_tuple
   {
      int store;
      int city;
      int state;
      int store_type;
      int cluster;
      Stores_tuple(const std::string& tuple);
   };

   extern std::vector<Stores_tuple> Stores;

   struct Items_tuple
   {
      int item;
      int family;
      int itemclass;
      int perishable;
      Items_tuple(const std::string& tuple);
   };

   extern std::vector<Items_tuple> Items;

   struct V0_tuple
   {
      int date;
      double aggregates[1] = {};
      V0_tuple(const int& date);
   };

   extern std::vector<V0_tuple> V0;

   struct V1_tuple
   {
      int date;
      double aggregates[1] = {};
      V1_tuple(const int& date);
   };

   extern std::vector<V1_tuple> V1;

   struct V2_tuple
   {
      int date;
      int store;
      double aggregates[1] = {};
      V2_tuple(const int& date,const int& store);
   };

   extern std::vector<V2_tuple> V2;

   struct V3_tuple
   {
      int store;
      double aggregates[1] = {};
      V3_tuple(const int& store);
   };

   extern std::vector<V3_tuple> V3;

   struct V4_tuple
   {
      int item;
      double aggregates[1] = {};
      V4_tuple(const int& item);
   };

   extern std::vector<V4_tuple> V4;

   struct V5_tuple
   {
      double aggregates[3] = {};
      V5_tuple();
   };

   extern std::vector<V5_tuple> V5;

   struct V6_tuple
   {
      int store;
      double aggregates[3] = {};
      V6_tuple(const int& store);
   };

   extern std::vector<V6_tuple> V6;

   struct V7_tuple
   {
      int onpromotion;
      double aggregates[3] = {};
      V7_tuple(const int& onpromotion);
   };

   extern std::vector<V7_tuple> V7;

   struct V8_tuple
   {
      int date;
      double aggregates[3] = {};
      V8_tuple(const int& date);
   };

   extern std::vector<V8_tuple> V8;

   struct V9_tuple
   {
      double aggregates[114] = {};
      V9_tuple();
   };

   extern std::vector<V9_tuple> V9;

   struct V10_tuple
   {
      int date;
      double aggregates[3] = {};
      V10_tuple(const int& date);
   };

   extern std::vector<V10_tuple> V10;

   struct V11_tuple
   {
      int holiday_type;
      double aggregates[3] = {};
      V11_tuple(const int& holiday_type);
   };

   extern std::vector<V11_tuple> V11;

   struct V12_tuple
   {
      int locale;
      double aggregates[3] = {};
      V12_tuple(const int& locale);
   };

   extern std::vector<V12_tuple> V12;

   struct V13_tuple
   {
      int locale_id;
      double aggregates[3] = {};
      V13_tuple(const int& locale_id);
   };

   extern std::vector<V13_tuple> V13;

   struct V14_tuple
   {
      int transferred;
      double aggregates[3] = {};
      V14_tuple(const int& transferred);
   };

   extern std::vector<V14_tuple> V14;

   struct V15_tuple
   {
      int date;
      int store;
      double aggregates[3] = {};
      V15_tuple(const int& date,const int& store);
   };

   extern std::vector<V15_tuple> V15;

   struct V16_tuple
   {
      double aggregates[114] = {};
      V16_tuple();
   };

   extern std::vector<V16_tuple> V16;

   struct V17_tuple
   {
      int store;
      double aggregates[3] = {};
      V17_tuple(const int& store);
   };

   extern std::vector<V17_tuple> V17;

   struct V18_tuple
   {
      int city;
      double aggregates[3] = {};
      V18_tuple(const int& city);
   };

   extern std::vector<V18_tuple> V18;

   struct V19_tuple
   {
      int state;
      double aggregates[3] = {};
      V19_tuple(const int& state);
   };

   extern std::vector<V19_tuple> V19;

   struct V20_tuple
   {
      int store_type;
      double aggregates[3] = {};
      V20_tuple(const int& store_type);
   };

   extern std::vector<V20_tuple> V20;

   struct V21_tuple
   {
      int cluster;
      double aggregates[3] = {};
      V21_tuple(const int& cluster);
   };

   extern std::vector<V21_tuple> V21;

   struct V22_tuple
   {
      int item;
      double aggregates[3] = {};
      V22_tuple(const int& item);
   };

   extern std::vector<V22_tuple> V22;

   struct V23_tuple
   {
      int family;
      double aggregates[3] = {};
      V23_tuple(const int& family);
   };

   extern std::vector<V23_tuple> V23;

   struct V24_tuple
   {
      int itemclass;
      double aggregates[3] = {};
      V24_tuple(const int& itemclass);
   };

   extern std::vector<V24_tuple> V24;

   struct V25_tuple
   {
      int perishable;
      double aggregates[3] = {};
      V25_tuple(const int& perishable);
   };

   extern std::vector<V25_tuple> V25;

   enum ID {
      Sales_ID,
      Oil_ID,
      Holiday_ID,
      Transactions_ID,
      Stores_ID,
      Items_ID,
      V0_ID,
      V1_ID,
      V2_ID,
      V3_ID,
      V4_ID,
      V5_ID,
      V6_ID,
      V7_ID,
      V8_ID,
      V9_ID,
      V10_ID,
      V11_ID,
      V12_ID,
      V13_ID,
      V14_ID,
      V15_ID,
      V16_ID,
      V17_ID,
      V18_ID,
      V19_ID,
      V20_ID,
      V21_ID,
      V22_ID,
      V23_ID,
      V24_ID,
      V25_ID
   };

   extern void sortSales();
   extern void sortOil();
   extern void sortHoliday();
   extern void sortTransactions();
   extern void sortStores();
   extern void sortItems();
}

#endif /* INCLUDE_DATAHANDLER_HPP_*/
