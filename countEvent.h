#ifndef LEETCODE_COUNTEVENT_H
#define LEETCODE_COUNTEVENT_H
#include "iostream"

using namespace std;

int countEven(int num) {
    int ans = 0;
    int a = num / 100;
    int b = num % 100;
    // 处理百位
    int temp1 = a / 2;
    int temp2 = a % 2;
    ans = temp1 * 100 + temp2 * 50;
    if(a )
        ans--;
    // 处理十位
    int t1 = b / 10;
    int t2 = b % 10;
    if(a > 0)
        ans += t1 * 5;
    else
        ans += t1 * 5 - 1;
    for(int i = 0; i<= t2; i++)
        if((a + t1 + i) % 2 == 0)
            ans++;
    return ans;
}
#endif //LEETCODE_COUNTEVENT_H
