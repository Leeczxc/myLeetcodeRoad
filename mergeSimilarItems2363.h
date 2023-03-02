#ifndef LEETCODE_MERGESIMILARITEMS2363_H
#define LEETCODE_MERGESIMILARITEMS2363_H
#include "iostream"
#include "vector"
#include "map"

using namespace std;

vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
    map<int, int> item;
    size_t size = items1.size();
    for (int i = 0; i < size; i++) {
        if (item.find(items1[i][0]) != item.end()) {
            item[items1[i][0]] = items1[i][1];
        } else {
            item[items1[i][0]] += items1[i][1];
        }
    }
    size = items2.size();
    for (int i = 0; i < size; i++) {
        if (item.find(items2[i][0]) != item.end()) {
            item[items2[i][0]] += items2[i][1];
        } else {
            item[items2[i][0]] = items2[i][1];
        }
    }
    vector<vector<int>> ans;
    auto ite = item.begin();
    while(ite != item.end()){
        ans.emplace_back(vector<int>{ite->first, ite->second});
        ite++;
    }
    return ans;
}

#endif