//
// Created by Lee on 2022/10/16.
//

#ifndef LEETCODE_POSSIBLEBIPARTITION886_H
#define LEETCODE_POSSIBLEBIPARTITION886_H
#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//    sort(dislikes.begin(), dislikes.end());
    set<int> first;
    set<int> second;
    for(auto dis : dislikes){
        int x = dis[0];
        int y = dis[1];
        // 判断第一个元素是否在集合里面
        if(first.find(x) != first.end()){
            if(first.find(y) != first.end())
                return false;
            second.emplace(y);
            continue;
        }else if(second.find(x) != second.end()){
            if(second.find(y) != second.end())
                return false;
            first.emplace(y);
            continue;
        }
        // 确实第一个元素不在里面
        // 判断第二个元素是不是在里面
        if(first.find(y) != first.end()){
           second.emplace(x);
           continue;
        }else if(second.find(y) != second.end()){
            first.emplace(x);
            continue;
        }
        first.emplace(x);
        second.emplace(y);
    }
    return true;
}
#endif //LEETCODE_POSSIBLEBIPARTITION886_H
