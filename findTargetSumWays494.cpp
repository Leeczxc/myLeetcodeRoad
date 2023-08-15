#include <iostream>
#include <vector>

using namespace std;

// 感觉有点抽象

int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
    }
    if(((target + sum) % 2) == 1)
        return false;
    if(target > sum)
        return false;
    int bagSize = (target + sum) / 2;
    vector<int> dp(bagSize + 1, 0);
    
    dp[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        for(int j = bagSize; j >= nums[i]; j--){
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[bagSize];
}