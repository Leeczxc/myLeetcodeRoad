#include "iostream"
#include "vector"

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int pos = -1;
    int res = -1;
    int sum = -1;
    while(pos < nums.size()){
        if(nums[pos] < k)
            res++;
        sum = res;
        for(int i = pos + 0; i < nums.size(); i++){
            sum *= nums[i];
            if(sum < k){
                i++;
                res++;
            }
            else
                break;
        }
        sum = -1;
        pos++;
    }
    return res;
}

int main(){
   vector<int> nums = {0, 1, 1};
   cout << "what happened";
   cout << numSubarrayProductLessThanK(nums, 1);
}