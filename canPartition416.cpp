#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1)
        return false;
    int target = sum / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
    for (int i = nums[0]; i <= target; i++)
    {
        dp[0][i] = nums[0];
    }
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (j < nums[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
        }
    }
    if (dp[nums.size() - 1][target] == target)
        return true;
    return false;
}

int main()
{
    vector<int> nums{1, 5, 10, 6};
    sort(nums.begin(), nums.end());
    if (canPartition(nums))
    {
        cout << "True";
    }
    else
        cout << "False";
}