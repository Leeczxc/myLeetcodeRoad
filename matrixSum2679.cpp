#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int matrixSum(vector<vector<int>>& nums) {
    size_t row = nums.size();
    size_t column = nums[0].size();
    vector<int> selectedNum;
    int res = 0;
    for(int i = 0; i < row; i++){
        std::sort(nums[i].begin(), nums[i].end());
    }
    for(int i = 0; i < column; i++){
        selectedNum.clear();
        for(int j = 0; j < row; j++){
            selectedNum.emplace_back(nums[j][i]);
        }
        std::sort(selectedNum.begin(), selectedNum.end(), [](int& a, int& b){
            return a > b;
        });
        res += selectedNum[0];
    }
    return res;
}