#include <iostream>
#include <vector>

using namespace std;

// template<class T, typename... Args>

// T max(T head, Args... args) {

//     T t = max<T>(args...);

//     return (head > t)?head:t;


// }
// int dps(vector<vector<int>>& maxtrix, int ans, int row, int column,int Row, int Column){
//     if(row > Row)
//         return ans;
//     if(column < 0 || column >= Column){
//         return 0;
//     }
//     ans += maxtrix[row][column];
//     return max(dps(maxtrix, ans, row + 1, column -1, Row, Column),dps(maxtrix, ans, row + 1, column, Row, Column), dps(maxtrix, ans, row + 1, column + 1, Row, Column));
// }
// int minFallingPathSum(vector<vector<int>> &matrix)
// {
//     int column = matrix[0].size();
//     int row = matrix.size();
//     int ans = 0;
//     for(int i = 0; i < column; ++i){
//         ans = max(ans, dps(matrix, 0, 0, i, row, column));
//     }
//     return ans;
// }

// 动态规划
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = dp[i - 1][j];
                if (j > 0) {
                    mn = min(mn, dp[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    mn = min(mn, dp[i - 1][j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

