#ifndef LEETCODE_CHECKARITHMETICSUBARRAYS1630_H
#define LEETCODE_CHECKARITHMETICSUBARRAYS1630_H
#include "iostream"
#include "vector"

using namespace std;

// 没注意这里是要做重新排列的
bool allSame(vector<int>& sub, int pos_start, int pos_end){
    if(pos_start == pos_end)
        return true;
    int same = sub[pos_start];
    for(int i = pos_start + 1; i < pos_end; i++){
        if(sub[i] != same)
            return false;
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    size_t size = nums.size();
    vector<int> sub;
    vector<bool> ans;
    for(int i = 1; i < size; i++){
        sub.emplace_back(nums[i] - nums[i - 1]);
    }
    size = l.size();
    for(int i = 0; i < size; i++){
        if(allSame(sub, l[i], r[i] - 1))
            ans.emplace_back(true);
        else
            ans.emplace_back(false);
    }
    return ans;
}
#endif //LEETCODE_CHECKARITHMETICSUBARRAYS1630_H
