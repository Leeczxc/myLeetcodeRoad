#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    size_t n = cost.size();
    vector<int> value(n + 1, 0);
    value[0] = 0;
    value[1] = 0;
    for(int i = 2; i <= n; i++){
        value[i] = min(value[i - 2] + cost[i - 2], value[i - 1] + cost[i -1]);
    }
    return value.back();
}

int main(){
    vector<int> cost{1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(cost);
}