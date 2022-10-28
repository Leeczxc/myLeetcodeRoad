//
// Created by Lee on 2022/10/28.
//

#ifndef LEETCODE_SUMSUBARRAYMINS907_H
#define LEETCODE_SUMSUBARRAYMINS907_H
#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"

using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    // 超时
//    int sum = 0;
//    for(int start = 0; start < arr.size(); start++){
//        int m_min = arr[start];
//        for(int end = start; end < arr.size(); end++){
//            m_min = min(m_min,arr[end]);
//            if(m_min + sum >= (pow(10, 9) + 7))
//                sum -= (pow(10, 9) + 7);
//            sum += m_min;
//        }
//    }
//    return sum;
    int n = arr.size();
    vector<int> monoStack;
    vector<int> left(n), right(n);
    for(int i = 0; i < n; i++){
        while(!monoStack.empty() && arr[i] <= arr[monoStack.back()]){
            monoStack.pop_back();
        }
        left[i] = i - (monoStack.empty() ? -1 : monoStack.back());
        monoStack.emplace_back(i);
    }
    monoStack.clear();
    for(int i = n - 1; i > 0; i--){
        while(!monoStack.empty() && arr[i] < arr[monoStack.back()]){
            monoStack.pop_back();
        }


    }
    monoStack.clear();

}
#endif //LEETCODE_SUMSUBARRAYMINS907_H
