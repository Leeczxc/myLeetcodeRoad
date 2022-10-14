//
// Created by Lee on 2022/9/27.
//

#ifndef LEETCODE_CHECKPERMUTATION_H
#define LEETCODE_CHECKPERMUTATION_H
#include "iostream"
#include "string"
#include "map"
using namespace std;

bool CheckPermutation(string s1, string s2) {
    map<char, int> numS1;
    map<char, int> numS2;
    if(s1.size() != s2.size())
        return false;
    for(int i = 0; i < s1.size(); i++){
        numS1[s1[i]]++;
        numS2[s2[i]]++;
    }
    auto it = numS1.begin();
    while(it != numS1.end()){
        auto c = numS2.find(it->first);
        if(c == numS2.end())
            return false;
        if(c->second != it->second)
            return false;
        it++;
    }
    return true;
}
#endif //LEETCODE_CHECKPERMUTATION_H
