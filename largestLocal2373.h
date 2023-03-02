#ifndef LEETCODE_LARGESTLOCAL2373_H
#define LEETCODE_LARGESTLOCAL2373_H
#include "iostream"
#include "vector"

using namespace std;

int getTheMax(vector<vector<int>>& grid, int i, int j){
    int ans = 0;
    for(int x = i ; x <= i + 2; ++x){
        for(int y = j; y <= j + 2; ++y)
            ans = max(ans, grid[x][y]);
    }
    return ans;
}

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    size_t size = grid.size() - 2;
    vector<vector<int>> ans{size, vector<int>(size, 0)};
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            ans[i][j] = getTheMax(grid, i, j);
        }
    }
    return ans;
}
#endif //LEETCODE_LARGESTLOCAL2373_H
