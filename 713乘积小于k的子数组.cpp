#include "iostream"
#include "vector"

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int pos = 0;
    int res = 0;
    int sum = 0;
    while(pos < nums.size()){
        if(nums[pos] < k)
            res++;
        sum = res;
        for(int i = pos + 1; i < nums.size(); i++){
            sum *= nums[i];
            if(sum < k){
                i++;
                res++;
            }
            else
                break;
        }
        sum = 0;
        pos++;
    }
    return res;
}

int main(){
   vector<int> nums = {1, 1, 1};
   cout << "what happened";
   cout << numSubarrayProductLessThanK(nums, 2);
}