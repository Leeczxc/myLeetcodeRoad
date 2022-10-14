//
// Created by Lee on 2022/10/12.
//

#ifndef LEETCODE_GENERATEMATRIX58_H
#define LEETCODE_GENERATEMATRIX58_H
#include "vector"
#include "iostream"

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    if(n == 1)
        return vector<vector<int>>(1,vector<int>(1,1));
    int start = 0;
    int end = n -1;
    int num = 0;
    vector<vector<int>> ans(n, vector<int>(n,0));
    while(start < end){
        for(int i = start; i <= end; i++){
            ans[start][i] = ++num;
        }
        for(int i = start + 1; i <= end; i++){
            ans[i][end] = ++num;
        }
        for(int i = end - 1; i >= start; i--){
            ans[end][i] = ++num;
        }
        for(int i = end - 1; i > start; i--){
            ans[i][start] = ++num;
        }
        start++;
        end--;
    }
    if(n % 2 == 1)
        ans[start][start] = ++num;
    return ans;
}
#endif //LEETCODE_GENERATEMATRIX58_H
