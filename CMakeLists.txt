# cmake_minimum_required(VERSION <specify CMake version here>)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(BAEKJOON)
include_directories(PROGRAMMERS)

add_executable(Algorithm
        BAEKJOON/Basic/10026.cpp
        BAEKJOON/Basic/1003.cpp
        BAEKJOON/Basic/1012.cpp
        BAEKJOON/Basic/1016.cpp
        BAEKJOON/Basic/10171.cpp
        BAEKJOON/Basic/10172.cpp
        BAEKJOON/Basic/1018.cpp
        BAEKJOON/Basic/1021.cpp
        BAEKJOON/Basic/10250.cpp
        BAEKJOON/Basic/10699.cpp
        BAEKJOON/Basic/1072.cpp
        BAEKJOON/Basic/1074.cpp
        BAEKJOON/Basic/10773.cpp
        BAEKJOON/Basic/10798.cpp
        BAEKJOON/Basic/10807.cpp
        BAEKJOON/Basic/10809.cpp
        BAEKJOON/Basic/10810.cpp
        BAEKJOON/Basic/10811.cpp
        BAEKJOON/Basic/10813.cpp
        BAEKJOON/Basic/10814.cpp
        BAEKJOON/Basic/10816.cpp
        BAEKJOON/Basic/10818.cpp
        BAEKJOON/Basic/10826.cpp
        BAEKJOON/Basic/10845.cpp
        BAEKJOON/Basic/1085.cpp
        BAEKJOON/Basic/10870.cpp
        BAEKJOON/Basic/10871.cpp
        BAEKJOON/Basic/10872.cpp
        BAEKJOON/Basic/10951.cpp
        BAEKJOON/Basic/10952.cpp
        BAEKJOON/Basic/10986.cpp
        BAEKJOON/Basic/10989.cpp
        BAEKJOON/Basic/11003.cpp
        BAEKJOON/Basic/11021.cpp
        BAEKJOON/Basic/11022.cpp
        BAEKJOON/Basic/11047.cpp
        BAEKJOON/Basic/11050.cpp
        BAEKJOON/Basic/11053.cpp
        BAEKJOON/Basic/1107.cpp
        BAEKJOON/Basic/1120.cpp
        BAEKJOON/Basic/11382.cpp
        BAEKJOON/Basic/11399.cpp
        BAEKJOON/Basic/11403.cpp
        BAEKJOON/Basic/1152.cpp
        BAEKJOON/Basic/11536.cpp
        BAEKJOON/Basic/1157.cpp
        BAEKJOON/Basic/11650.cpp
        BAEKJOON/Basic/11651.cpp
        BAEKJOON/Basic/11654.cpp
        BAEKJOON/Basic/11659.cpp
        BAEKJOON/Basic/11718.cpp
        BAEKJOON/Basic/11723.cpp
        BAEKJOON/Basic/11724.cpp
        BAEKJOON/Basic/11726.cpp
        BAEKJOON/Basic/11727.cpp
        BAEKJOON/Basic/11729.cpp
        BAEKJOON/Basic/1181.cpp
        BAEKJOON/Basic/1182.cpp
        BAEKJOON/Basic/11866.cpp
        BAEKJOON/Basic/11868.cpp
        BAEKJOON/Basic/11899.cpp
        BAEKJOON/Basic/12015.cpp
        BAEKJOON/Basic/1205.cpp
        BAEKJOON/Basic/1259.cpp
        BAEKJOON/Basic/1260.cpp
        BAEKJOON/Basic/1269.cpp
        BAEKJOON/Basic/12789.cpp
        BAEKJOON/Basic/12865.cpp
        BAEKJOON/Basic/1300.cpp
        BAEKJOON/Basic/1302.cpp
        BAEKJOON/Basic/1312.cpp
        BAEKJOON/Basic/1316.cpp
        BAEKJOON/Basic/1389.cpp
        BAEKJOON/Basic/1406.cpp
        BAEKJOON/Basic/1427.cpp
        BAEKJOON/Basic/1436.cpp
        BAEKJOON/Basic/14494.cpp
        BAEKJOON/Basic/14500.cpp
        BAEKJOON/Basic/1463.cpp
        BAEKJOON/Basic/1487.cpp
        BAEKJOON/Basic/14940.cpp
        BAEKJOON/Basic/1546.cpp
        BAEKJOON/Basic/15552.cpp
        BAEKJOON/Basic/15829.cpp
        BAEKJOON/Basic/15964.cpp
        BAEKJOON/Basic/1654.cpp
        BAEKJOON/Basic/1662.cpp
        BAEKJOON/Basic/1676.cpp
        BAEKJOON/Basic/16928.cpp
        BAEKJOON/Basic/1697.cpp
        BAEKJOON/Basic/1699.cpp
        BAEKJOON/Basic/17175.cpp
        BAEKJOON/Basic/17219.cpp
        BAEKJOON/Basic/17503.cpp
        BAEKJOON/Basic/1755.cpp
        BAEKJOON/Basic/17626.cpp
        BAEKJOON/Basic/1764.cpp
        BAEKJOON/Basic/18111.cpp
        BAEKJOON/Basic/1874.cpp
        BAEKJOON/Basic/18870.cpp
        BAEKJOON/Basic/1918.cpp
        BAEKJOON/Basic/1920.cpp
        BAEKJOON/Basic/1927.cpp
        BAEKJOON/Basic/1929.cpp
        BAEKJOON/Basic/1931.cpp
        BAEKJOON/Basic/2018.cpp
        BAEKJOON/Basic/2075.cpp
        BAEKJOON/Basic/2108.cpp
        BAEKJOON/Basic/2161.cpp
        BAEKJOON/Basic/2166.cpp
        BAEKJOON/Basic/21736.cpp
        BAEKJOON/Basic/2178.cpp
        BAEKJOON/Basic/2231.cpp
        BAEKJOON/Basic/2292.cpp
        BAEKJOON/Basic/23253.cpp
        BAEKJOON/Basic/24060.cpp
        BAEKJOON/Basic/2420.cpp
        BAEKJOON/Basic/2438.cpp
        BAEKJOON/Basic/2439.cpp
        BAEKJOON/Basic/24416.cpp
        BAEKJOON/Basic/2442.cpp
        BAEKJOON/Basic/2447.cpp
        BAEKJOON/Basic/2475.cpp
        BAEKJOON/Basic/2480.cpp
        BAEKJOON/Basic/2491.cpp
        BAEKJOON/Basic/2504.cpp
        BAEKJOON/Basic/25083.cpp
        BAEKJOON/Basic/25304.cpp
        BAEKJOON/Basic/25314.cpp
        BAEKJOON/Basic/25497.cpp
        BAEKJOON/Basic/25501.cpp
        BAEKJOON/Basic/2558.cpp
        BAEKJOON/Basic/2562.cpp
        BAEKJOON/Basic/2563.cpp
        BAEKJOON/Basic/2566.cpp
        BAEKJOON/Basic/2577.cpp
        BAEKJOON/Basic/2579.cpp
        BAEKJOON/Basic/2588.cpp
        BAEKJOON/Basic/2606.cpp
        BAEKJOON/Basic/2630.cpp
        BAEKJOON/Basic/26549.cpp
        BAEKJOON/Basic/2666.cpp
        BAEKJOON/Basic/2667.cpp
        BAEKJOON/Basic/2675.cpp
        BAEKJOON/Basic/2738.cpp
        BAEKJOON/Basic/2740.cpp
        BAEKJOON/Basic/2741.cpp
        BAEKJOON/Basic/2742.cpp
        BAEKJOON/Basic/2743.cpp
        BAEKJOON/Basic/2744.cpp
        BAEKJOON/Basic/2748.cpp
        BAEKJOON/Basic/2750.cpp
        BAEKJOON/Basic/2751.CPP
        BAEKJOON/Basic/2754.cpp
        BAEKJOON/Basic/2775.cpp
        BAEKJOON/Basic/27866.cpp
        BAEKJOON/Basic/27896.cpp
        BAEKJOON/Basic/2792.cpp
        BAEKJOON/Basic/2798.cpp
        BAEKJOON/Basic/2805.cpp
        BAEKJOON/Basic/2839.cpp
        BAEKJOON/Basic/2869.cpp
        BAEKJOON/Basic/2884.cpp
        BAEKJOON/Basic/2908.cpp
        BAEKJOON/Basic/2920.cpp
        BAEKJOON/Basic/3052.cpp
        BAEKJOON/Basic/3986.cpp
        BAEKJOON/Basic/4153.cpp
        BAEKJOON/Basic/4949.cpp
        BAEKJOON/Basic/5397.cpp
        BAEKJOON/Basic/5430.cpp
        BAEKJOON/Basic/5567.cpp
        BAEKJOON/Basic/5597.cpp
        BAEKJOON/Basic/5622.cpp
        BAEKJOON/Basic/7287.cpp
        BAEKJOON/Basic/7568.cpp
        BAEKJOON/Basic/7569.cpp
        BAEKJOON/Basic/7576.cpp
        BAEKJOON/Basic/7785.cpp
        BAEKJOON/Basic/8958.cpp
        BAEKJOON/Basic/9019.cpp
        BAEKJOON/Basic/9086.cpp
        BAEKJOON/Basic/9095.cpp
        BAEKJOON/Basic/9375.cpp
        BAEKJOON/Basic/9461.cpp
        BAEKJOON/Basic/9655.cpp
        BAEKJOON/Basic/9656.cpp
        BAEKJOON/Basic/9935.cpp
        "BAEKJOON/Data_Structure/10799_Iron bar.cpp"
        BAEKJOON/Data_Structure/10828_Stack.cpp
        BAEKJOON/Data_Structure/10866_Deque.cpp
        "BAEKJOON/Data_Structure/1158_ Josephus Problem.cpp"
        BAEKJOON/Data_Structure/18258_queue2.cpp
        BAEKJOON/Data_Structure/1935_Postfix2.cpp
        "BAEKJOON/Data_Structure/1966_Printer Que.cpp"
        BAEKJOON/Data_Structure/2164_Card2.cpp
        "BAEKJOON/Data_Structure/22942_Data Checker.cpp"
        "BAEKJOON/Data_Structure/2346_Popping Balloon.cpp"
        BAEKJOON/Data_Structure/2493_Top.cpp
        "BAEKJOON/Data_Structure/9012_Parenthesis String.cpp"
        "BAEKJOON/Data_Structure2/11279_Max Heap.cpp"
        "BAEKJOON/Data_Structure2/11286_ Absolute Heap.cpp"
        BAEKJOON/Data_Structure2/14425_stringSet.cpp
        BAEKJOON/Data_Structure2/1620_Im_PoketmonMaster_Dasom.cpp
        BAEKJOON/Data_Structure2/4358_Ecology.cpp
        "BAEKJOON/Data_Structure2/7662_Double Priority Queue.cpp"
        BAEKJOON/Math/1110_AddCycle.cpp
        BAEKJOON/Math/11653_Factorization.cpp
        BAEKJOON/Math/1934_LCM.cpp
        BAEKJOON/Math/1978_FindPrimeNum.cpp
        BAEKJOON/Math/21920.cpp
        BAEKJOON/Math/22864_fatigue.cpp
        BAEKJOON/Math/2581_PrimeNum.cpp
        "BAEKJOON/Math/2609_greatest common factor&Least Common Multiple.cpp"
        BAEKJOON/Math/2745_ToDecimal.cpp
        "BAEKJOON/Math/2960_Sieve of Eratosthenes.cpp"
        BAEKJOON/Math/4134_Next_PrimeNum.cpp
        BAEKJOON/Math/5347_LCM.cpp
        "BAEKJOON/Math/5618_common factor.cpp"
        "BAEKJOON/String/11720_The sum of numbers.cpp"
        "PROGRAMMERS/Level_1/LV1_A knightly weapon.cpp"
        "PROGRAMMERS/Level_1/LV1_Add a missing number.cpp"
        "PROGRAMMERS/Level_1/LV1_Calc the money.cpp"
        "PROGRAMMERS/Level_1/LV1_Checking personality type.cpp"
        "PROGRAMMERS/Level_1/LV1_don't like the same number.cpp"
        "PROGRAMMERS/Level_1/LV1_Find a number that leaves 1.cpp"
        PROGRAMMERS/Level_1/LV1_MakeAHamberger.cpp
        PROGRAMMERS/Level_1/LV1_StringDivide.cpp
        "PROGRAMMERS/Level_2/LV2_Currect bracket.cpp"
        "PROGRAMMERS/Level_2/LV2_Fibonacci numbers.cpp"
        "PROGRAMMERS/Level_2/LV_2_Develope Fuction.cpp"
        PROGRAMMERS/OpenChat.cpp)
