#include <iostream>
#include <vector>
#include <map>

using namespace std;

int unequalTriplets(vector<int>& nums) {
    int ans = 0;
    size_t size = nums.size();
    for(int i = 0; i < size - 2; i++){
        for(int j = i + 1; j < size - 1; j++)
            for(int k = j + 1; k < size; k++){
                if(nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k])
                    ans++;
            }
    }
    return ans;
}