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
   Test_tuple(const std::string& tuple)
   {
         qi::phrase_parse(tuple.begin(),tuple.end(),
            qi::int_[phoenix::ref(date) = qi::_1]>>
            qi::int_[phoenix::ref(store) = qi::_1]>>
            qi::int_[phoenix::ref(item) = qi::_1]>>
            qi::double_[phoenix::ref(unit_sales) = qi::_1]>>
            qi::int_[phoenix::ref(onpromotion) = qi::_1]>>
            qi::double_[phoenix::ref(oilprize) = qi::_1],
            '|');
   }
};

void loadTestDataset(std::vector<Test_tuple>& TestDataset)
{
   std::ifstream input;
   std::string line;
   input.open("/Users/yuhao/LMFAO/data/favorita-small-2tbl/test_data.tbl");
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
   std::string variableMap[] = {"date","store","item","unit_sales","onpromotion","oilprize"};
   std::string variableList[] = {"int date,int store,int item,double unit_sales,int onpromotion","int date,double oilprize"};
   size_t relationMap[] = {0,0,0,0,0,1};
   std::string relationName[] = {"Sales","Oil"};
   std::string conditionStr[] = {"",""};
   for (Condition& c : conditions)
      conditionStr[relationMap[c.variable]] += variableMap[c.variable] + c.op + std::to_string(c.threshold) + "&&";
   std::ofstream ofs("DynamicFunctions.cpp", std::ofstream::out);
   ofs << "#include \"DynamicFunctions.h\"\nnamespace lmfao\n{\n";
   for (size_t rel = 0; rel < 2; ++rel)
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
