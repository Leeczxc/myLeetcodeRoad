//
// Created by Lee on 2022/10/22.
//

#ifndef LEETCODE_UNIQUEPATHS62_H
#define LEETCODE_UNIQUEPATHS62_H
#include "iostream"
#include "vector"

using namespace std;

int uniquePaths(int m, int n) {
    if(m == 1 && n == 1)
        return 1;
    vector<vector<int>> col(m, vector<int>(n,0));
    for(int i = 1; i < n; i++)
        col[0][i]  = 1;
    for(int i = 1; i < m; i++)
        col[i][0] = 1;
    for(int i = 1; i < m ; i++)
        for(int j = 1; j < n; j++)
            col[i][j] = col[i - 1][j] + col[i][j - 1];
    return col[m-1][n-1];
}
#endif //LEETCODE_UNIQUEPATHS62_H
