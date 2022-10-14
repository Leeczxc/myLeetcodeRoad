//
// Created by Lee on 2022/10/3.
//

#ifndef LEETCODE_REFORMATNUMBER1694_H
#define LEETCODE_REFORMATNUMBER1694_H
#include "iostream"
#include "vector"

using namespace std;

string reformatNumber(string number) {
    auto it = number.begin();
    string temp;
    while(it != number.end()){
        if(*it != ' ' && *it != '-')
            temp += *it;
        it++;
    }
    size_t size = temp.size();
    if(size <= 3)
        return temp;
    string ans;
    if(size % 3 == 1){
        int t = size / 3 - 1;
        for(int i = 0; i < size; i++){
            if(i % 3 == 0 && t >= 0){
                t--;
                ans += '-';
            }
            ans += temp[i];
        }
        ans.insert(ans.size() - 2, 1, '-');
    }else{
        for(int i = 0; i < size; i++){
            if(i % 3 == 0)
                ans += '-';
            ans += temp[i];
        }
    }
    ans.erase(ans.begin());
    return ans;
}

#endif //LEETCODE_REFORMATNUMBER1694_H

