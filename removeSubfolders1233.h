#ifndef LEETCODE_REMOVESUBFOLDERS1233_H
#define LEETCODE_REMOVESUBFOLDERS1233_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
bool isPrefix(string s1, string s2){
    size_t size = s1.size();
    string s = s2.substr(0,size);
    if(s == s1){
        if(s2.size() > size && s2[size] == '/')
            return true;
    }
    return false;
}

vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    size_t size = folder.size();
    int pre = 0;
    int now = 1;
    vector<string> ans;
    ans.emplace_back(folder[pre]);
    while(now < size){
        if(!isPrefix(folder[pre], folder[now])){
            ans.emplace_back(folder[now]);
            pre = now;
        }
            now++;
    }
    return ans;
}
#endif //LEETCODE_REMOVESUBFOLDERS1233_H
