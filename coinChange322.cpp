#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, __INT_MAX__);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++)
    { // 遍历物品
        for (int j = coins[i]; j <= amount; j++)
        { // 遍历背包
            if (dp[j - coins[i]] != __INT_MAX__)
            { // 如果dp[j - coins[i]]是初始值则跳过
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
    }
    if (dp[amount] == __INT_MAX__)
        return -1;
    return dp[amount];
}

int main()
{
    vector<int> coins{2, 5, 10, 1};
    cout << coinChange(coins, 27);
}