#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int ans = nums[0];
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    for(int i = 1; i <= nums.size(); i++){
        if(dp[i - 1] + nums[i -1] < 0)
        dp[i] = 0;
        else
        dp[i] = dp[i - 1] + nums[i -1];
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    vector<int> nums{ -1};
    cout << maxSubArray(nums);
}