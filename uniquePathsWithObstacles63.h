//
// Created by Lee on 2022/10/22.
//

#ifndef LEETCODE_UNIQUEPATHSWITHOBSTACLES63_H
#define LEETCODE_UNIQUEPATHSWITHOBSTACLES63_H

#include "iostream"
#include "vector"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1)
        return 0;
    if(m == 1 && n == 1 )
        return 1;
    vector<vector<int>> cols(m, vector<int>(n, 0));
    for(int i = 1;i < n; i++){
        if(obstacleGrid[0][i] == 1)
            break;
        cols[0][i] = 1;
    }
    for(int i = 1; i < m; i++){
        if(obstacleGrid[i][0] == 1)
            break;
        cols[i][0] = 1;
    }
    for(int i = 1; i< m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1){
                cols[i][j] = 0;
                continue;
            }
                cols[i][j] = cols[i - 1][j] + cols[i][j - 1];
        }
    }
    return cols[m - 1][n - 1];
}
#endif //LEETCODE_UNIQUEPATHSWITHOBSTACLES63_H
