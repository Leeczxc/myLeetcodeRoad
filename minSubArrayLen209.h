//
// Created by Lee on 2022/10/12.
//

#ifndef LEETCODE_MINSUBARRAYLEN209_H
#define LEETCODE_MINSUBARRAYLEN209_H
#include "iostream"
#include "vector"

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int allNum = 0;
    for(int num: nums){
        allNum += num;
    }
    if(allNum < target)
        return 0;
    int ans = INT32_MAX;
    for(int i = 0; i < nums.size(); i++){
        int sum = nums[i];
        if(sum >= target){
            return 1;
        }else{
            if(i == nums.size() -1){
                break;
            }
            int temp = 1;
            for(int j = i + 1; j < nums.size(); j++){
                if((sum += nums[j]) >= target){
                    temp++;
                    ans = min(ans, temp);
                    break;
                }
                temp++;
            }
        }
    }
    if(ans == INT32_MAX)
        ans = 0;
    return ans;
}
#endif //LEETCODE_MINSUBARRAYLEN209_H
