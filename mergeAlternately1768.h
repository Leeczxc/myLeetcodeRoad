//
// Created by Lee on 2022/10/23.
//

#ifndef LEETCODE_MERGEALTERNATELY1768_H
#define LEETCODE_MERGEALTERNATELY1768_H
#include "iostream"
#include "string"

using namespace std;

string mergeAlternately(string word1, string word2) {
    size_t size = min(word1.size(), word2.size());
    string ans;
    int pos = 0;
    for(; pos < size; pos++) {
        ans.push_back(word1[pos]);
        ans.push_back(word2[pos]);
    }
    if(word1.size() > pos){
        while(pos < word1.size())
            ans.push_back(word1[pos++]);
    } else if( word2.size() > pos){
        while(pos < word2.size())
            ans.push_back(word2[pos++]);
    }
    return ans;
}
#endif //LEETCODE_MERGEALTERNATELY1768_H
