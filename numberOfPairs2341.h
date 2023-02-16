#ifndef LEETCODE_NUMBEROFPAIRS2341_H
#define LEETCODE_NUMBEROFPAIRS2341_H
#include "iostream"
#include "vector"
#include "map"

using namespace std;

vector<int> numberOfPairs(vector<int>& nums) {
    map<int, int> times;
    for(auto c: nums)
        times[c]++;
    int time = 0;
    int last = 0;
    auto it = times.begin();
    while(it != times.end()){
        time += it->second / 2;
        last += it->second % 2;
        it++;
    }
    return vector<int>{time, last};
}
#endif //LEETCODE_NUMBEROFPAIRS2341_H
