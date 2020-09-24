int sinewave[] =  {2048,2073,2098,2123,2148,2173,2198,2223,2248,2273,2298,2323,2348,2373,2398,2422,2447,2472,2496,2521,2545,2569,2594,2618,2642,2666,2690,2714,2737,2761,2784,2808,2831,2854,2877,2900,2923,2946,2968,2990,3013,3035,3057,3078,3100,3122,3143,3164,3185,3206,3226,3247,3267,3287,3307,3327,3346,3366,3385,3404,3423,3441,3459,3477,3495,3513,3530,3548,3565,3581,3598,3614,3630,3646,3662,3677,3692,3707,3722,3736,3750,3764,3777,3791,3804,3816,3829,3841,3853,3865,3876,3888,3898,3909,3919,3929,3939,3949,3958,3967,3975,3984,3992,3999,4007,4014,4021,4027,4034,4040,4045,4051,4056,4060,4065,4069,4073,4076,4080,4083,4085,4087,4089,4091,4093,4094,4094,4095,4095,4095,4094,4094,4093,4091,4089,4087,4085,4083,4080,4076,4073,4069,4065,4060,4056,4051,4045,4040,4034,4027,4021,4014,4007,3999,3992,3984,3975,3967,3958,3949,3939,3929,3919,3909,3898,3888,3876,3865,3853,3841,3829,3816,3804,3791,3777,3764,3750,3736,3722,3707,3692,3677,3662,3646,3630,3614,3598,3581,3565,3548,3530,3513,3495,3477,3459,3441,3423,3404,3385,3366,3346,3327,3307,3287,3267,3247,3226,3206,3185,3164,3143,3122,3100,3078,3057,3035,3013,2990,2968,2946,2923,2900,2877,2854,2831,2808,2784,2761,2737,2714,2690,2666,2642,2618,2594,2569,2545,2521,2496,2472,2447,2422,2398,2373,2348,2323,2298,2273,2248,2223,2198,2173,2148,2123,2098,2073,2048,2022,1997,1972,1947,1922,1897,1872,1847,1822,1797,1772,1747,1722,1697,1673,1648,1623,1599,1574,1550,1526,1501,1477,1453,1429,1405,1381,1358,1334,1311,1287,1264,1241,1218,1195,1172,1149,1127,1105,1082,1060,1038,1017,995,973,952,931,910,889,869,848,828,808,788,768,749,729,710,691,672,654,636,618,600,582,565,547,530,514,497,481,465,449,433,418,403,388,373,359,345,331,318,304,291,279,266,254,242,230,219,207,197,186,176,166,156,146,137,128,120,111,103,96,88,81,74,68,61,55,50,44,39,35,30,26,22,19,15,12,10,8,6,4,2,1,1,0,0,0,1,1,2,4,6,8,10,12,15,19,22,26,30,35,39,44,50,55,61,68,74,81,88,96,103,111,120,128,137,146,156,166,176,186,197,207,219,230,242,254,266,279,291,304,318,331,345,359,373,388,403,418,433,449,465,481,497,514,530,547,565,582,600,618,636,654,672,691,710,729,749,768,788,808,828,848,869,889,910,931,952,973,995,1017,1038,1060,1082,1105,1127,1149,1172,1195,1218,1241,1264,1287,1311,1334,1358,1381,1405,1429,1453,1477,1501,1526,1550,1574,1599,1623,1648,1673,1697,1722,1747,1772,1797,1822,1847,1872,1897,1922,1947,1972,1997,2022};
int halfsinewave[] = {2048,2060,2073,2085,2098,2110,2123,2135,2148,2160,2173,2185,2198,2210,2223,2235,2247,2260,2272,2284,2296,2308,2321,2333,2345,2357,2369,2381,2392,2404,2416,2428,2439,2451,2462,2474,2485,2497,2508,2519,2530,2541,2552,2563,2574,2585,2595,2606,2616,2627,2637,2647,2657,2667,2677,2687,2697,2707,2716,2726,2735,2744,2753,2762,2771,2780,2789,2798,2806,2814,2823,2831,2839,2847,2855,2862,2870,2877,2885,2892,2899,2906,2912,2919,2926,2932,2938,2944,2950,2956,2962,2968,2973,2978,2983,2988,2993,2998,3003,3007,3011,3016,3020,3023,3027,3031,3034,3037,3041,3044,3046,3049,3052,3054,3056,3058,3060,3062,3064,3065,3066,3067,3068,3069,3070,3071,3071,3071,3071,3071,3071,3071,3070,3069,3068,3067,3066,3065,3064,3062,3060,3058,3056,3054,3052,3049,3046,3044,3041,3037,3034,3031,3027,3023,3020,3016,3011,3007,3003,2998,2993,2988,2983,2978,2973,2968,2962,2956,2950,2944,2938,2932,2926,2919,2912,2906,2899,2892,2885,2877,2870,2862,2855,2847,2839,2831,2823,2814,2806,2798,2789,2780,2771,2762,2753,2744,2735,2726,2716,2707,2697,2687,2677,2667,2657,2647,2637,2627,2616,2606,2595,2585,2574,2563,2552,2541,2530,2519,2508,2497,2485,2474,2462,2451,2439,2428,2416,2404,2392,2381,2369,2357,2345,2333,2321,2308,2296,2284,2272,2260,2247,2235,2223,2210,2198,2185,2173,2160,2148,2135,2123,2110,2098,2085,2073,2060,2048,2035,2022,2010,1997,1985,1972,1960,1947,1935,1922,1910,1897,1885,1872,1860,1848,1835,1823,1811,1799,1787,1774,1762,1750,1738,1726,1714,1703,1691,1679,1667,1656,1644,1633,1621,1610,1598,1587,1576,1565,1554,1543,1532,1521,1510,1500,1489,1479,1468,1458,1448,1438,1428,1418,1408,1398,1388,1379,1369,1360,1351,1342,1333,1324,1315,1306,1297,1289,1281,1272,1264,1256,1248,1240,1233,1225,1218,1210,1203,1196,1189,1183,1176,1169,1163,1157,1151,1145,1139,1133,1127,1122,1117,1112,1107,1102,1097,1092,1088,1084,1079,1075,1072,1068,1064,1061,1058,1054,1051,1049,1046,1043,1041,1039,1037,1035,1033,1031,1030,1029,1028,1027,1026,1025,1024,1024,1024,1024,1024,1024,1024,1025,1026,1027,1028,1029,1030,1031,1033,1035,1037,1039,1041,1043,1046,1049,1051,1054,1058,1061,1064,1068,1072,1075,1079,1084,1088,1092,1097,1102,1107,1112,1117,1122,1127,1133,1139,1145,1151,1157,1163,1169,1176,1183,1189,1196,1203,1210,1218,1225,1233,1240,1248,1256,1264,1272,1281,1289,1297,1306,1315,1324,1333,1342,1351,1360,1369,1379,1388,1398,1408,1418,1428,1438,1448,1458,1468,1479,1489,1500,1510,1521,1532,1543,1554,1565,1576,1587,1598,1610,1621,1633,1644,1656,1667,1679,1691,1703,1714,1726,1738,1750,1762,1774,1787,1799,1811,1823,1835,1848,1860,1872,1885,1897,1910,1922,1935,1947,1960,1972,1985,1997,2010,2022,2035};
int sawtooth[] = {0,8,16,24,32,40,48,56,64,72,80,88,96,104,112,120,128,136,144,152,160,168,176,184,192,200,208,216,224,232,240,248,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,400,408,416,424,432,440,448,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,600,608,616,624,632,640,648,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,800,808,816,824,832,840,848,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,1000,1008,1016,1024,1032,1040,1048,1056,1064,1072,1080,1088,1096,1104,1112,1120,1128,1136,1144,1152,1160,1168,1176,1184,1192,1200,1208,1216,1224,1232,1240,1248,1256,1264,1272,1280,1288,1296,1304,1312,1320,1328,1336,1344,1352,1360,1368,1376,1384,1392,1400,1408,1416,1424,1432,1440,1448,1456,1464,1472,1480,1488,1496,1504,1512,1520,1528,1536,1544,1552,1560,1568,1576,1584,1592,1600,1608,1616,1624,1632,1640,1648,1656,1664,1672,1680,1688,1696,1704,1712,1720,1728,1736,1744,1752,1760,1768,1776,1784,1792,1800,1808,1816,1824,1832,1840,1848,1856,1864,1872,1880,1888,1896,1904,1912,1920,1928,1936,1944,1952,1960,1968,1976,1984,1992,2000,2008,2016,2024,2032,2040,2048,2055,2063,2071,2079,2087,2095,2103,2111,2119,2127,2135,2143,2151,2159,2167,2175,2183,2191,2199,2207,2215,2223,2231,2239,2247,2255,2263,2271,2279,2287,2295,2303,2311,2319,2327,2335,2343,2351,2359,2367,2375,2383,2391,2399,2407,2415,2423,2431,2439,2447,2455,2463,2471,2479,2487,2495,2503,2511,2519,2527,2535,2543,2551,2559,2567,2575,2583,2591,2599,2607,2615,2623,2631,2639,2647,2655,2663,2671,2679,2687,2695,2703,2711,2719,2727,2735,2743,2751,2759,2767,2775,2783,2791,2799,2807,2815,2823,2831,2839,2847,2855,2863,2871,2879,2887,2895,2903,2911,2919,2927,2935,2943,2951,2959,2967,2975,2983,2991,2999,3007,3015,3023,3031,3039,3047,3055,3063,3071,3079,3087,3095,3103,3111,3119,3127,3135,3143,3151,3159,3167,3175,3183,3191,3199,3207,3215,3223,3231,3239,3247,3255,3263,3271,3279,3287,3295,3303,3311,3319,3327,3335,3343,3351,3359,3367,3375,3383,3391,3399,3407,3415,3423,3431,3439,3447,3455,3463,3471,3479,3487,3495,3503,3511,3519,3527,3535,3543,3551,3559,3567,3575,3583,3591,3599,3607,3615,3623,3631,3639,3647,3655,3663,3671,3679,3687,3695,3703,3711,3719,3727,3735,3743,3751,3759,3767,3775,3783,3791,3799,3807,3815,3823,3831,3839,3847,3855,3863,3871,3879,3887,3895,3903,3911,3919,3927,3935,3943,3951,3959,3967,3975,3983,3991,3999,4007,4015,4023,4031,4039,4047,4055,4063,4071,4079,4087};
int halfsawtooth[] = {0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,272,276,280,284,288,292,296,300,304,308,312,316,320,324,328,332,336,340,344,348,352,356,360,364,368,372,376,380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,448,452,456,460,464,468,472,476,480,484,488,492,496,500,504,508,512,516,520,524,528,532,536,540,544,548,552,556,560,564,568,572,576,580,584,588,592,596,600,604,608,612,616,620,624,628,632,636,640,644,648,652,656,660,664,668,672,676,680,684,688,692,696,700,704,708,712,716,720,724,728,732,736,740,744,748,752,756,760,764,768,772,776,780,784,788,792,796,800,804,808,812,816,820,824,828,832,836,840,844,848,852,856,860,864,868,872,876,880,884,888,892,896,900,904,908,912,916,920,924,928,932,936,940,944,948,952,956,960,964,968,972,976,980,984,988,992,996,1000,1004,1008,1012,1016,1020,1024,1027.5,1031.5,1035.5,1039.5,1043.5,1047.5,1051.5,1055.5,1059.5,1063.5,1067.5,1071.5,1075.5,1079.5,1083.5,1087.5,1091.5,1095.5,1099.5,1103.5,1107.5,1111.5,1115.5,1119.5,1123.5,1127.5,1131.5,1135.5,1139.5,1143.5,1147.5,1151.5,1155.5,1159.5,1163.5,1167.5,1171.5,1175.5,1179.5,1183.5,1187.5,1191.5,1195.5,1199.5,1203.5,1207.5,1211.5,1215.5,1219.5,1223.5,1227.5,1231.5,1235.5,1239.5,1243.5,1247.5,1251.5,1255.5,1259.5,1263.5,1267.5,1271.5,1275.5,1279.5,1283.5,1287.5,1291.5,1295.5,1299.5,1303.5,1307.5,1311.5,1315.5,1319.5,1323.5,1327.5,1331.5,1335.5,1339.5,1343.5,1347.5,1351.5,1355.5,1359.5,1363.5,1367.5,1371.5,1375.5,1379.5,1383.5,1387.5,1391.5,1395.5,1399.5,1403.5,1407.5,1411.5,1415.5,1419.5,1423.5,1427.5,1431.5,1435.5,1439.5,1443.5,1447.5,1451.5,1455.5,1459.5,1463.5,1467.5,1471.5,1475.5,1479.5,1483.5,1487.5,1491.5,1495.5,1499.5,1503.5,1507.5,1511.5,1515.5,1519.5,1523.5,1527.5,1531.5,1535.5,1539.5,1543.5,1547.5,1551.5,1555.5,1559.5,1563.5,1567.5,1571.5,1575.5,1579.5,1583.5,1587.5,1591.5,1595.5,1599.5,1603.5,1607.5,1611.5,1615.5,1619.5,1623.5,1627.5,1631.5,1635.5,1639.5,1643.5,1647.5,1651.5,1655.5,1659.5,1663.5,1667.5,1671.5,1675.5,1679.5,1683.5,1687.5,1691.5,1695.5,1699.5,1703.5,1707.5,1711.5,1715.5,1719.5,1723.5,1727.5,1731.5,1735.5,1739.5,1743.5,1747.5,1751.5,1755.5,1759.5,1763.5,1767.5,1771.5,1775.5,1779.5,1783.5,1787.5,1791.5,1795.5,1799.5,1803.5,1807.5,1811.5,1815.5,1819.5,1823.5,1827.5,1831.5,1835.5,1839.5,1843.5,1847.5,1851.5,1855.5,1859.5,1863.5,1867.5,1871.5,1875.5,1879.5,1883.5,1887.5,1891.5,1895.5,1899.5,1903.5,1907.5,1911.5,1915.5,1919.5,1923.5,1927.5,1931.5,1935.5,1939.5,1943.5,1947.5,1951.5,1955.5,1959.5,1963.5,1967.5,1971.5,1975.5,1979.5,1983.5,1987.5,1991.5,1995.5,1999.5,2003.5,2007.5,2011.5,2015.5,2019.5,2023.5,2027.5,2031.5,2035.5,2039.5,2043.5};
