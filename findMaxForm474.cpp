#include <iostream>
#include <vector>

using namespace std;

std::pair<int, int> getStrNum(string &str)
{
    int m = 0, n = 0;
    for (auto &c : str)
    {
        if (c == '0')
            m++;
        else
            n++;
    }
    return std::pair<int, int>(m, n);
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    auto t = getStrNum(strs[0]);
    int x = t.first;
    int y  = t.second;
    for(int i = x; i <= m; i++){
        for(int j = y; j <= n; j++){
            dp[0][i][j] = 1;
        }
    }
    for(int i = 1; i < strs.size(); i++){
        t = getStrNum(strs[i]);
        x = t.first;
        y = t.second;
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= n; k++){
                if(j < x || k < y){
                    dp[i][j][k] = dp[i - 1][j][k];
                }else{
                 dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - x][k - y] + 1);
                }
            }
        }
    }
    return dp[strs.size() - 1][m][n];
}

int main(){
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(strs, 5, 3);
}