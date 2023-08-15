#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// 思路是正确的自己写乱了  后面改改下面两个循环 就是写的不如随想录好看
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    vector<int> nums(nums2.size(), -1);
    vector<int> ans(nums1.size(), -1);
    unordered_map<int, int> m;
    for(int i = 0; i < nums2.size(); i++){
        while(!st.empty() && nums2[i] > nums2[st.top()]){
            nums[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i < nums2.size(); i++){
        m[nums2[i]] =  nums[i];
    }
    for(int i = 0; i < nums1.size(); i++){
        if(m[nums[i]] != -1){
            ans[i] = nums2[m[nums[i]]];
        }
    }
    return ans;
}

int main(){
    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};
    auto ans = nextGreaterElement(nums1, nums2);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}