#ifndef LEETCODE_FILLCUPS2335_H
#define LEETCODE_FILLCUPS2335_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int fillCups(vector<int>& amount) {
    sort(amount.begin(), amount.end());
    if((amount[0] + amount[1]) <= amount[2]){
        return amount[2];
    } else{
        int t = amount[0] + amount[1] - amount[2];
        return (t + 1) / 2;
    }
}
#endif //LEETCODE_FILLCUPS2335_H
