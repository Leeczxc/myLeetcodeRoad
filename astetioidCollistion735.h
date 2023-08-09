#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> ast;
    vector<int> ans;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i] > 0)
        {
            ast.push(asteroids[i]);
        }
        else
        {
            if(ast.empty()){
                ans.emplace_back(asteroids[i]);
                continue;
            }
            while (!ast.empty())
            {
                if (ast.top() < -asteroids[i])
                {
                    ast.pop();
                    if(ast.empty()){
                        ans.emplace_back(asteroids[i]);
                        break;
                    }
                }
                else if (ast.top() == -asteroids[i])
                {
                    ast.pop();
                    break;
                }
                else
                {                    ans.emplace_back(asteroids[i]);
                    break;
                }
            }

        }
    }

    if (ast.empty())
    {
        return ans;
    }
    else
    {
        vector<int> temp;
        while (!ast.empty())
        {
            temp.insert(temp.begin(), ast.top());
            ast.pop();
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}