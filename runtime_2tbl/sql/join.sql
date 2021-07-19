CREATE TABLE joinres AS (SELECT date,store,item,unit_sales,onpromotion,oilprize
FROM Sales NATURAL JOIN Oil);
