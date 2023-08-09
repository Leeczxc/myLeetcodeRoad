#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 这里二分法感觉更好一点
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    map<int, vector<int>> nums;
    for(auto& c : arr){
        nums[abs(c - x)].emplace_back(c);
    }
    auto ite = nums.begin();
    while(ite != nums.end()){
        auto t = ite->second;
        sort(t.begin(), t.end());
        ite++;
    }
    ite = nums.begin();
    vector<int> ans;
    int size = 0;
    while(ans.size() < k){
        if(ite->second.size() + size < k){
            ans.insert(ans.end(), ite->second.begin(), ite->second.end());
            size += ite->second.size();
            ite++;
        }else{
            for(int i = 0; i < k - size; i++){
                ans.emplace_back(ite->second[i]);
            }
            break;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}