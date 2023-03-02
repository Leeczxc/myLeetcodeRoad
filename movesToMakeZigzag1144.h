#ifndef LEETCODE_MOVESTOMAKEZIGZAG1144_H
#define LEETCODE_MOVESTOMAKEZIGZAG1144_H
#include "iostream"
#include "vector"

using namespace std;

int movesToMakeZigzag(vector<int>& nums) {
    vector<int> ans;
    vector<bool> big{true, false};
    for(auto c : big){
        for(int i = 1; i < nums.size() - 1; i++){
            if(c){
                while(nums[i] > nums[i - 1]){
                    nums
                }
            }
        }
    }
}
#endif //LEETCODE_MOVESTOMAKEZIGZAG1144_H
