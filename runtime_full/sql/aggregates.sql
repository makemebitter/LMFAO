CREATE TABLE agg_0 AS (
SELECT SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_1 AS (
SELECT store,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY store);

CREATE TABLE agg_2 AS (
SELECT onpromotion,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY onpromotion);

CREATE TABLE agg_3 AS (
SELECT SUM(CASE WHEN oilprize <= 35.360000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 35.360000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 35.360000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 35.360000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 35.360000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 35.360000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_4 AS (
SELECT SUM(CASE WHEN oilprize <= 40.050000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 40.050000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 40.050000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 40.050000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 40.050000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 40.050000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_5 AS (
SELECT SUM(CASE WHEN oilprize <= 43.040000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 43.040000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 43.040000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 43.040000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 43.040000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 43.040000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_6 AS (
SELECT SUM(CASE WHEN oilprize <= 44.470000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 44.470000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 44.470000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 44.470000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 44.470000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 44.470000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_7 AS (
SELECT SUM(CASE WHEN oilprize <= 45.470000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 45.470000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 45.470000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 45.470000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 45.470000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 45.470000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_8 AS (
SELECT SUM(CASE WHEN oilprize <= 46.120000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 46.120000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 46.120000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 46.120000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 46.120000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 46.120000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_9 AS (
SELECT SUM(CASE WHEN oilprize <= 47.170000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 47.170000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 47.170000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 47.170000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 47.170000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 47.170000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_10 AS (
SELECT SUM(CASE WHEN oilprize <= 48.130000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 48.130000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 48.130000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 48.130000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 48.130000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 48.130000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_11 AS (
SELECT SUM(CASE WHEN oilprize <= 49.070000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 49.070000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 49.070000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 49.070000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 49.070000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 49.070000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_12 AS (
SELECT SUM(CASE WHEN oilprize <= 49.850000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 49.850000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 49.850000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 49.850000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 49.850000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 49.850000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_13 AS (
SELECT SUM(CASE WHEN oilprize <= 51.610000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 51.610000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 51.610000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 51.610000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 51.610000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 51.610000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_14 AS (
SELECT SUM(CASE WHEN oilprize <= 53.010000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 53.010000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 53.010000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 53.010000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 53.010000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 53.010000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_15 AS (
SELECT SUM(CASE WHEN oilprize <= 54.590000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 54.590000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 54.590000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 54.590000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 54.590000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 54.590000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_16 AS (
SELECT SUM(CASE WHEN oilprize <= 60.250000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 60.250000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 60.250000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 60.250000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 60.250000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 60.250000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_17 AS (
SELECT SUM(CASE WHEN oilprize <= 90.880000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 90.880000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 90.880000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 90.880000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 90.880000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 90.880000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_18 AS (
SELECT SUM(CASE WHEN oilprize <= 93.840000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 93.840000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 93.840000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 93.840000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 93.840000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 93.840000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_19 AS (
SELECT SUM(CASE WHEN oilprize <= 97.030000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 97.030000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 97.030000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 97.030000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 97.030000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 97.030000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_20 AS (
SELECT SUM(CASE WHEN oilprize <= 100.520000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 100.520000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 100.520000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 100.520000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 100.520000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 100.520000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_21 AS (
SELECT SUM(CASE WHEN oilprize <= 104.060000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN oilprize <= 104.060000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN oilprize <= 104.060000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN oilprize > 104.060000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN oilprize > 104.060000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN oilprize > 104.060000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_22 AS (
SELECT holiday_type,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY holiday_type);

CREATE TABLE agg_23 AS (
SELECT locale,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY locale);

CREATE TABLE agg_24 AS (
SELECT locale_id,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY locale_id);

CREATE TABLE agg_25 AS (
SELECT transferred,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY transferred);

CREATE TABLE agg_26 AS (
SELECT SUM(CASE WHEN transactions <= 711.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 711.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 711.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 711.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 711.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 711.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_27 AS (
SELECT SUM(CASE WHEN transactions <= 856.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 856.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 856.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 856.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 856.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 856.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_28 AS (
SELECT SUM(CASE WHEN transactions <= 973.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 973.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 973.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 973.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 973.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 973.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_29 AS (
SELECT SUM(CASE WHEN transactions <= 1070.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1070.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1070.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1070.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1070.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1070.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_30 AS (
SELECT SUM(CASE WHEN transactions <= 1157.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1157.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1157.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1157.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1157.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1157.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_31 AS (
SELECT SUM(CASE WHEN transactions <= 1235.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1235.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1235.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1235.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1235.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1235.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_32 AS (
SELECT SUM(CASE WHEN transactions <= 1304.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1304.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1304.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1304.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1304.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1304.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_33 AS (
SELECT SUM(CASE WHEN transactions <= 1373.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1373.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1373.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1373.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1373.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1373.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_34 AS (
SELECT SUM(CASE WHEN transactions <= 1453.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1453.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1453.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1453.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1453.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1453.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_35 AS (
SELECT SUM(CASE WHEN transactions <= 1554.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1554.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1554.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1554.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1554.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1554.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_36 AS (
SELECT SUM(CASE WHEN transactions <= 1681.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1681.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1681.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1681.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1681.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1681.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_37 AS (
SELECT SUM(CASE WHEN transactions <= 1804.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1804.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1804.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1804.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1804.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1804.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_38 AS (
SELECT SUM(CASE WHEN transactions <= 1945.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 1945.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 1945.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 1945.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 1945.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 1945.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_39 AS (
SELECT SUM(CASE WHEN transactions <= 2151.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 2151.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 2151.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 2151.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 2151.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 2151.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_40 AS (
SELECT SUM(CASE WHEN transactions <= 2390.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 2390.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 2390.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 2390.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 2390.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 2390.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_41 AS (
SELECT SUM(CASE WHEN transactions <= 2679.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 2679.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 2679.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 2679.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 2679.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 2679.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_42 AS (
SELECT SUM(CASE WHEN transactions <= 2997.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 2997.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 2997.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 2997.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 2997.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 2997.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_43 AS (
SELECT SUM(CASE WHEN transactions <= 3408.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 3408.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 3408.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 3408.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 3408.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 3408.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_44 AS (
SELECT SUM(CASE WHEN transactions <= 4070.000000 THEN 1.0 ELSE 0.0 END) AS agg_0,SUM(unit_sales*CASE WHEN transactions <= 4070.000000 THEN 1.0 ELSE 0.0 END) AS agg_1,SUM(unit_sales*unit_sales*CASE WHEN transactions <= 4070.000000 THEN 1.0 ELSE 0.0 END) AS agg_2,SUM(CASE WHEN transactions > 4070.000000 THEN 1.0 ELSE 0.0 END) AS agg_3,SUM(unit_sales*CASE WHEN transactions > 4070.000000 THEN 1.0 ELSE 0.0 END) AS agg_4,SUM(unit_sales*unit_sales*CASE WHEN transactions > 4070.000000 THEN 1.0 ELSE 0.0 END) AS agg_5
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items);

CREATE TABLE agg_45 AS (
SELECT city,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY city);

CREATE TABLE agg_46 AS (
SELECT state,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY state);

CREATE TABLE agg_47 AS (
SELECT store_type,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY store_type);

CREATE TABLE agg_48 AS (
SELECT cluster,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY cluster);

CREATE TABLE agg_49 AS (
SELECT family,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY family);

CREATE TABLE agg_50 AS (
SELECT itemclass,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY itemclass);

CREATE TABLE agg_51 AS (
SELECT perishable,SUM(1) AS agg_0,SUM(unit_sales) AS agg_1,SUM(unit_sales*unit_sales) AS agg_2
FROM Sales NATURAL JOIN Oil NATURAL JOIN Holiday NATURAL JOIN Transactions NATURAL JOIN Stores NATURAL JOIN Items
GROUP BY perishable);

