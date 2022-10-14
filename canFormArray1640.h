//
// Created by Lee on 2022/9/22.
//

#ifndef LEETCODE_CANFORMARRAY1640_H
#define LEETCODE_CANFORMARRAY1640_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
bool hasValue(int find, vector<int> values){
    bool ok = false;
    for(auto c : values){
        if(c == find){
            ok = true;
            break;
        }
    }
    return ok;
}
bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    bool can = true;
    int pos = 0;

    while(pos < arr.size()){
        int value = arr[pos];
        auto it =pieces.begin();
        while(it != pieces.end()){
            if(hasValue(value, *it)){
                break;
            }
            it++;
        }
        if(it == pieces.end())
            return false;
        size_t size = it->size();
        for(int i = 0; i < size; i++){
            if(arr[pos + i] != (*it)[i]){
                can = false;
                break;
            }
        }
        pos += size;
    }
    return can;
}
#endif //LEETCODE_CANFORMARRAY1640_H
