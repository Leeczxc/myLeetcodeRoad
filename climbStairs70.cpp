#include <iostream>
#include <vector>

using namespace std;

int getDP(int n){
    vector<int> nums(n + 1, 0);
    nums[0] = 0;
    nums[1] = 1;
    for(int i = 2; i < nums.size(); i++){
        nums[i] = nums[i - 1] + nums[i + 2];
    }
}
int climbStairs(int n)
{
}