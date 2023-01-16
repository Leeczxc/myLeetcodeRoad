#ifndef LEETCODE_MINOPERATIONS1658_H
#define LEETCODE_MINOPERATIONS1658_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 错误答案 dfs
// 超出时间限制
// 应该使用滑动窗口 效率更高啊 不用递归

vector<int> allAns;
void dfs(vector<int> nums, int x, int times, int start, int end){
    if(x == 0){
        allAns.emplace_back(times);
        return;
    }
    if(start > end)
        return;
    if(x - nums[start] >= 0){
        dfs(nums, x - nums[start], times + 1, start + 1, end);
    }
    if(start == end)
        return;
    if(x - nums[end] >= 0){
        dfs(nums, x - nums[end], times + 1, start, end - 1);
    }
    return;
}


int minOperations(vector<int>& nums, int x) {
    dfs(nums, x, 0, 0, nums.size() - 1);
    std::sort(allAns.begin(), allAns.end());
    if(allAns.size() == 0)
        return -1;
    return allAns[0];
}
#endif //LEETCODE_MINOPERATIONS1658_H
