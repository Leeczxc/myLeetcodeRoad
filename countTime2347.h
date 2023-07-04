#ifndef LEETCODE_COUNTTIME2347_H
#define LEETCODE_COUNTTIME2347_H
#include "iostream"
#include "vector"

using namespace std;

int countTime(string time) {
    int left = 1;
    if(time[0] == '?'){
        if(time[1] == '?'){
            left = 24;
        }else{
            if(time[1] > '3'){
                left = 2;
            } else{
                left = 3;
            }
        }
    } else{
        if(time[1] == '?'){
            if(time[0] <= '1'){
                left = 10;
            }else{
                left = 4;
            }
        }
    }

    int right = 1;
    if(time[3] == '?'){
        if(time[4] == '?')
            right = 60;
        else
            right = 6;
    } else{
        if(time[4] == '?')
            right = 10;

    }
    return left * right;
}
#endif //LEETCODE_COUNTTIME2347_H
