#ifndef INCLUDE_DYNAMICFUNCTIONS_H_
#define INCLUDE_DYNAMICFUNCTIONS_H_

namespace lmfao
{
   double f_Sales(int date,int store,int item,double unit_sales,int onpromotion);

   double f_Oil(int date,double oilprize);

   double f_Holiday(int date,int holiday_type,int locale,int locale_id,int transferred);

   double f_Transactions(int date,int store,int transactions);

   double f_Stores(int store,int city,int state,int store_type,int cluster);

   double f_Items(int item,int family,int itemclass,int perishable);

}

#endif /* INCLUDE_DYNAMICFUNCTIONS_H_*/
