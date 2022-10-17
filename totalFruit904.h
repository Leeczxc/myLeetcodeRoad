//
// Created by Lee on 2022/10/17.
//

#ifndef LEETCODE_TOTALFRUIT904_H
#define LEETCODE_TOTALFRUIT904_H
#include "iostream"
#include "vector"
#include "map"

using namespace std;

int totalFruit(vector<int>& fruits) {
    map<int, int> cat;
    int sum = 0;
    int maxNum = 0;
    for(int i = 0; i < fruits.size(); i++){
        cat[fruits[i]]++;
        sum++;
        while(cat.size() > 2){
            cat[fruits[i - sum + 1]]--;
            if(cat[fruits[i - sum + 1]] == 0)
                cat.erase(fruits[i - sum + 1]);
            sum--;
        }
        maxNum = max(maxNum, sum);
    }
    return maxNum;
}
#endif //LEETCODE_TOTALFRUIT904_H
