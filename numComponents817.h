//
// Created by Lee on 2022/10/12.
//

#ifndef LEETCODE_NUMCOMPONENTS817_H
#define LEETCODE_NUMCOMPONENTS817_H
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_set"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> numSet;
    for(int num: nums){
        numSet.emplace(num);
    }
    bool inSet = false;
    int res = 0;
    while(head != nullptr){
        if(numSet.count(head->val)){
            if(!inSet){
                inSet = true;
                res++;
            }
        }else{
            inSet = false;
        }
        head = head->next;
    }
    return res;
}
#endif //LEETCODE_NUMCOMPONENTS817_H
