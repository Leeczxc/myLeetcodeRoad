#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 数学题
/*
 * 当 n=2n = 2n=2 时，0≤x<1000 \le x \lt 1000≤x<100，xxx 的选择可以由两部分构成：只有一位数的 xxx 和有两位数的 xxx。只有一位数的 xxx 可以由上述的边界情况计算。有两位数的 xxx 可以由组合数学进行计算：第一位的选择有 999 种，即 1∼91 \sim 91∼9，第二位的选择也有 999 种，即 0∼90 \sim 90∼9 中除去第一位的选择。
更一般地，含有 ddd （2≤d≤102 \le d \le 102≤d≤10）位数的各位数字都不同的数字 xxx 的个数可以由公式 9×A9d−19 \times A_9^{d-1}9×A9d−1​ 计算。再加上含有小于 ddd 位数的各位数字都不同的数字 xxx 的个数，即可得到答案
 * */
int countNumbersWithUniqueDigits(int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return 10;
    int ans = 10, cur = 9;
    for(int i = 0; i < n -1; i++){
        cur *= 9 - i;
        ans += cur;
    }
    return ans;
}
int main() {
    cout << countNumbersWithUniqueDigits(2) << endl;
    cout << countNumbersWithUniqueDigits(0) << endl;
}
