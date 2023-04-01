#ifndef LEETCODE_ARITHMETICTRIPLETS2367_H
#define LEETCODE_ARITHMETICTRIPLETS2367_H
#include "iostream"
#include "vector"
#include "map"

using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
    map<int, int> times;
    for(auto& c : nums){
       times[c]++;
    }
    int ans = 0;
    auto ite = times.rbegin();
    while(ite != times.rend() && ite->first >= 2 * diff){
       if(times.find(ite->first - diff) != times.end() && times.find(ite->first - 2 * diff) != times.end())
           ans++;
       ite++;
    }
    return ans;
}
#endif //LEETCODE_ARITHMETICTRIPLETS2367_H
