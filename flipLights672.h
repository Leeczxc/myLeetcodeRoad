//
// Created by Lee on 2022/9/15.
//
#include "iostream"
#include "unordered_set"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

vector<string> getAllString(string& s){
    string s1(s);
    vector<string> ans;
    size_t size = s.size();
    for(int i = 0; i < size; i++){
        if(s1[i] == '0')
            s1[i] = '1';
        else
            s1[i] = '0';
    }
    string s2(s);
    for(int i = 1; i < size; i += 2){
        if(s2[i] == '0')
            s2[i] = '1';
        else
            s2[i] = '0';
    }
    string s3(s);
    for(int i = 0; i < size; i += 2){
        if(s3[i] == '0')
            s3[i] = '1';
        else
            s3[i] = '0';
    }

    string s4(s);
    for(int i = 0; i < size; i += 3){
        if(s4[i] == '0')
            s4[i] = '1';
        else
            s4[i] = '0';
    }
    ans.emplace_back(s1);
    ans.emplace_back(s2);
    ans.emplace_back(s3);
    ans.emplace_back(s4);
    return ans;
}

int flipLights(int n, int presses) {
    if(presses == 0)
        return 0;
    string ligth(n, '0');
    vector<string> ans;
    auto c = getAllString(ligth);
    ans.emplace_back(c[0]);
    ans.emplace_back(c[1]);
    ans.emplace_back(c[2]);
    ans.emplace_back(c[3]);
    sort(ans.begin(), ans.end());
    auto t = unique(ans.begin(), ans.end());
    ans.erase(t, ans.end());

    for(int i = 0; i < presses - 1; i++){
        size_t size = ans.size();
        for(int j = 0; j < size; j++){
            auto it = ans.begin();
            auto c = getAllString(*it);
            ans.erase(it);
            ans.emplace_back(c[0]);
            ans.emplace_back(c[1]);
            ans.emplace_back(c[2]);
            ans.emplace_back(c[3]);
        }
        sort(ans.begin(), ans.end());
        auto c = unique(ans.begin(), ans.end());
        ans.erase(c, ans.end());
    }
    return ans.size();
}

