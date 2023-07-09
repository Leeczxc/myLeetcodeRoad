#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> num;
    for(int i = 0; i < nums.size(); i++){
        num[nums[i]] = i;
    }
    vector<int> res;
    auto ite = num.begin();
    while(ite != num.end()){
        auto it = num.find(ite->second);
        if(it != num.end()){
            res.emplace_back(it->first);
            res.emplace_back(it->second);
        }
        ite++;
    }
    return res;
}