#ifndef LEETCODE_ALERTNAMES1604_H
#define LEETCODE_ALERTNAMES1604_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"
#include "string"

using namespace std;


// 更快的方式是把小时转化成分钟

bool hasThree(vector<string>& times){
    size_t size = times.size();
    if(size < 3){
        return false;
    }
    string ans = "";
    int h1, h2;
    int m1, m2;
    for(int i = size - 1; i >= 2; i--){
        h1 = stoi(times[i].substr(0, 2));
        h2 = stoi(times[i - 2].substr(0, 2));
        m1 = stoi(times[i].substr(3, 2));
        m2 = stoi(times[i - 2].substr(3, 2));
        if(h1 == h2)
            return true;
        else if((h1 - h2) == 1 && m1 <= m2){
            return true;
        }
    }
    return false;
}

vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    size_t size = keyName.size();
    map<string, vector<string>> times;
    for(int i = 0; i < size; i++){
        times[keyName[i]].emplace_back(keyTime[i]);
    };
    auto ite = times.begin();
    while(ite != times.end()){
        sort(ite->second.begin(), ite->second.end(), [](string a, string b){
            int h1,h2,m1,m2;
            h1 = stoi(a.substr(0, 2));
            h2 = stoi(b.substr(0, 2));
            m1 = stoi(a.substr(3, 2));
            m2 = stoi(b.substr(3, 2));
            if(h1 == h2)
                return m1 < m2;
            else
                return h1 < h2;
        });
        ite++;
    }
    vector<string> ans;
    ite = times.begin();
    while(ite != times.end()){
        if(hasThree(ite->second)){
            ans.emplace_back(ite->first);
        }
        ite++;
    }
    return ans;
}
#endif //LEETCODE_ALERTNAMES1604_H
