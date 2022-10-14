//
// Created by Lee on 2022/9/17.
//

#ifndef LEETCODE_MAXLENGTH1624_H
#define LEETCODE_MAXLENGTH1624_H
#include "iostream"
#include "map"
#include "vector"

using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    map<char, vector<int>> chars;
    for(int pos = 0; pos < s.size(); pos++) {
        chars[s[pos]].emplace_back(pos);
    }
    int ans = -1;
    auto it = chars.begin();
    while(it != chars.end()){
        auto t = it->second;
        std::sort(t.begin(), t.end());
        if(t.size() != 1) {
            int first = t[0];
            int end = t[t.size()-1];
            ans = max(ans, end - first -1);
        }
        it++;
    }
    return ans;
}
#endif //LEETCODE_MAXLENGTH1624_H
