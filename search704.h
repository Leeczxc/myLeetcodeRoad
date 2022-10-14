//
// Created by Lee on 2022/10/12.
//

#ifndef LEETCODE_SEARCH704_H
#define LEETCODE_SEARCH704_H
#include "iostream"
#include "vector"

using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    // 防止溢出的写法 mid = start + (end - start) / 2;
    int mid = (start + end) / 2;
    int pos = -1;
    while(start <= end){
        if(nums[mid] == target){
            pos = mid;
            break;
        }else if(nums[mid] < target)
            start = mid + 1;
        else
            end = mid -1;
        // 防止溢出的写法 mid = start + (end - start) / 2;
        mid =  (start + end) / 2;
    }
    return pos;
}

#endif //LEETCODE_SEARCH704_H
