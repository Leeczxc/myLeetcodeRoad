//
// Created by Lee on 2022/10/12.
//

#ifndef LEETCODE_REMOVEELEMENT27_H
#define LEETCODE_REMOVEELEMENT27_H
#include "iostream"
#include "vector"

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != val)
            nums[index++] = nums[i];
    }
    return index;
}
#endif //LEETCODE_REMOVEELEMENT27_H
