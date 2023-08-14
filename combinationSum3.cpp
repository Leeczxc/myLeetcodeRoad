#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtracing(int targetSum, int k, int sum, int startIndex){
    if(sum > targetSum){
        return;
    }
    if(path.size() == k){
        if(sum == targetSum)
            ans.push_back(path);
        return;
    }
    for(int i = startIndex; i <= 9 - (k - path.size() + 1); i++){
        sum += i;
        path.push_back(i);
        backtracing(targetSum, k, sum, i + 1);
        sum -= i;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    backtracing(n, k, 0, 1);
    return ans;
}