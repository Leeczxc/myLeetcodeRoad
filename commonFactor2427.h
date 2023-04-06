#ifndef LEETCODE_COMMONFACTOR2427_H
#define LEETCODE_COMMONFACTOR2427_H
#include "iostream"

using namespace std;

int commonFactors(int a, int b) {
    int ans = 1;
    for(int i = 2; i <= min(a, b); i++){
        if(a % i == 0 && b % i == 0)
            ans++;
    }
    return ans;
}
#endif //LEETCODE_COMMONFACTOR2427_H
