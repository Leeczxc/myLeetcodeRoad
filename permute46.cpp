#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtracking(vector<int> &nums, int len, unordered_set<int> &num)
{
    if (path.size() == len)
    {
        ans.emplace_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (num.find(nums[i]) != num.end())
            continue;
        num.emplace(nums[i]);
        path.push_back(nums[i]);
        backtracking(nums, len, num);
        path.pop_back();
        num.erase(nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    unordered_set<int> num;
    backtracking(nums, nums.size(), num);
    return ans;
}

int main()
{
    vector<int> nums{0, 1};
    ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}