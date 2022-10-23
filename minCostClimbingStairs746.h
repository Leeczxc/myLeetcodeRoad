//
// Created by Lee on 2022/10/22.
//

#ifndef LEETCODE_MINCOSTCLIMBINGSTAIRS746_H
#define LEETCODE_MINCOSTCLIMBINGSTAIRS746_H
#include "iostream"
#include "vector"

using namespace std;


int minCostClimbingStairs(vector<int>& cost) {
    int dp0 = cost[0];
    int dp1 = cost[1];
    int dp = min(dp0, dp1);
    for(int i = 2 ; i < cost.size(); i++){
        dp = min(dp0, dp1) + cost[i];
        dp0 = dp1;
        dp1 = dp;
    }
    return min(dp0, dp1);
}
#endif //LEETCODE_MINCOSTCLIMBINGSTAIRS746_H
