//
// Created by Lee on 2022/11/6.
//

#ifndef LEETCODE_INTERPRET1678_H
#define LEETCODE_INTERPRET1678_H
#include "iostream"
#include "stack"

using namespace std;

string interpret(string command) {
    string ans = "";
    string temp = "";
    for(auto c : command){
        switch (c) {
            case 'G': ans += 'G'; break;
            case ')': temp += ')';
                if(temp != "()")
                    ans += 'al';
                else
                    ans += 'o';
                temp.clear();
                    break;
            default:
                temp += c;
        }
    }
    return ans;
}
#endif //LEETCODE_INTERPRET1678_H
