//
// Created by Lee on 2022/10/28.
//

#ifndef LEETCODE_ARRAYSIGN1822_H
#define LEETCODE_ARRAYSIGN1822_H
#include "iostream"
#include "vector"

using namespace std;

int arraySign(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    auto func = [](int& num){
        if(num == 0)
            return 0;
        if(num > 0)
            return  1;
        return -1;
    };
    int ans = func(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == 0)
            return 0;
        ans *= func(nums[i]);
    }
    return ans;
}
#endif //LEETCODE_ARRAYSIGN1822_H
