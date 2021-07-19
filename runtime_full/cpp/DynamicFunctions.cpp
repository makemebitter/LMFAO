#include "DynamicFunctions.h"
namespace lmfao
{
   double f_Sales(int date,int store,int item,double unit_sales,int onpromotion)
   {
      return 1.0;
   }
   double f_Oil(int date,double oilprize)
   {
      return 1.0;
   }
   double f_Holiday(int date,int holiday_type,int locale,int locale_id,int transferred)
   {
      return 1.0;
   }
   double f_Transactions(int date,int store,int transactions)
   {
      return 1.0;
   }
   double f_Stores(int store,int city,int state,int store_type,int cluster)
   {
      return 1.0;
   }
   double f_Items(int item,int family,int itemclass,int perishable)
   {
      return 1.0;
   }
}
