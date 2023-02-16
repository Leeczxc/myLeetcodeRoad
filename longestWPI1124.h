#ifndef LEETCODE_LONGESTWPI1124_H
#define LEETCODE_LONGESTWPI1124_H
#include "iostream"
#include "vector"

using namespace std;
// 前缀和+单调栈
// 哈希表也可以
// 多看看这个
bool tired(int x){
    if(x > 8)
        return true;
    return false;
}

int longestWPI(vector<int>& hours) {
    int ans = INT_MAX;
    int tir = 0, untired = 0;
    int left = 0, right = 0;
    while(left <= right && right < hours.size()){
        while(tir <= untired && right < hours.size()){
            if(tired(hours[right++]))
                tir++;
            else
                untired++;
        }
        ans = min(ans, tir + untired);

    }
    return ans;
}