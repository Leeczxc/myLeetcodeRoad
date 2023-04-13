#ifndef LEETCODE_MOSTFREQUENCY2404_H
#define LEETCODE_MOSTFREQUENCY2404_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int mostFrequentEven(vector<int>& nums) {
    map<int, int> times;
    for(auto &c : nums){
        if(c % 2 == 0){
            if(times.find(c) == times.end())
                times[c]++;
            else
                times[c]++;
        }
    }
    if(times.size() == 0)
        return -1;
    vector<pair<int, int>> num;
    for(auto &c : times){
        num.emplace_back(pair<int, int>(c.first, c.second));
    }
    sort(num.begin(), num.end(),
         [](pair<int, int> a, pair<int, int> b){
        return a.second > b.second || (a.second == b.second && a < b);
    });
    return num[0].first;
}
#endif //LEETCODE_MOSTFREQUENCY2404_H
