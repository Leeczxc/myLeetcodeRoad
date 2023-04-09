#ifndef LEETCODE_BASENEG21017_H
#define LEETCODE_BASENEG21017_H
#include "iostream"
#include "vector"
#include "stack"

using namespace std;
// û�㶮
string baseNeg2(int n) {
    string ans = "";
    stack<int> nums;
    while(n != 0){
        if(abs(n) > 2){
            nums.emplace(abs(n) % 2);
            n
        }
    }
}
#endif //LEETCODE_BASENEG21017_H
