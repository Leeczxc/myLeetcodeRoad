#include <iostream>
#include <vector>

using namespace std;

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int res  = 0;
    if(k < numOnes){
        return k;
    }
    res += numOnes;
    k -= numOnes;
    if(k < numZeros){
        return res;
    }
    k -= numZeros;
    return res - k;
}