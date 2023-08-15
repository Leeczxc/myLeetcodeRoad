#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int numSquares(int n)
{
    vector<int> dp(n + 1, __INT_MAX__);
    dp[0] = 0;
    for (int i = 1; i <= sqrt(n); i++){
        for(int j = i * i;  j <= n; j++){
            if(dp[j - i * i] != __INT_MAX__){
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
    }
    return dp[n];
}


int main(){
    cout << numSquares(12);
}