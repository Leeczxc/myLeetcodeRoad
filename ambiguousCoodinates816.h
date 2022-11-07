//
// Created by Lee on 2022/11/7.
//

// 想复杂了 没必要模拟，可以根据位置坐标找到连个字符串
// 然后分别切换小树和整数 应该就可以了
// 虽然判断数字有效是很恶心

#ifndef LEETCODE_AMBIGUOUSCOODINATES816_H
#define LEETCODE_AMBIGUOUSCOODINATES816_H
#include "iostream"
#include "vector"

using namespace std;

vector<string> result;

bool isValidDigit(string& s1){
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == '0')

    }
}

bool isValid(string& s, int pos1, int pos2, int mode){
    string t(s);
    if(mode == 1){
        t.insert(s.begin() + pos2 + 1, '.');
        t.insert(s.begin() + pos1 + 1, ',');
    }else{
        t.insert(s.begin() + pos2 + 1, ',');
        t.insert(s.begin() + pos1 + 1, '.');
    }
    string t1, t2;
    bool ok = false;
    for(int i = 0; i < s.size(); i++){
        if(ok)
            t2 += s[i];
        else if(s[i] != ',')
            t1 += s[i];
        else
            ok = true;
    }
    if(isValidDigit(t1) && isValidDigit(t2))
        return true;
    return false;
}

void backTracking(string& s,int pos1, int pos2){
    size_t size = s.size();
    if(pos1 == size || pos2 == size)
        return;
    for(int i = pos1; i < size;i++)
        for(int j = pos2; j < size; j++){
            if(isValid(s, pos1, pos2, 1)){

            }
        }
}

vector<string> ambiguousCoordinates(string s) {
    string t;
    for(auto c : s){
       if(c == '(' || c == ')')
           continue;
       s += c;
    }

}
#endif //LEETCODE_AMBIGUOUSCOODINATES816_H
