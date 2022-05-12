#include "iostream"
#include "math.h"

using namespace std;

//好像只有偶数

int largestPalindrome(int n) {
    if (n == 1)
        return 9;
    int max = pow(10, n) - 1;
    for(int left = max ;; --left){
        long p = left;
        for(int x = left; x > 0; x/=10){
            p = p * 10 + x % 10;
        }
        for(long x = max; x * x > p; --x){
            if(p % x==0)
                return p % 1337;
        }
    }
}

int main(){
    cout << largestPalindrome(2) << endl;
}