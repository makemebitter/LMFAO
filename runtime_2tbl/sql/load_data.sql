DROP TABLE IF EXISTS Sales;
DROP TABLE IF EXISTS Oil;
CREATE TABLE Sales(date int,store int,item int,unit_sales numeric,onpromotion int);
\COPY Sales FROM '/Users/yuhao/LMFAO/data/favorita-small-2tbl/Sales.tbl' DELIMITER '|' CSV;
CREATE TABLE Oil(date int,oilprize numeric);
\COPY Oil FROM '/Users/yuhao/LMFAO/data/favorita-small-2tbl/Oil.tbl' DELIMITER '|' CSV;
