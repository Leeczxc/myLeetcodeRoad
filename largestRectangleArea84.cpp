#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    vector<int> nums(heights.size(), 0);
    int h_min = __INT_MAX__;
    int h = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        h_min = min(h_min, heights[i]);
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            nums[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {

            h = max(h, heights[i] * nums[i]);
        }
        else
        {
            h = max(h, static_cast<int>(heights[i] * (heights.size() - i)));
        }
    }
    h = max(static_cast<int>(h_min * heights.size()), h);
    return h;
}

int main(){
    vector<int> nums{5, 4, 1, 2};
    cout << largestRectangleArea(nums);
}