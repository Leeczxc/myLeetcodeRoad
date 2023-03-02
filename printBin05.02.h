#ifndef LEETCODE_PRINTBIN05_02_H
#define LEETCODE_PRINTBIN05_02_H
#include "iostream"
#include "vector"

using namespace std;

string printBin(double num) {
    string ans("0.");
    int times = 2;
    double temp(num);
    temp *= 2;
    while(temp != 0.2 && temp != 0 && ++times <= 32){
        if(temp > 1){
            temp -= 1;
            ans += '1';
        }else if (temp == 1){
            ans += '1';
            temp -= 1;
            break;
        }else
            ans += '0';
        temp *= 2;
    }
    if(temp == 0.2 || times > 32)
        ans = "ERROR";
    return ans;
}
#endif //LEETCODE_PRINTBIN05_02_H
