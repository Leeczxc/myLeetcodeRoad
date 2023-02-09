#ifndef LEETCODE_COUNTNICEPAIRS1814_H
#define LEETCODE_COUNTNICEPAIRS1814_H
#include "iostream"
#include "vector"
#include "queue"
#include "math.h"
#include "ctime"

using namespace std;
// 最后处理超时
// 选用哈希表就好了
vector<int> rev(vector<int>& nums){
    size_t size = nums.size();
    vector<int> ans;
    queue<int> st;
    for(int i = 0; i < size; i++){
        int t = nums[i];
        while(t){
            st.push(t % 10);
            t = t / 10;
        }
        int x = 0;
        while(!st.empty()){
            int p = st.front();
            x = x * 10 + p;
            st.pop();
        }
        ans.emplace_back(x);
    }
    return ans;
}

int countNicePairs(vector<int>& nums) {
    vector<int> revs = rev(nums);
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            if((nums[i] + revs[j])== (revs[i] + nums[j]))
                ans++;
        }
    }
    return ans % (int)(pow(10, 9) + 7);
}
#endif //LEETCODE_COUNTNICEPAIRS1814_H
