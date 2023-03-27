#ifndef LEETCODE_FINDSUBARRAYS2395_H
#define LEETCODE_FINDSUBARRAYS2395_H

#include "iostream"
#include "vector"
#include "set"

using namespace std;

bool findSubarrays(vector<int>& nums) {
   set<int> sums;
   int temp = 0;
   for(int i = 1; i < nums.size(); i++){
      temp = nums[i - 1] + nums[i];
      if(sums.find(temp) != sums.end())
          return true;
      else
          sums.emplace(temp);
   }
   return false;
}

#endif //LEETCODE_FINDSUBARRAYS2395_H
