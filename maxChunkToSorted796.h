//
// Created by Lee on 2022/10/14.
//

#ifndef LEETCODE_MAXCHUNKTOSORTED796_H
#define LEETCODE_MAXCHUNKTOSORTED796_H
#include "iostream"
#include "vector"

using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    if(arr.size() == 1)
        return 1;
    int ans = 0;
    int max = arr[0];

    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
            if(max == i)
               ans++;
        }
    }
    return ++ans;
}

#endif //LEETCODE_MAXCHUNKTOSORTED796_H

