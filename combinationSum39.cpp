#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int>> ans;

void backtracing(vector<int>& candidates, int sum, int target, int startIndex){
    if(sum > target)
        return;
    if(sum == target){
        ans.push_back(path)};
        return;
    }
    for(int i = startIndex; i < size; i++){
        path.push_back(candidates[i]);
        sum += candidates[i];
        backtracing(candidates, size, sum, target);
        sum -= candidates[i];
        path.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

}