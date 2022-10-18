//
// Created by Lee on 2022/10/18.
//

#ifndef LEETCODE_COMBINATION39_H
#define LEETCODE_COMBINATION39_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> combination(vector<int>& candidates, int pos,int target){
    if(candidates[0] > target)
        return vector<vector<int>>();
    vector<vector<int>> ans;
    for(int i = pos; i >=0 ;i--){
        if(candidates[i] == target) {
            vector<int> temp;
            temp.emplace_back(candidates[i]);
            ans.emplace_back(temp);
        }else{
            auto c = combination(candidates, i, target - candidates[i]);
            for(int j = 0; j < c.size(); j++){
                vector<int> temp;
                temp.emplace_back(candidates[i]);
                for (int k = 0; k < c[j].size(); ++k) {
                    temp.emplace_back(c[j][k]);
                }
                ans.emplace_back(temp);
            }
        }
    }
    return ans;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    // 判断最小值和target
    if(candidates[0] > target)
        return vector<vector<int>>();
    vector<vector<int>> ans;

    size_t size = candidates.size();
//    for(int i = size - 1; i >= 0; i--){
//        vector<vector<int>> can;
//        if(candidates[i] == target){
//            vector<int> temp;
//            temp.emplace_back(candidates[i]);
//            ans.emplace_back(temp);
//        }
//        if(candidates[i] < target)
//            can = combination(candidates, i, target - candidates[i]);
//        if(can.size() !=0){
//            for(int j = 0; j < can.size(); j++){
//                vector<int> temp;
//                temp.emplace_back(candidates[i]);
//                for(int z = 0; z < can[j].size(); z++){
//                    temp.emplace_back(can[j][z]);
//                }
//                ans.emplace_back(temp);
//            }
//        }
//    }
    ans = combination(candidates,size - 1, target);
    return ans;
}
#endif //LEETCODE_COMBINATION39_H
