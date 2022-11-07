//
// Created by Lee on 2022/11/4.
//

#ifndef LEETCODE_REACHNUMBER754_H
#define LEETCODE_REACHNUMBER754_H
#include "iostream"
#include "vector"

using namespace std;

// 思路错了 是数学题
int reachNumber(int target) {
    if(target < 0)
        target = -1 * target;
    vector<int> dp(target + 1, 0);
    int sum = 0;
    for(int i = 0; sum + i <= target; i++){
        sum += i;
        dp[sum] = i;
    }
    if(dp[target] != 0)
        return dp[target];
    if(target >= 2){
        for(int i = 2; i <= target; i++){
            if(dp[i] == 0)
                dp[i] = dp[i - 1] + 2;
        }
    }
    return dp[target];
}
#endif //LEETCODE_REACHNUMBER754_H