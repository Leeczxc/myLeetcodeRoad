//
// Created by Lee on 2022/10/11.
//

#ifndef LEETCODE_MAXASCENDINGSUM1800_H
#define LEETCODE_MAXASCENDINGSUM1800_H
#include "iostream"
#include "vector"

using namespace std;

int maxAscendingSum(vector<int>& nums) {
    int maxN = 0;
    int sum = nums[0];
    int num = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > num){
            sum += nums[i];
            num = nums[i];
        }else{
            maxN = max(maxN, sum);
            sum = nums[i];
            num = nums[i];
        }
    }
    return max(maxN,sum);
}
#endif //LEETCODE_MAXASCENDINGSUM1800_H
