#ifndef LEETCODE_MINIMUMOPERATIONS2357_H
#define LEETCODE_MINIMUMOPERATIONS2357_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 还是麻烦了 就是找不同非零数字的数量
int minimumOperations(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    auto ite = std::find_if(nums.begin(), nums.end(),[](int x){
        return x > 0;
    });
    int ans = 0;
    int reduce = 0;
    while(ite != nums.end()){
        if(*ite > reduce){
            reduce = *ite;
            ans++;
        }
        ite++;
    }
    return ans;
}
#endif //LEETCODE_MINIMUMOPERATIONS2357_H
