//
// Created by Lee on 2022/10/22.
//

#ifndef LEETCODE_FIB509_H
#define LEETCODE_FIB509_H
#include "iostream"
#include "vector"

using namespace std;

vector<int> nums{0, 1};
int fib(int n) {
    if(n  >= nums.size()){
        auto c = fib(n - 1) + fib(n - 2);
        nums.emplace_back(c);
        return c;
    }
    return nums[n];
}
#endif //LEETCODE_FIB509_H
