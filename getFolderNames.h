#ifndef LEETCODE_GETFOLDERNAMES_H
#define LEETCODE_GETFOLDERNAMES_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

// œÎ¬È∑≥¡À
//pair<string, int> spillFolder(string& str){
//    char c = '(';
//    auto ite = find(str.begin(), str.end(), c);
//    if(ite == str.end()){
//        return pair<string, int>(string(str.begin(), ite), 0);
//    }
//    return pair<string, int>(string(str.begin(), ite), stoi(string(ite + 1, str.end())));
//}
//
//vector<string> getFolderNames(vector<string>& names) {
//    map<string, vector<int>> strTimes;
//    for(int i = 0; i < names.size(); ++i){
//        auto x = spillFolder(names[i]);
//        strTimes[x.first].emplace_back(x.second);
//    }
//    for(auto c : strTimes){
//        sort(c.second.begin(), c.second.end());
//    }
//
//}

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> d;
        for (auto& name : names) {
            int k = d[name];
            if (k) {
                while (d[name + "(" + to_string(k) + ")"]) {
                    k++;
                }
                d[name] = k;
                name += "(" + to_string(k) + ")";
            }
            d[name] = 1;
        }
        return names;
    }
};


#endif //LEETCODE_GETFOLDERNAMES_H
