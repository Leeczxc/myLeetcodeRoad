#include <iostream>
#include <vector>

using namespace std;

int searchNum(vector<int>& nums, int left, int right, int target){
    if(left > right){
        return -1;
    }
    int mid = (left + right) / 2;
    if(nums[mid] == target){
        return mid;
    }
    if(nums[mid] < target){
        return searchNum(nums, mid + 1, right, target);
    }
    return searchNum(nums, left, mid - 1, target);
}

int search(vector<int> &nums, int target)
{

    if(nums.size() == 1){
        if(nums[0] == target)
            return 0;
        return -1;
    }
    int pos = nums.size() / 2;
    int ans = pos;
    if(nums[pos] < target){
        ans = searchNum(nums, pos + 1, nums.size() -1, target);
    }else if(nums[pos] > target){
        ans = searchNum(nums, 0, pos - 1, target);
    }
    return ans;
}

int main(){
    vector<int> nums{2, 5};
    cout << search(nums, 5);
}