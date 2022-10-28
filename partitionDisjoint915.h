//
// Created by Lee on 2022/10/24.
//

#ifndef LEETCODE_PARTITIONDISJOINT915_H
#define LEETCODE_PARTITIONDISJOINT915_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int partitionDisjoint(vector<int>& nums) {
     int leftSize = 1;
     int maxNum = nums[0];
     int ans = 1;
     map<int, int> num;
     for(int i = 1; i < nums.size(); i++){
         num[nums[i]]++;
     }

     for(int i = 1; i < nums.size(); i++){
        if(num.begin()->first < maxNum){
            ans++;
            auto ite = num.find(nums[i]);
            maxNum = max(maxNum, nums[i]);
            if(ite->second == 1)
                num.erase(ite);
            else
                ite->second--;
        }else
            break;
     }
     return ans;
}
#endif //LEETCODE_PARTITIONDISJOINT915_H
