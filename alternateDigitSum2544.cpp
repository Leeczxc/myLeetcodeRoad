#include <iostream>

using namespace std;

int alternateDigitSum(int n)
{
    int ans = 0;
    bool even = true;
    int temp = 0;
    while(n != 0){
        temp = n % 10;
        n = n / 10;
        if(even){
            ans += temp;
        }else{
            ans -= temp;
        }
        even = !even;
    }
    return even? - ans : ans;
}