#include <iostream>
#include <vector>

using namespace std;

// 写错了，到时候看看
int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s.size()][t.size()];
}

int main()
{
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t);
}