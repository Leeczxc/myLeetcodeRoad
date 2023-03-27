#ifndef LEETCODE_ANSWERQUERIES2389_H
#define LEETCODE_ANSWERQUERIES2389_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    size_t n = nums.size();
    size_t m = queries.size();
    std::sort(nums.begin(), nums.end());
    std::sort(queries.begin(), queries.end());
    vector<int> ans;
    int startPos = 0;
    int endPos = 0;
    int length = 0;
    int sum = 0;
    int pos = 0;
    while(startPos <= endPos && endPos < n && pos < m){
        sum += nums[endPos];
        if(sum < queries[m]){

        }
    }
}
#endif //LEETCODE_ANSWERQUERIES2389_H
