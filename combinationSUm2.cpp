#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ans;
vector<int> path;
void backtracing(vector<int> &candidates, int startIndex, vector<bool>& used, int &target, int sum)
{
    if (sum > target)
        return;
    if (sum == target)
        ans.emplace_back(path);
    for (int i = startIndex; i < candidates.size(); i++)
    {
        if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            continue;
        used[i] = true;
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracing(candidates, i + 1, used, target, sum);
        used[i] = false;
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    int sum = 0;
    vector<bool> used(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    backtracing(candidates, 0, used, target, sum);
    return ans;
}

int main()
{
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    auto ans = combinationSum2(candidates, 8);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}