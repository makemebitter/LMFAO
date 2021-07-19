#include "DataHandler.h"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

namespace qi = boost::spirit::qi;
namespace phoenix = boost::phoenix;

namespace lmfao
{
   Sales_tuple::Sales_tuple(const std::string& tuple)
   {
      qi::phrase_parse(tuple.begin(),tuple.end(),
         qi::int_[phoenix::ref(date) = qi::_1]>>
         qi::int_[phoenix::ref(store) = qi::_1]>>
         qi::int_[phoenix::ref(item) = qi::_1]>>
         qi::double_[phoenix::ref(unit_sales) = qi::_1]>>
         qi::int_[phoenix::ref(onpromotion) = qi::_1],
         '|');
   }

   Oil_tuple::Oil_tuple(const std::string& tuple)
   {
      qi::phrase_parse(tuple.begin(),tuple.end(),
         qi::int_[phoenix::ref(date) = qi::_1]>>
         qi::double_[phoenix::ref(oilprize) = qi::_1],
         '|');
   }

   Holiday_tuple::Holiday_tuple(const std::string& tuple)
   {
      qi::phrase_parse(tuple.begin(),tuple.end(),
         qi::int_[phoenix::ref(date) = qi::_1]>>
         qi::int_[phoenix::ref(holiday_type) = qi::_1]>>
         qi::int_[phoenix::ref(locale) = qi::_1]>>
         qi::int_[phoenix::ref(locale_id) = qi::_1]>>
         qi::int_[phoenix::ref(transferred) = qi::_1],
         '|');
   }

   Transactions_tuple::Transactions_tuple(const std::string& tuple)
   {
      qi::phrase_parse(tuple.begin(),tuple.end(),
         qi::int_[phoenix::ref(date) = qi::_1]>>
         qi::int_[phoenix::ref(store) = qi::_1]>>
         qi::int_[phoenix::ref(transactions) = qi::_1],
         '|');
   }

   Stores_tuple::Stores_tuple(const std::string& tuple)
   {
      qi::phrase_parse(tuple.begin(),tuple.end(),
         qi::int_[phoenix::ref(store) = qi::_1]>>
         qi::int_[phoenix::ref(city) = qi::_1]>>
         qi::int_[phoenix::ref(state) = qi::_1]>>
         qi::int_[phoenix::ref(store_type) = qi::_1]>>
         qi::int_[phoenix::ref(cluster) = qi::_1],
         '|');
   }

   Items_tuple::Items_tuple(const std::string& tuple)
   {
      qi::phrase_parse(tuple.begin(),tuple.end(),
         qi::int_[phoenix::ref(item) = qi::_1]>>
         qi::int_[phoenix::ref(family) = qi::_1]>>
         qi::int_[phoenix::ref(itemclass) = qi::_1]>>
         qi::int_[phoenix::ref(perishable) = qi::_1],
         '|');
   }

   V0_tuple::V0_tuple(const int& date) : date(date){}

   V1_tuple::V1_tuple(const int& date) : date(date){}

   V2_tuple::V2_tuple(const int& date,const int& store) : date(date),store(store){}

   V3_tuple::V3_tuple(const int& store) : store(store){}

   V4_tuple::V4_tuple(const int& item) : item(item){}

   V5_tuple::V5_tuple(){}

   V6_tuple::V6_tuple(const int& store) : store(store){}

   V7_tuple::V7_tuple(const int& onpromotion) : onpromotion(onpromotion){}

   V8_tuple::V8_tuple(const int& date) : date(date){}

   V9_tuple::V9_tuple(){}

   V10_tuple::V10_tuple(const int& date) : date(date){}

   V11_tuple::V11_tuple(const int& holiday_type) : holiday_type(holiday_type){}

   V12_tuple::V12_tuple(const int& locale) : locale(locale){}

   V13_tuple::V13_tuple(const int& locale_id) : locale_id(locale_id){}

   V14_tuple::V14_tuple(const int& transferred) : transferred(transferred){}

   V15_tuple::V15_tuple(const int& date,const int& store) : date(date),store(store){}

   V16_tuple::V16_tuple(){}

   V17_tuple::V17_tuple(const int& store) : store(store){}

   V18_tuple::V18_tuple(const int& city) : city(city){}

   V19_tuple::V19_tuple(const int& state) : state(state){}

   V20_tuple::V20_tuple(const int& store_type) : store_type(store_type){}

   V21_tuple::V21_tuple(const int& cluster) : cluster(cluster){}

   V22_tuple::V22_tuple(const int& item) : item(item){}

   V23_tuple::V23_tuple(const int& family) : family(family){}

   V24_tuple::V24_tuple(const int& itemclass) : itemclass(itemclass){}

   V25_tuple::V25_tuple(const int& perishable) : perishable(perishable){}

}

