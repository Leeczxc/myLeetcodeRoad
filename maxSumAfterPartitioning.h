#ifndef LEETCODE_MAXSUMAFTERPARTITIONING_H
#define LEETCODE_MAXSUMAFTERPARTITIONING_H
#include "iostream"
#include "vector"

using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k){
    int n  = arr.size();
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++){
        int maxValue = arr[i - 1];
        for(int j = i - 1; j >= 0 && j >= i -k; j--){
            dp[i] = max(dp[i], dp[j] + maxValue * (i - j));
            if(j > 0)
                maxValue = max(maxValue, arr[j - 1]);
        }
    };
    return dp[n];
}
#endif //LEETCODE_MAXSUMAFTERPARTITIONING_H
