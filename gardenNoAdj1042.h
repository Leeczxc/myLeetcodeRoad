#ifndef LEETCODE_GARDENNOADJ1042_H
#define LEETCODE_GARDENNOADJ1042_H
#include "iostream"
#include "vector"
#include "map"


using namespace std;
// 看题解是邻接表
vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    for(auto &c : paths){
        if(c[0] > c[1])
            swap(c[0], c[1]);
    }
    map<int, vector<int>> nums;
    for(auto &c : paths){
        nums[c[0]].emplace_back(c[1]);
    }
    vector<bool> times(n, false);
    vector<int> path(n, 0);


}
#endif //LEETCODE_GARDENNOADJ1042_H
