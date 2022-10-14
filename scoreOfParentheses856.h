//
// Created by Lee on 2022/10/11.
//

#ifndef LEETCODE_SCOREOFPARENTHESES856_H
#define LEETCODE_SCOREOFPARENTHESES856_H
#include "iostream"
#include "vector"

using namespace std;

int scoreOfParentheses(string s){
    if(s.size() == 2)
        return 1;
    int bal = 0, size = s.size(), len;
    for(int i = 0; i < size; i++){
        bal += (s[i] == '(' ? 1 : -1);
        if(bal == 0){
            len = i + 1;
            break;
        }
    }
    if(len == size){
       return 2 * scoreOfParentheses(s.substr(1, size-2));
    }
    else
        return scoreOfParentheses(s.substr(0, len))
        + scoreOfParentheses(s.substr(len,size - len));
}

#endif //LEETCODE_SCOREOFPARENTHESES856_H
