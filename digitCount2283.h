#ifndef LEETCODE_DIGITCOUNT2283_H
#define LEETCODE_DIGITCOUNT2283_H
#include "iostream"
#include "string.h"
#include "map"

using namespace std;

bool digitCount(string num) {
    map<int, int> times;
    for(auto c : num)
        times[c - '0']++;
    for(int i = 0; i < num.size(); i++)
        if(times[i] != (num[i] - '0'))
            return false;
    return true;
}
#endif //LEETCODE_DIGITCOUNT2283_H
