#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> nums(m, vector<int>(n, 1));
    bool haveOne = false;
    for (int i = 0; i < n; i++)
    {
        if (obstacleGrid[0][i] == 1)
        {
            haveOne = true;
        }
        if (haveOne)
        {
            nums[0][i] = 0;
        }
    }
    haveOne = false;
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            haveOne = true;
        }
        if (haveOne)
        {
            nums[i][0] = 0;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                nums[i][j] = 0;
            else
                nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
        }
    }
    return nums[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> obstacleGrid{{0,0, 0}, {0,1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid);
}