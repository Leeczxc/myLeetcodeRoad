#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while(left < right){
        while(left < right && nums[left] % 2 == 0){
            left++;
        }
        while(right > left && nums[right] % 2 == 1){
            right--;
        }
        if(left < right){
            swap(nums[left++], nums[right--]);
        }
    }
    return nums;
}