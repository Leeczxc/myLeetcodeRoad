#ifndef LEETCODE_REINITIALIZEPERMUTATION1806_H
#define LEETCODE_REINITIALIZEPERMUTATION1806_H
#include "iostream"
#include "vector"

using namespace std;

bool check(vector<int>& nums, int& n){
    for(int i = 0; i < n; i++)
        if(nums[i] != i)
            return false;
    return true;
}

int reinitializePermutation(int n) {
    vector<int> pre(n, 0);
    vector<int> tem(n, 0);
    for(int i = 0; i < n; i++){
        pre[i]  = i;
    }
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            tem[i] = pre[i / 2];
        }else{
            tem[i] = pre[n / 2 + (i - 1) / 2];
        }
    }
    pre = tem;
    int ans = 1;
    while(!check(pre, n)){
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                tem[i] = pre[i / 2];
            }else{
                tem[i] = pre[n / 2 + (i - 1) / 2];
            }
        }
        pre = tem;
        ans++;
    }
    return ans;
}
#endif //LEETCODE_REINITIALIZEPERMUTATION1806_H
