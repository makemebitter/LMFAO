#include <fstream>
#include <vector>
#include "RegressionTreeNode.hpp"

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

namespace qi = boost::spirit::qi;
namespace phoenix = boost::phoenix;


struct Test_tuple
{
   int date;
   int store;
   int item;
   double unit_sales;
   int onpromotion;
   double oilprize;
   int holiday_type;
   int locale;
   int locale_id;
   int transferred;
   int transactions;
   int city;
   int state;
   int store_type;
   int cluster;
   int family;
   int itemclass;
   int perishable;
   Test_tuple(const std::string& tuple)
   {
         qi::phrase_parse(tuple.begin(),tuple.end(),
            qi::int_[phoenix::ref(date) = qi::_1]>>
            qi::int_[phoenix::ref(store) = qi::_1]>>
            qi::int_[phoenix::ref(item) = qi::_1]>>
            qi::double_[phoenix::ref(unit_sales) = qi::_1]>>
            qi::int_[phoenix::ref(onpromotion) = qi::_1]>>
            qi::double_[phoenix::ref(oilprize) = qi::_1]>>
            qi::int_[phoenix::ref(holiday_type) = qi::_1]>>
            qi::int_[phoenix::ref(locale) = qi::_1]>>
            qi::int_[phoenix::ref(locale_id) = qi::_1]>>
            qi::int_[phoenix::ref(transferred) = qi::_1]>>
            qi::int_[phoenix::ref(transactions) = qi::_1]>>
            qi::int_[phoenix::ref(city) = qi::_1]>>
            qi::int_[phoenix::ref(state) = qi::_1]>>
            qi::int_[phoenix::ref(store_type) = qi::_1]>>
            qi::int_[phoenix::ref(cluster) = qi::_1]>>
            qi::int_[phoenix::ref(family) = qi::_1]>>
            qi::int_[phoenix::ref(itemclass) = qi::_1]>>
            qi::int_[phoenix::ref(perishable) = qi::_1],
            '|');
   }
};

void loadTestDataset(std::vector<Test_tuple>& TestDataset)
{
   std::ifstream input;
   std::string line;
   input.open("/Users/yuhao/LMFAO/data/favorita-small/test_data.tbl");
   if (!input)
   {
      std::cerr << "TestDataset.tbl does is not exist.\n";
      exit(1);
   }
   while(getline(input, line))
      TestDataset.push_back(Test_tuple(line));
   input.close();
}

double findPrediction(const RegTreeNode* node, const Test_tuple& tuple)
{
   if (node->isLeaf)
      return node->prediction;

   bool goLeft = true;
   const Condition& c = node->condition;
   switch (c.variable)
   {
         case 0 : goLeft = (tuple.date <= c.threshold); break;
         case 1 : goLeft = (tuple.store == c.threshold); break;
         case 2 : goLeft = (tuple.item <= c.threshold); break;
         case 3 : goLeft = (tuple.unit_sales <= c.threshold); break;
         case 4 : goLeft = (tuple.onpromotion == c.threshold); break;
         case 5 : goLeft = (tuple.oilprize <= c.threshold); break;
         case 6 : goLeft = (tuple.holiday_type == c.threshold); break;
         case 7 : goLeft = (tuple.locale == c.threshold); break;
         case 8 : goLeft = (tuple.locale_id == c.threshold); break;
         case 9 : goLeft = (tuple.transferred == c.threshold); break;
         case 10 : goLeft = (tuple.transactions <= c.threshold); break;
         case 11 : goLeft = (tuple.city == c.threshold); break;
         case 12 : goLeft = (tuple.state == c.threshold); break;
         case 13 : goLeft = (tuple.store_type == c.threshold); break;
         case 14 : goLeft = (tuple.cluster == c.threshold); break;
         case 15 : goLeft = (tuple.family == c.threshold); break;
         case 16 : goLeft = (tuple.itemclass == c.threshold); break;
         case 17 : goLeft = (tuple.perishable == c.threshold); break;
   }
   if (goLeft)
      return findPrediction(node->lchild, tuple);
   else
      return findPrediction(node->rchild, tuple);
}

void evaluateModel(const RegTreeNode* root)
{
   std::vector<Test_tuple> TestDataset;
   loadTestDataset(TestDataset);
   double pred, diff, error = 0.0;
   for (const Test_tuple& tuple : TestDataset)
      {
      pred = findPrediction(root, tuple);
      diff = tuple.unit_sales-pred;
      error += diff * diff;
   }
   error /= TestDataset.size();
   std::cout << "RMSE: " << sqrt(error) << std::endl;
}

void generateDynamicFunctions(std::vector<Condition>& conditions)
{
   std::string variableMap[] = {"date","store","item","unit_sales","onpromotion","oilprize","holiday_type","locale","locale_id","transferred","transactions","city","state","store_type","cluster","family","itemclass","perishable"};
   std::string variableList[] = {"int date,int store,int item,double unit_sales,int onpromotion","int date,double oilprize","int date,int holiday_type,int locale,int locale_id,int transferred","int date,int store,int transactions","int store,int city,int state,int store_type,int cluster","int item,int family,int itemclass,int perishable"};
   size_t relationMap[] = {0,0,0,0,0,1,2,2,2,2,3,4,4,4,4,5,5,5};
   std::string relationName[] = {"Sales","Oil","Holiday","Transactions","Stores","Items"};
   std::string conditionStr[] = {"","","","","",""};
   for (Condition& c : conditions)
      conditionStr[relationMap[c.variable]] += variableMap[c.variable] + c.op + std::to_string(c.threshold) + "&&";
   std::ofstream ofs("DynamicFunctions.cpp", std::ofstream::out);
   ofs << "#include \"DynamicFunctions.h\"\nnamespace lmfao\n{\n";
   for (size_t rel = 0; rel < 6; ++rel)
   {
      if (!conditionStr[rel].empty())
      {
         conditionStr[rel].pop_back();
         conditionStr[rel].pop_back();
         ofs << "double f_"+relationName[rel]+"("+variableList[rel]+")\n{\n	return ("+conditionStr[rel]+" ? 1.0 : 0.0);\n}\n";
      }
      else
      {
         ofs << "double f_"+relationName[rel]+"("+variableList[rel]+")\n{\n\treturn 1.0;\n}\n";
      }
   }
   ofs << "}\n";
   ofs.close();
}
