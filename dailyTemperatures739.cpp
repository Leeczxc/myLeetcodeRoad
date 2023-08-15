#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    vector<int> ans(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> t { 73,74,75,71,69,72,76,73};
    auto ans = dailyTemperatures(t);
    for(int i = 0; i < t.size(); i++){
        cout << ans[i] << " ";
    }
}