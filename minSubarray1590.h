#ifndef LEETCODE_MINSUBARRAY1590_H
#define LEETCODE_MINSUBARRAY1590_H
#include "iostream"
#include "vector"
#include "map"
#include "unordered_map"

using namespace std;

int minSubarray(vector<int>& nums, int p) {
//    map<int, int> times;
//    int sum = 0;
//    for(auto& c : nums){
//        times[c]++;
//        sum += c;
//    }
//    if(sum == p)
//        return 0;
//    if(sum < p){
//        return -1;
//    }
//    int last = sum % p;
    int target = 0, ans = nums.size(), sum = 0, res;
    for(int& num : nums){
        target = (target + num) % p;
    }
    if(target == 0)
        return 0;
    unordered_map<int, int> pos;
    pos[0] = -1;
    for(int i = 0; i < nums.size(); ++i){
       sum = (sum + nums[i]) % p;
       res = (sum - target + p) % p;
       pos[sum] = i;
       ans = min(ans, pos.find(res) == pos.end() ? INT_MAX : i - pos[res]);
    }
}
#endif //LEETCODE_MINSUBARRAY1590_H
