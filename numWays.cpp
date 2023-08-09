#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n)
{

    int MOD = 1000000007;

    int f1 = 0, f2 = 0, f3 = 1;

    for (int i = 1; i <= n; ++i)
    {

        f1 = f2;

        f2 = f3;

        f3 = (f1 + f2) % MOD;
    }

    return f3;
}
