CREATE TABLE joinres AS (SELECT date,store,item,unit_sales,onpromotion,oilprize,holiday_type,locale,locale_id,transferred,transactions,city,state,store_type,cluster,family,itemclass,perishable
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);
