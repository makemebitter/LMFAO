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

   V0_tuple::V0_tuple(const int& date) : date(date){}

   V1_tuple::V1_tuple(){}

   V2_tuple::V2_tuple(const int& store) : store(store){}

   V3_tuple::V3_tuple(const int& onpromotion) : onpromotion(onpromotion){}

   V4_tuple::V4_tuple(const int& date) : date(date){}

   V5_tuple::V5_tuple(){}

}

