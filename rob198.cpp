#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i <= nums.size(); i++){
        dp[i] = max(dp[i - 2] + nums[i - 1], dp[i -1]);
    }
    return dp[nums.size()];
}

int main(){
    vector<int> nums{2, 7, 9, 3, 1};
    cout << rob(nums);
}