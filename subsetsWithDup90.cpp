#include <iostream>
#include <vector>

using namespace std;

// error 看原答案理解一下
vector<vector<int>> ans;
vector<int> path;

void backtracing(vector<int>& nums, int startIndex){
    if(startIndex >= nums.size())
        return;
    for(int i = startIndex; i < nums.size(); i++){
        path.push_back(nums[i]);
        ans.emplace_back(path);
        int num = nums[i];
        while(nums[i + 1] == num && i + 1 < nums.size()){
            backtracing(nums, i + 1);
            i++;
        }
        if(i < nums.size())
            backtracing(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    ans.emplace_back(vector<int>{});
    backtracing(nums, 0);
    return ans;
}

int main(){
    vector<int> nums{1, 2, 2};
    ans = subsetsWithDup(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0 ; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}