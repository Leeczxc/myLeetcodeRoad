//
// Created by Lee on 2022/10/22.
//

#ifndef LEETCODE_INTERGERBREAK343_H
#define LEETCODE_INTERGERBREAK343_H
#include "iostream"
#include "vector"

using namespace std;

int integerBreak(int n) {
    vector<int> dp;
    // 0 ,1 ,2
    dp.emplace_back(0);
    dp.emplace_back(0);
    dp.emplace_back(1);
    for(int i = 3 ; i <= n; i++){
        int numMax = 0;
        for(int j = 1; j <= i -1; j++){
            int t  = max(j * (i - j), j * dp[i - j]);
            numMax = max(t, numMax);
        }
        dp.emplace_back(numMax);
    }
    return dp[n];
}
#endif //LEETCODE_INTERGERBREAK343_H
