#include <iostream>
#include <vector>

using namespace std;

int getDP(int n)
{
    vector<int> nums(n + 1, 0);
    nums[1] = 1;
    for (int i = 2; i < nums.size(); i++)
    {
        nums[i] = nums[i - 1]  + nums[i - 2];
    }
    return nums.back();
}

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return getDP(n);
}

int main(){
    cout << fib(4);
}