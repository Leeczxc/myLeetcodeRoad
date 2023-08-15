#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s)
{
    int ans = 1;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i < s.size(); i++){
        dp[i][i] = 1;
    }
    for(int i = s.size() - 2; i >= 0; i--){
        for(int j = i + 1; j < s.size(); j++){
            if(s[i] == s[j]){
                if((j - i) == 1){
                    dp[i][j] = 2;
                }else{
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }else{
                if((j - i) == 1){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main(){
    string s = "abcabcabcabc";
    cout << longestPalindromeSubseq(s);
}