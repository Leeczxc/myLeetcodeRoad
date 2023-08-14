#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    if(n >= 2)
        dp[2] = 2;
    for(int i = 3;i <= n; i++){
        dp[i] = 2 * dp[i - 1];
        for(int j = 1; j <= (i - 1) / 2; j++){
            if((i - 1 - j) == j){
                dp[i] += dp[j] * dp[j];
            }else{
                dp[i] += 2 * dp[i -1 -j] * dp[j];
            }
        }
    }
    return dp[n];
}

int main(){
    cout << numTrees(5);
}