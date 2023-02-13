#ifndef LEETCODE_DIESIMULATOR1223_H
#define LEETCODE_DIESIMULATOR1223_H
#include "iostream"
#include "vector"

using namespace std;

class Solution{
public:
    static constexpr int mod = 1E9 + 7;

    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(16)));
        for(int j = 0; j < 6; j++)
            dp[1][j][1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 1; j < rollMax[j]; k++){
                    for(int p = 0; p < 6; p++){
                        if(p != j)
                            dp[i][p][1] = (dp[i][p][1] + dp[i - 1][j][k]) % mod;
                        else if(k + 1 < rollMax[j])
                            dp[i][p][k + 1] = (dp[i][p][k + 1] + dp[i - 1][j][k]) % mod;
                    }
                }
            }
        }
        int res = 0;
        for(int j = 0 ; j < 6; j++){
            for(int k = 1; k < rollMax[j]; k++)
                res = (res + dp[n][j][k]) % mod;
        }
        return res;
    }
};
#endif //LEETCODE_DIESIMULATOR1223_H
