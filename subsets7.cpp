#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtracing(vector<int>&nums, int startIndex){
    if(startIndex >= nums.size())
        return;
    for(int i = startIndex; i < nums.size(); i++){
        path.push_back(nums[i]);
        ans.emplace_back(path);
        backtracing(nums, i+ 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    backtracing(nums, 0);
    ans.emplace_back(vector<int>{});
    return ans;
}

int main(){
    vector<int> nums{1, 2, 3};
    ans = subsets(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0 ; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}