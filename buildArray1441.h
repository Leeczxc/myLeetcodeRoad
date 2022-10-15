//
// Created by Lee on 2022/10/15.
//

#ifndef LEETCODE_BUILDARRAY1441_H
#define LEETCODE_BUILDARRAY1441_H
#include "iostream"
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    set<int> nums;
    for(int num : target){
        nums.emplace(num);
    }
    vector<string> ans;
    sort(target.begin(), target.end());
    for(int i = 1; i <= target[target.size() - 1]; i++){
        if(target[i - 1] > n)
            break;
        ans.emplace_back("PUSH");
        auto t = nums.find(i);
        if(t == nums.end())
            ans.emplace_back("POP");
    }
    return ans;
}
#endif //LEETCODE_BUILDARRAY1441_H
