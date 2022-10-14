//
// Created by Lee on 2022/10/3.
//

#ifndef LEETCODE_CHECKONESSEGMENT_H
#define LEETCODE_CHECKONESSEGMENT_H
#include "iostream"
#include "string"

using namespace std;

bool checkOnesSegment(string s) {
    size_t size = s.size();
    if(size == 1)
        return true;
    int ans = 0;
    bool hasOne = true;
    for(int i = 1; i < size; i++){
        if(s[i] == '1'){
            hasOne = true;
        }else{
            if(hasOne)
                ans++;
            hasOne = false;
        }
    }
    if(s[s.size() - 1] == '1')
        ans++;
    return ans <= 1;
}
#endif //LEETCODE_CHECKONESSEGMENT_H
