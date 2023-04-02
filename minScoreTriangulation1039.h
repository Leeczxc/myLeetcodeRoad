#ifndef LEETCODE_MINSCORETRIANGULATION1039_H
#define LEETCODE_MINSCORETRIANGULATION1039_H
#include "iostream"
#include "vector"

using namespace std;

// 感觉记忆话搜索的思路比较简单
int dp(vector<int>& values, int x,int y){
    class Solution {
    public:
        int minScoreTriangulation(vector<int>& values) {
            int n = values.size();
            int f[n][n];
            memset(f, 0, sizeof(f));
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (i + 1 == j) {
                    return 0;
                }
                if (f[i][j]) {
                    return f[i][j];
                }
                int ans = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    ans = min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
                }
                return f[i][j] = ans;
            };
            return dfs(0, n - 1);
        }
    };


}

int minScoreTriangulation(vector<int>& values) {
    return dp(values,0 ,0);
}
#endif //LEETCODE_MINSCORETRIANGULATION1039_H
