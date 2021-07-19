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
   const std::string PATH_TO_DATA = "/Users/yuhao/LMFAO/data/favorita-small-2tbl";

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

   struct V0_tuple
   {
      int date;
      double aggregates[1] = {};
      V0_tuple(const int& date);
   };

   extern std::vector<V0_tuple> V0;

   struct V1_tuple
   {
      double aggregates[3] = {};
      V1_tuple();
   };

   extern std::vector<V1_tuple> V1;

   struct V2_tuple
   {
      int store;
      double aggregates[3] = {};
      V2_tuple(const int& store);
   };

   extern std::vector<V2_tuple> V2;

   struct V3_tuple
   {
      int onpromotion;
      double aggregates[3] = {};
      V3_tuple(const int& onpromotion);
   };

   extern std::vector<V3_tuple> V3;

   struct V4_tuple
   {
      int date;
      double aggregates[3] = {};
      V4_tuple(const int& date);
   };

   extern std::vector<V4_tuple> V4;

   struct V5_tuple
   {
      double aggregates[114] = {};
      V5_tuple();
   };

   extern std::vector<V5_tuple> V5;

   enum ID {
      Sales_ID,
      Oil_ID,
      V0_ID,
      V1_ID,
      V2_ID,
      V3_ID,
      V4_ID,
      V5_ID
   };

   extern void sortSales();
   extern void sortOil();
}

#endif /* INCLUDE_DATAHANDLER_HPP_*/
