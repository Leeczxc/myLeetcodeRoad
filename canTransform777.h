//
// Created by Lee on 2022/10/3.
//

#ifndef LEETCODE_CANTRANSFORM777_H
#define LEETCODE_CANTRANSFORM777_H
#include "iostream"
#include "string"

using namespace std;

bool canTransform(string start, string end) {
    int n = start.length();
    int i = 0, j = 0;
    while(i < n && j < n){
        while(i < n && start[i] == 'X'){
            i++;
        }
        while(j < n && start[j] == 'X'){
            j++;
        }
        if(i < n && j < n){
            if(start[i] != end[j]){
                return false;
            }
            char c = start[i];
            if((c == 'L' && i < j) || (c == 'R' && i > j))
                return false;
            i++;
            j++;
        }
    }
    while(i < n){
        if(start[i] != 'X'){
            return false;
        }
        i++;
    }
    while(j < n){
        if(start[j] != 'X'){
                return false;
        }
        i++;
    }
    return true;
}
#endif //LEETCODE_CANTRANSFORM777_H
