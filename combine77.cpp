#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(int n, int k, int startIndex){
    if(path.size() == k){
        result.push_back(path);
        return;
    }
    for(int i = startIndex; i<= n; i++){
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}