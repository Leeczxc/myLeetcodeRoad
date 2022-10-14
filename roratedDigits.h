#ifndef LEETCODE_RORATEDDIGITS_H
#define LEETCODE_RORATEDDIGITS_H
#include "iostream"
#include "vector"

using namespace std;

int getRotatedValue(int n){
    switch (n) {
        case 0 : return 0;
        case 1 : return 1;
        case 8 : return 8;
        case 2 : return 5;
        case 5 : return 2;
        case 6 : return 9;
        case 9 : return 6;
        default: return -1;
    }
}

bool rotatedValue(int n){
    vector<int> nums;
    while(n != 0){
        nums.emplace_back(n % 10);
        n = n / 10;
    }
    vector<int> r_num;
    for(auto c : nums){
        if(getRotatedValue(c) == -1){
            return false;
        }
        r_num.emplace_back(getRotatedValue(c));
    }
    bool same = true;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != r_num[i])
            same = false;
    }
    if(!same)
        return true;
    return false;
}

int rotatedDigits(int n) {
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(rotatedValue(i))
            ans++;
    }
    return ans;
}
#endif //LEETCODE_RORATEDDIGITS_H
