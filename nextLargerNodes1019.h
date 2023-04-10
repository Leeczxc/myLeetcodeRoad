#ifndef LEETCODE_NEXTLARGERNODES1019_H
#define LEETCODE_NEXTLARGERNODES1019_H
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

// 超时 应该选择单调栈

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    stack<pair<int, int>> s;

    ListNode* cur = head;
    int idx = -1;
    while(cur){
        ++idx;
        ans.push_back(0);
        while(!s.empty() && s.top().first < cur->val){
            ans[s.top().second] =cur->val;
            s.pop();
        }
        s.emplace(cur->val, idx);
        cur = cur->next;
    }
    return ans;
//    vector<int> nums;
//    while(head != nullptr){
//        nums.emplace_back(head->val);
//        head = head->next;
//    }
//    vector<int> ans(nums.size(), 0);
//    for(int i = 0; i < nums.size(); i++){
//        for(int j = i + 1; j < nums.size(); j++){
//            if(nums[j] > nums[i]){
//                ans[i] = nums[j];
//                break;
//            }
//        }
//    }
//    return ans;
}
#endif //LEETCODE_NEXTLARGERNODES1019_H
