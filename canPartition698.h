//
// Created by Lee on 2022/9/20.
//

#ifndef LEETCODE_CANPARTITION698_H
#define LEETCODE_CANPARTITION698_H
#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    map<int, int> nu;
    for(auto c : nums){
        sum += c;
        nu[c]++;
    }
    if(sum % k != 0)
        return false;
    auto it = nu.begin();
    while(nu.size() != 0){
        if(it->first == sum /k){
            nu.erase(it);
            continue;
        }
        auto t = nu.find(sum / k - it->first);
        if(t == nu.end() || t->second < 1 || it->second > t->second){
            return false;
        }
        t->second -= it->second;
        if(t->second == 0)
            nu.erase(t);
        nu.erase(it);
        it = nu.begin();
    }
    return true;
}
#endif //LEETCODE_CANPARTITION698_H
