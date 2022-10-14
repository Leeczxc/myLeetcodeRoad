//
// Created by Lee on 2022/9/16.
//

#ifndef LEETCODE_STRING3_H
#define LEETCODE_STRING3_H

#include "iostream"
#include "string"
#include "vector"
#include "map"
using namespace std;


int lengthOfLongestSubstring(string s) {
    map<char, int> num;
    int maxSize = 0;
    for(auto c : s){
        auto it = num.find(c);
        if(it != num.end()){
            maxSize = std::max(maxSize, static_cast<int>(num.size()));
            num.clear();
        }
        num[c]++;
    }
    return max(maxSize, static_cast<int>(num.size()));
}
#endif //LEETCODE_STRING3_H
