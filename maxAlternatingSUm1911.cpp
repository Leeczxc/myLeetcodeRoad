#include <iostream>
#include <vector>

using namespace std;

long long maxAlternatingSum(vector<int> &nums)
{
    long long even = nums[0], odd = 0;
    for(int i = 1; i < nums.size(); i++){
        even = max(even, odd + nums[i]);
        odd = max(odd, even - nums[i]);
    }
    return even;
}