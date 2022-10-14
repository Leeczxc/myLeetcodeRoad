//
// Created by Lee on 2022/9/28.
//

#ifndef LEETCODE_GETKTHMAGICNUMBER1709_H
#define LEETCODE_GETKTHMAGICNUMBER1709_H
#include "iostream"
#include "vector"
#include "queue"
#include "unordered_set"

using namespace std;

int getKthMagicNumber(int k) {
    vector<int> factors{3, 5, 7};
    unordered_set<long> seen;
    priority_queue<long, vector<long>, greater<long>> heap;
    seen.insert(1L);
    heap.push(1L);
    int ugly = 0;
    for(int i = 0; i < k; i++){
        long curr = heap.top();
        heap.pop();
        ugly = (int)curr;
        for(int factor: factors){
            long next = curr * factor;
            if(!seen.count(next)){
                seen.insert(next);
                heap.push(next);
            }
        }
    }
    return ugly;
}
#endif //LEETCODE_GETKTHMAGICNUMBER1709_H
