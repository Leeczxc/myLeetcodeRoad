#include "iostream"
#include "vector"
#include "map"

using namespace std;
//似乎空间上对不上
vector<int> findDuplicates(vector<int>& nums) {
   map<int,int> array;
   vector<int> ans;
   for(auto c :nums){
       array[c]++;
       if(array[c] == 2)
           ans.emplace_back(c);
   }
   return ans;
}

int main(){
    vector<int> nums = {4, 3, 2, 7, 8 ,2, 3, 1};
    for(auto c : findDuplicates(nums)){
        cout << c << ' ';
    }
}