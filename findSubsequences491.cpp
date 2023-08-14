#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int>> ans;

void backtracing(vector<int> &nums, int startIndex, vector<bool> &used)
{
    if (path.size() >= 2)
        ans.emplace_back(path);
    if (startIndex >= nums.size())
        return;
    for (int i = startIndex; i < nums.size(); i++)
    {
        if (i > 0 && (nums[i] == [i - 1]) && (used[i - 1] == false))
            continue;
        if(path.size() > 0 && nums[i] < path[path.size() -1]){
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        backtracing(nums, i + 1, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<bool> used(nums.size(), false);
    backtracing(nums, 0, used);
    return ans;
}

int main()
{
    vector<int> nums{4, 4, 3, 2, 1};
    ans = findSubsequences(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}