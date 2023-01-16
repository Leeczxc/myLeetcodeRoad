#ifndef LEETCODE_MINMAXGAME2293_H
#define LEETCODE_MINMAXGAME2293_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int minMaxGame(vector<int>& nums) {
    vector<int> ans;
    ans = nums;
    while(ans.size() != 1){
        vector<int> newNums = ans;
        int size = ans.size() / 2;
        ans.clear();
        for(int i = 0; i < size; i++){
            if(i % 2 == 0)
                ans.emplace_back(min(ans[2 * i], ans[2 * i + 1]));
            else
                ans.emplace_back(max(ans[2 * i], ans[2 * i + 1]));
        }
    }
    return ans[0];
}
#endif //LEETCODE_MINMAXGAME2293_H
