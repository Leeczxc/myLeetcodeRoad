//
// Created by Lee on 2022/9/30.
//

#ifndef LEETCODE_SETZEROS0108_H
#define LEETCODE_SETZEROS0108_H
#include "iostream"
#include "vector"
#include "map"
#include "set"
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    set<int> row;
    set<int> column;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0){
                row.emplace(i);
                column.emplace(j);
            }
        }
    }
    for(auto i = row.begin(); i != row.end(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            matrix[*i][j] = 0;
        }
    }
    for(auto i = column.begin(); i != column.end(); i++){
        for(int j = 0; j < matrix.size(); j++){
            matrix[j][*i] = 0;
        }
    }
}
#endif //LEETCODE_SETZEROS0108_H
