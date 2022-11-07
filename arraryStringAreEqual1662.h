//
// Created by Lee on 2022/11/1.
//

#ifndef LEETCODE_ARRARYSTRINGAREEQUAL1662_H
#define LEETCODE_ARRARYSTRINGAREEQUAL1662_H
#include "iostream"
#include "vector"

using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string str1 = "";
    for(auto c : word1){
        str1 += c;
    }
    string str2 = "";
    for(auto c : word2){
        str2 += c;
    }
    return str1 == str2;
}
#endif //LEETCODE_ARRARYSTRINGAREEQUAL1662_H
