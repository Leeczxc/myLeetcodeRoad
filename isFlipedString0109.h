//
// Created by Lee on 2022/9/29.
//

#ifndef LEETCODE_ISFLIPEDSTRING0109_H
#define LEETCODE_ISFLIPEDSTRING0109_H
#include "iostream"
#include "string"

using namespace std;

bool isFlipedString(string s1, string s2) {
    if(s1.size() != s2.size())
        return false;
    char c = s2[s2.size() - 1];
    int pos = 0;
    string start;
    while(pos  < s1.size()){
        start += s1[pos];
        if(s1[pos] == c){
            string temp;
            if(pos !=  s1.size())
                temp = s1.substr(pos + 1,s1.size() - pos);
            temp += start;
            if(temp == s2)
                return true;
        }
        pos++;
    }
    return false;
}
#endif //LEETCODE_ISFLIPEDSTRING0109_H
