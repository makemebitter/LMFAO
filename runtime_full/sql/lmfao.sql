CREATE TABLE view_0 AS
SELECT date,
SUM(1) AS agg_0_0
FROM Oil 
GROUP BY date;

CREATE TABLE view_1 AS
SELECT date,
SUM(1) AS agg_1_0
FROM Holiday 
GROUP BY date;

CREATE TABLE view_2 AS
SELECT date,store,
SUM(1) AS agg_2_0
FROM Transactions 
GROUP BY date,store;

CREATE TABLE view_3 AS
SELECT store,
SUM(1) AS agg_3_0
FROM Stores 
GROUP BY store;

CREATE TABLE view_4 AS
SELECT item,
SUM(1) AS agg_4_0
FROM Items 
GROUP BY item;

CREATE TABLE view_5 AS
SELECT 
SUM(1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_5_0,
SUM(unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_5_1,
SUM(unit_sales*unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_5_2
FROM Sales NATURAL JOIN view_0 NATURAL JOIN view_1 NATURAL JOIN view_2 NATURAL JOIN view_3 NATURAL JOIN view_4 ;

CREATE TABLE view_6 AS
SELECT store,
SUM(1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_6_0,
SUM(unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_6_1,
SUM(unit_sales*unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_6_2
FROM Sales NATURAL JOIN view_0 NATURAL JOIN view_1 NATURAL JOIN view_2 NATURAL JOIN view_3 NATURAL JOIN view_4 
GROUP BY store;

CREATE TABLE view_7 AS
SELECT onpromotion,
SUM(1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_7_0,
SUM(unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_7_1,
SUM(unit_sales*unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_7_2
FROM Sales NATURAL JOIN view_0 NATURAL JOIN view_1 NATURAL JOIN view_2 NATURAL JOIN view_3 NATURAL JOIN view_4 
GROUP BY onpromotion;

CREATE TABLE view_8 AS
SELECT date,
SUM(1*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_8_0,
SUM(unit_sales*1*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_8_1,
SUM(unit_sales*unit_sales*1*agg_1_0*agg_2_0*agg_3_0*agg_4_0) AS agg_8_2
FROM Sales NATURAL JOIN view_1 NATURAL JOIN view_2 NATURAL JOIN view_3 NATURAL JOIN view_4 
GROUP BY date;

CREATE TABLE view_9 AS
SELECT 
SUM(CASE WHEN oilprize <= 35.360000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_0,
SUM(CASE WHEN oilprize <= 35.360000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_1,
SUM(CASE WHEN oilprize <= 35.360000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_2,
SUM(CASE WHEN oilprize > 35.360000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_3,
SUM(CASE WHEN oilprize > 35.360000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_4,
SUM(CASE WHEN oilprize > 35.360000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_5,
SUM(CASE WHEN oilprize <= 40.050000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_6,
SUM(CASE WHEN oilprize <= 40.050000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_7,
SUM(CASE WHEN oilprize <= 40.050000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_8,
SUM(CASE WHEN oilprize > 40.050000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_9,
SUM(CASE WHEN oilprize > 40.050000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_10,
SUM(CASE WHEN oilprize > 40.050000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_11,
SUM(CASE WHEN oilprize <= 43.040000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_12,
SUM(CASE WHEN oilprize <= 43.040000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_13,
SUM(CASE WHEN oilprize <= 43.040000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_14,
SUM(CASE WHEN oilprize > 43.040000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_15,
SUM(CASE WHEN oilprize > 43.040000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_16,
SUM(CASE WHEN oilprize > 43.040000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_17,
SUM(CASE WHEN oilprize <= 44.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_18,
SUM(CASE WHEN oilprize <= 44.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_19,
SUM(CASE WHEN oilprize <= 44.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_20,
SUM(CASE WHEN oilprize > 44.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_21,
SUM(CASE WHEN oilprize > 44.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_22,
SUM(CASE WHEN oilprize > 44.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_23,
SUM(CASE WHEN oilprize <= 45.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_24,
SUM(CASE WHEN oilprize <= 45.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_25,
SUM(CASE WHEN oilprize <= 45.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_26,
SUM(CASE WHEN oilprize > 45.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_27,
SUM(CASE WHEN oilprize > 45.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_28,
SUM(CASE WHEN oilprize > 45.470000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_29,
SUM(CASE WHEN oilprize <= 46.120000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_30,
SUM(CASE WHEN oilprize <= 46.120000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_31,
SUM(CASE WHEN oilprize <= 46.120000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_32,
SUM(CASE WHEN oilprize > 46.120000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_33,
SUM(CASE WHEN oilprize > 46.120000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_34,
SUM(CASE WHEN oilprize > 46.120000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_35,
SUM(CASE WHEN oilprize <= 47.170000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_36,
SUM(CASE WHEN oilprize <= 47.170000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_37,
SUM(CASE WHEN oilprize <= 47.170000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_38,
SUM(CASE WHEN oilprize > 47.170000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_39,
SUM(CASE WHEN oilprize > 47.170000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_40,
SUM(CASE WHEN oilprize > 47.170000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_41,
SUM(CASE WHEN oilprize <= 48.130000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_42,
SUM(CASE WHEN oilprize <= 48.130000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_43,
SUM(CASE WHEN oilprize <= 48.130000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_44,
SUM(CASE WHEN oilprize > 48.130000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_45,
SUM(CASE WHEN oilprize > 48.130000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_46,
SUM(CASE WHEN oilprize > 48.130000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_47,
SUM(CASE WHEN oilprize <= 49.070000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_48,
SUM(CASE WHEN oilprize <= 49.070000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_49,
SUM(CASE WHEN oilprize <= 49.070000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_50,
SUM(CASE WHEN oilprize > 49.070000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_51,
SUM(CASE WHEN oilprize > 49.070000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_52,
SUM(CASE WHEN oilprize > 49.070000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_53,
SUM(CASE WHEN oilprize <= 49.850000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_54,
SUM(CASE WHEN oilprize <= 49.850000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_55,
SUM(CASE WHEN oilprize <= 49.850000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_56,
SUM(CASE WHEN oilprize > 49.850000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_57,
SUM(CASE WHEN oilprize > 49.850000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_58,
SUM(CASE WHEN oilprize > 49.850000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_59,
SUM(CASE WHEN oilprize <= 51.610000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_60,
SUM(CASE WHEN oilprize <= 51.610000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_61,
SUM(CASE WHEN oilprize <= 51.610000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_62,
SUM(CASE WHEN oilprize > 51.610000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_63,
SUM(CASE WHEN oilprize > 51.610000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_64,
SUM(CASE WHEN oilprize > 51.610000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_65,
SUM(CASE WHEN oilprize <= 53.010000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_66,
SUM(CASE WHEN oilprize <= 53.010000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_67,
SUM(CASE WHEN oilprize <= 53.010000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_68,
SUM(CASE WHEN oilprize > 53.010000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_69,
SUM(CASE WHEN oilprize > 53.010000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_70,
SUM(CASE WHEN oilprize > 53.010000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_71,
SUM(CASE WHEN oilprize <= 54.590000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_72,
SUM(CASE WHEN oilprize <= 54.590000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_73,
SUM(CASE WHEN oilprize <= 54.590000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_74,
SUM(CASE WHEN oilprize > 54.590000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_75,
SUM(CASE WHEN oilprize > 54.590000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_76,
SUM(CASE WHEN oilprize > 54.590000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_77,
SUM(CASE WHEN oilprize <= 60.250000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_78,
SUM(CASE WHEN oilprize <= 60.250000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_79,
SUM(CASE WHEN oilprize <= 60.250000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_80,
SUM(CASE WHEN oilprize > 60.250000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_81,
SUM(CASE WHEN oilprize > 60.250000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_82,
SUM(CASE WHEN oilprize > 60.250000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_83,
SUM(CASE WHEN oilprize <= 90.880000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_84,
SUM(CASE WHEN oilprize <= 90.880000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_85,
SUM(CASE WHEN oilprize <= 90.880000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_86,
SUM(CASE WHEN oilprize > 90.880000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_87,
SUM(CASE WHEN oilprize > 90.880000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_88,
SUM(CASE WHEN oilprize > 90.880000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_89,
SUM(CASE WHEN oilprize <= 93.840000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_90,
SUM(CASE WHEN oilprize <= 93.840000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_91,
SUM(CASE WHEN oilprize <= 93.840000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_92,
SUM(CASE WHEN oilprize > 93.840000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_93,
SUM(CASE WHEN oilprize > 93.840000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_94,
SUM(CASE WHEN oilprize > 93.840000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_95,
SUM(CASE WHEN oilprize <= 97.030000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_96,
SUM(CASE WHEN oilprize <= 97.030000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_97,
SUM(CASE WHEN oilprize <= 97.030000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_98,
SUM(CASE WHEN oilprize > 97.030000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_99,
SUM(CASE WHEN oilprize > 97.030000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_100,
SUM(CASE WHEN oilprize > 97.030000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_101,
SUM(CASE WHEN oilprize <= 100.520000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_102,
SUM(CASE WHEN oilprize <= 100.520000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_103,
SUM(CASE WHEN oilprize <= 100.520000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_104,
SUM(CASE WHEN oilprize > 100.520000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_105,
SUM(CASE WHEN oilprize > 100.520000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_106,
SUM(CASE WHEN oilprize > 100.520000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_107,
SUM(CASE WHEN oilprize <= 104.060000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_108,
SUM(CASE WHEN oilprize <= 104.060000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_109,
SUM(CASE WHEN oilprize <= 104.060000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_110,
SUM(CASE WHEN oilprize > 104.060000 THEN 1.0 ELSE 0.0 END*1*agg_8_0) AS agg_9_111,
SUM(CASE WHEN oilprize > 104.060000 THEN 1.0 ELSE 0.0 END*1*agg_8_1) AS agg_9_112,
SUM(CASE WHEN oilprize > 104.060000 THEN 1.0 ELSE 0.0 END*1*agg_8_2) AS agg_9_113
FROM Oil NATURAL JOIN view_8 ;

CREATE TABLE view_10 AS
SELECT date,
SUM(1*agg_0_0*agg_2_0*agg_3_0*agg_4_0) AS agg_10_0,
SUM(unit_sales*1*agg_0_0*agg_2_0*agg_3_0*agg_4_0) AS agg_10_1,
SUM(unit_sales*unit_sales*1*agg_0_0*agg_2_0*agg_3_0*agg_4_0) AS agg_10_2
FROM Sales NATURAL JOIN view_0 NATURAL JOIN view_2 NATURAL JOIN view_3 NATURAL JOIN view_4 
GROUP BY date;

CREATE TABLE view_11 AS
SELECT holiday_type,
SUM(1*agg_10_0) AS agg_11_0,
SUM(1*agg_10_1) AS agg_11_1,
SUM(1*agg_10_2) AS agg_11_2
FROM Holiday NATURAL JOIN view_10 
GROUP BY holiday_type;

CREATE TABLE view_12 AS
SELECT locale,
SUM(1*agg_10_0) AS agg_12_0,
SUM(1*agg_10_1) AS agg_12_1,
SUM(1*agg_10_2) AS agg_12_2
FROM Holiday NATURAL JOIN view_10 
GROUP BY locale;

CREATE TABLE view_13 AS
SELECT locale_id,
SUM(1*agg_10_0) AS agg_13_0,
SUM(1*agg_10_1) AS agg_13_1,
SUM(1*agg_10_2) AS agg_13_2
FROM Holiday NATURAL JOIN view_10 
GROUP BY locale_id;

CREATE TABLE view_14 AS
SELECT transferred,
SUM(1*agg_10_0) AS agg_14_0,
SUM(1*agg_10_1) AS agg_14_1,
SUM(1*agg_10_2) AS agg_14_2
FROM Holiday NATURAL JOIN view_10 
GROUP BY transferred;

CREATE TABLE view_15 AS
SELECT date,store,
SUM(1*agg_0_0*agg_1_0*agg_3_0*agg_4_0) AS agg_15_0,
SUM(unit_sales*1*agg_0_0*agg_1_0*agg_3_0*agg_4_0) AS agg_15_1,
SUM(unit_sales*unit_sales*1*agg_0_0*agg_1_0*agg_3_0*agg_4_0) AS agg_15_2
FROM Sales NATURAL JOIN view_0 NATURAL JOIN view_1 NATURAL JOIN view_3 NATURAL JOIN view_4 
GROUP BY date,store;

CREATE TABLE view_16 AS
SELECT 
SUM(CASE WHEN transactions <= 711.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_0,
SUM(CASE WHEN transactions <= 711.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_1,
SUM(CASE WHEN transactions <= 711.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_2,
SUM(CASE WHEN transactions > 711.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_3,
SUM(CASE WHEN transactions > 711.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_4,
SUM(CASE WHEN transactions > 711.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_5,
SUM(CASE WHEN transactions <= 856.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_6,
SUM(CASE WHEN transactions <= 856.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_7,
SUM(CASE WHEN transactions <= 856.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_8,
SUM(CASE WHEN transactions > 856.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_9,
SUM(CASE WHEN transactions > 856.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_10,
SUM(CASE WHEN transactions > 856.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_11,
SUM(CASE WHEN transactions <= 973.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_12,
SUM(CASE WHEN transactions <= 973.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_13,
SUM(CASE WHEN transactions <= 973.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_14,
SUM(CASE WHEN transactions > 973.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_15,
SUM(CASE WHEN transactions > 973.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_16,
SUM(CASE WHEN transactions > 973.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_17,
SUM(CASE WHEN transactions <= 1070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_18,
SUM(CASE WHEN transactions <= 1070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_19,
SUM(CASE WHEN transactions <= 1070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_20,
SUM(CASE WHEN transactions > 1070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_21,
SUM(CASE WHEN transactions > 1070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_22,
SUM(CASE WHEN transactions > 1070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_23,
SUM(CASE WHEN transactions <= 1157.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_24,
SUM(CASE WHEN transactions <= 1157.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_25,
SUM(CASE WHEN transactions <= 1157.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_26,
SUM(CASE WHEN transactions > 1157.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_27,
SUM(CASE WHEN transactions > 1157.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_28,
SUM(CASE WHEN transactions > 1157.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_29,
SUM(CASE WHEN transactions <= 1235.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_30,
SUM(CASE WHEN transactions <= 1235.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_31,
SUM(CASE WHEN transactions <= 1235.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_32,
SUM(CASE WHEN transactions > 1235.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_33,
SUM(CASE WHEN transactions > 1235.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_34,
SUM(CASE WHEN transactions > 1235.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_35,
SUM(CASE WHEN transactions <= 1304.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_36,
SUM(CASE WHEN transactions <= 1304.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_37,
SUM(CASE WHEN transactions <= 1304.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_38,
SUM(CASE WHEN transactions > 1304.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_39,
SUM(CASE WHEN transactions > 1304.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_40,
SUM(CASE WHEN transactions > 1304.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_41,
SUM(CASE WHEN transactions <= 1373.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_42,
SUM(CASE WHEN transactions <= 1373.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_43,
SUM(CASE WHEN transactions <= 1373.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_44,
SUM(CASE WHEN transactions > 1373.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_45,
SUM(CASE WHEN transactions > 1373.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_46,
SUM(CASE WHEN transactions > 1373.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_47,
SUM(CASE WHEN transactions <= 1453.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_48,
SUM(CASE WHEN transactions <= 1453.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_49,
SUM(CASE WHEN transactions <= 1453.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_50,
SUM(CASE WHEN transactions > 1453.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_51,
SUM(CASE WHEN transactions > 1453.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_52,
SUM(CASE WHEN transactions > 1453.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_53,
SUM(CASE WHEN transactions <= 1554.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_54,
SUM(CASE WHEN transactions <= 1554.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_55,
SUM(CASE WHEN transactions <= 1554.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_56,
SUM(CASE WHEN transactions > 1554.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_57,
SUM(CASE WHEN transactions > 1554.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_58,
SUM(CASE WHEN transactions > 1554.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_59,
SUM(CASE WHEN transactions <= 1681.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_60,
SUM(CASE WHEN transactions <= 1681.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_61,
SUM(CASE WHEN transactions <= 1681.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_62,
SUM(CASE WHEN transactions > 1681.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_63,
SUM(CASE WHEN transactions > 1681.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_64,
SUM(CASE WHEN transactions > 1681.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_65,
SUM(CASE WHEN transactions <= 1804.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_66,
SUM(CASE WHEN transactions <= 1804.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_67,
SUM(CASE WHEN transactions <= 1804.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_68,
SUM(CASE WHEN transactions > 1804.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_69,
SUM(CASE WHEN transactions > 1804.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_70,
SUM(CASE WHEN transactions > 1804.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_71,
SUM(CASE WHEN transactions <= 1945.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_72,
SUM(CASE WHEN transactions <= 1945.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_73,
SUM(CASE WHEN transactions <= 1945.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_74,
SUM(CASE WHEN transactions > 1945.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_75,
SUM(CASE WHEN transactions > 1945.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_76,
SUM(CASE WHEN transactions > 1945.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_77,
SUM(CASE WHEN transactions <= 2151.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_78,
SUM(CASE WHEN transactions <= 2151.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_79,
SUM(CASE WHEN transactions <= 2151.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_80,
SUM(CASE WHEN transactions > 2151.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_81,
SUM(CASE WHEN transactions > 2151.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_82,
SUM(CASE WHEN transactions > 2151.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_83,
SUM(CASE WHEN transactions <= 2390.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_84,
SUM(CASE WHEN transactions <= 2390.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_85,
SUM(CASE WHEN transactions <= 2390.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_86,
SUM(CASE WHEN transactions > 2390.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_87,
SUM(CASE WHEN transactions > 2390.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_88,
SUM(CASE WHEN transactions > 2390.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_89,
SUM(CASE WHEN transactions <= 2679.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_90,
SUM(CASE WHEN transactions <= 2679.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_91,
SUM(CASE WHEN transactions <= 2679.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_92,
SUM(CASE WHEN transactions > 2679.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_93,
SUM(CASE WHEN transactions > 2679.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_94,
SUM(CASE WHEN transactions > 2679.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_95,
SUM(CASE WHEN transactions <= 2997.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_96,
SUM(CASE WHEN transactions <= 2997.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_97,
SUM(CASE WHEN transactions <= 2997.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_98,
SUM(CASE WHEN transactions > 2997.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_99,
SUM(CASE WHEN transactions > 2997.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_100,
SUM(CASE WHEN transactions > 2997.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_101,
SUM(CASE WHEN transactions <= 3408.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_102,
SUM(CASE WHEN transactions <= 3408.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_103,
SUM(CASE WHEN transactions <= 3408.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_104,
SUM(CASE WHEN transactions > 3408.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_105,
SUM(CASE WHEN transactions > 3408.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_106,
SUM(CASE WHEN transactions > 3408.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_107,
SUM(CASE WHEN transactions <= 4070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_108,
SUM(CASE WHEN transactions <= 4070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_109,
SUM(CASE WHEN transactions <= 4070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_110,
SUM(CASE WHEN transactions > 4070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_0) AS agg_16_111,
SUM(CASE WHEN transactions > 4070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_1) AS agg_16_112,
SUM(CASE WHEN transactions > 4070.000000 THEN 1.0 ELSE 0.0 END*1*agg_15_2) AS agg_16_113
FROM Transactions NATURAL JOIN view_15 ;

CREATE TABLE view_17 AS
SELECT store,
SUM(1*agg_0_0*agg_1_0*agg_2_0*agg_4_0) AS agg_17_0,
SUM(unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_4_0) AS agg_17_1,
SUM(unit_sales*unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_4_0) AS agg_17_2
FROM Sales NATURAL JOIN view_0 NATURAL JOIN view_1 NATURAL JOIN view_2 NATURAL JOIN view_4 
GROUP BY store;

CREATE TABLE view_18 AS
SELECT city,
SUM(1*agg_17_0) AS agg_18_0,
SUM(1*agg_17_1) AS agg_18_1,
SUM(1*agg_17_2) AS agg_18_2
FROM Stores NATURAL JOIN view_17 
GROUP BY city;

CREATE TABLE view_19 AS
SELECT state,
SUM(1*agg_17_0) AS agg_19_0,
SUM(1*agg_17_1) AS agg_19_1,
SUM(1*agg_17_2) AS agg_19_2
FROM Stores NATURAL JOIN view_17 
GROUP BY state;

CREATE TABLE view_20 AS
SELECT store_type,
SUM(1*agg_17_0) AS agg_20_0,
SUM(1*agg_17_1) AS agg_20_1,
SUM(1*agg_17_2) AS agg_20_2
FROM Stores NATURAL JOIN view_17 
GROUP BY store_type;

CREATE TABLE view_21 AS
SELECT cluster,
SUM(1*agg_17_0) AS agg_21_0,
SUM(1*agg_17_1) AS agg_21_1,
SUM(1*agg_17_2) AS agg_21_2
FROM Stores NATURAL JOIN view_17 
GROUP BY cluster;

CREATE TABLE view_22 AS
SELECT item,
SUM(1*agg_0_0*agg_1_0*agg_2_0*agg_3_0) AS agg_22_0,
SUM(unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0) AS agg_22_1,
SUM(unit_sales*unit_sales*1*agg_0_0*agg_1_0*agg_2_0*agg_3_0) AS agg_22_2
FROM Sales NATURAL JOIN view_0 NATURAL JOIN view_1 NATURAL JOIN view_2 NATURAL JOIN view_3 
GROUP BY item;

CREATE TABLE view_23 AS
SELECT family,
SUM(1*agg_22_0) AS agg_23_0,
SUM(1*agg_22_1) AS agg_23_1,
SUM(1*agg_22_2) AS agg_23_2
FROM Items NATURAL JOIN view_22 
GROUP BY family;

CREATE TABLE view_24 AS
SELECT itemclass,
SUM(1*agg_22_0) AS agg_24_0,
SUM(1*agg_22_1) AS agg_24_1,
SUM(1*agg_22_2) AS agg_24_2
FROM Items NATURAL JOIN view_22 
GROUP BY itemclass;

CREATE TABLE view_25 AS
SELECT perishable,
SUM(1*agg_22_0) AS agg_25_0,
SUM(1*agg_22_1) AS agg_25_1,
SUM(1*agg_22_2) AS agg_25_2
FROM Items NATURAL JOIN view_22 
GROUP BY perishable;

