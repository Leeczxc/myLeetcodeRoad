#ifndef LEETCODE_PREFIXCOUNT2185_H
#define LEETCODE_PREFIXCOUNT2185_H
#include "iostream"
#include "vector"

using namespace std;

int prefixCount(vector<string>& words, string pref) {
    int ans = 0;
    size_t size = pref.size();
    for(auto c : words){
        if(c.size() < size)
            continue;
        string str = c.substr(0, size);
        if(str == pref)
            ans++;
    }
    return ans;
}
#endif //LEETCODE_PREFIXCOUNT2185_H
