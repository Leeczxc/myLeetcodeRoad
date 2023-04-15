#ifndef LEETCODE_CAMELMATCH1023_H
#define LEETCODE_CAMELMATCH1023_H
#include "iostream"
#include "vector"

using namespace std;
// ∞¥’’À≥–ÚºÏ≤È
bool checkCamel(string& str, string& pattern){
    int bigStr = 0, bigPatter = 0;
    int posStr = 0, posPatter = 0;
    for(int i = 0; i < str.size(); i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            bigStr++;

    for(int j = 0; j < pattern.size(); j++)
        if(pattern[j] >= 'A' && pattern[j] <= 'Z')
            bigPatter++;

    if(bigStr != bigPatter)
        return false;
    while(posStr < str.size() && posPatter < pattern.size()){
        if(str[posStr] == pattern[posPatter]){
            posStr++;
            posPatter++;
        }else{
            posStr++;
        }
    }
    if(posPatter != pattern.size())
        return false;
    return true;
}

vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;
    for(auto &c : queries)
        ans.emplace_back(checkCamel(c, pattern));
    return ans;
}
#endif //LEETCODE_CAMELMATCH1023_H
