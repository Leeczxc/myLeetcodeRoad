//
// Created by Lee on 2022/10/11.
//

#ifndef LEETCODE_AREALMOSTEQUAL1790_H
#define LEETCODE_AREALMOSTEQUAL1790_H
#include "iostream"
#include "vector"

using namespace std;

bool areAlmostEqual(string s1, string s2) {
    size_t size = s1.size();
    vector<int> notSamePos;
    for(int i = 0; i < size; i++){
        if(s1[i] != s2[i])
            notSamePos.emplace_back(i);
    }
    if(notSamePos.size() > 2)
        return false;
    if(notSamePos.size() == 2) {
        swap(s1[notSamePos[0]], s1[notSamePos[1]]);
    }

    return s1 == s2;
}
#endif //LEETCODE_AREALMOSTEQUAL1790_H
