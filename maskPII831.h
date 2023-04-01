#ifndef LEETCODE_MASKPII_H
#define LEETCODE_MASKPII_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

string maskPII(string s) {
    bool hasAt{false};
    int pos = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '@'){
            hasAt = true;
            pos = i;
        }
    }
    if(hasAt){
        string ans = "";
        if(s[0] <= 'Z')
            s[0] += 32;
        ans += s[0];
        ans += string(5, '*');
        if(s[pos - 1] <= 'Z')
            s[pos -1] += 32;
        ans += s[pos -1];
        ans += '@';
        for(int i = ++pos; i < s.size(); i++){
            if(s[i] <= 'Z' && s[i] != '.')
                s[i] += 32;
            ans += s[i];
        }
        s = ans;
    }else{
        string temp = "";
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i]))
                temp += s[i];
        }
        if(temp.size() > 10){
            int length = temp.size() - 10;
            ans += '+';
            ans += string(length, '*');
            ans += '-';
        }
        ans += "***_***_";
        for(int i = temp.size() -4 ; i < temp.size(); i++){
            ans += temp[i];
        }
        s = ans;
    }
    return s;
}

#endif //LEETCODE_MASKPII_H
