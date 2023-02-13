#ifndef LEETCODE_BALANCESTRING1234_H
#define LEETCODE_BALANCESTRING1234_H
#include "iostream"
#include "vector"

using namespace std;

// 滑动窗口
// 这里是错的
// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/solution/ti-huan-zi-chuan-de-dao-ping-heng-zi-fu-f8fk8/
int balancedString(string s) {
//    vector<int> times(4, 0);
//    for(auto c : s){
//        if(c == 'Q'){
//            times[0]++;
//        }else if(c == 'W'){
//            times[1]++;
//        }else if(c == 'E'){
//            times[2]++;
//        }else
//            times[3]++;
//    }
//    size_t size = s.size();
//    int num = size / 4;
//    int ans = 0;
//    for(int i = 0; i < 4; i++){
//        if(times[i] > num)
//            ans += times[i] - num;
//    }
//    return ans;
    vector<int> cnt(26, 0);
    for(auto c : s){
        cnt[c - 'A']++;
    }
    int nums = s.size() / 4;
    int res = s.size();
    auto check = [&](){
        if(cnt['Q' - 'A'] > nums || cnt['W' - 'A'] > nums || cnt['E' - 'A'] > nums || cnt['R' - 'A'] > nums)
            return false;
        return true;
    };

    if(check())
        return 0;
    for(int l = 0, r = 0; r < s.size(); l++){
        while(r < s.size() && !check()){
            cnt[s[r] - 'A']--;
            r++;
        }
        if(!check())
            return false;
        res = min(res, r - l);
        cnt[s[l] - 'A']++;
    }
    return res;
}
#endif //LEETCODE_BALANCESTRING1234_H
