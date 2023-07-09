#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() -1;
    vector<int> ans;
    while(left < right){
        if(numbers[left] + numbers[right] < target){
            left++;
        }else if(numbers[left] + numbers[right] > target){
            right--;
        }else{
            ans.emplace_back(left + 1);
            ans.emplace_back(right + 1);
        }
    }
    return ans;
}