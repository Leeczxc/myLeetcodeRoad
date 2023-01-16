#ifndef LEETCODE_EVALUATE1807_H
#define LEETCODE_EVALUATE1807_H
#include "iostream"
#include "vector"
#include "map"

using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
    map<string, string> keys;
    for(auto c: knowledge){
        keys[c[0]] = c[1];
    }
    string ans = "";
    string temp = "";
    bool hasBracket = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            hasBracket = true;
            continue;
        }
        if(s[i] == ')'){
            hasBracket = false;
            auto ite = keys.find(temp);
            if(ite == keys.end())
                ans += '?';
            else
                ans += keys[temp];
            temp = "";
            continue;
        }
        if(hasBracket)
            temp += s[i];
        else
            ans += s[i];
    }
    return ans;
}
#endif //LEETCODE_EVALUATE1807_H
