#ifndef LEETCODE_DECRYPT1652_H
#define LEETCODE_DECRYPT1652_H
#include "iostream"
#include "vector"

using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    vector<int> ans;
    size_t size = code.size();
    if(k == 0){
        for(int i = 0; i< size; i++){
            ans.emplace_back(0);
        }
        return ans;
    }
    if(k > 0){
       for(int i = 0; i < size; i++){
           int sum = 0;
           for(int j = 0; j < k; j++){
               sum += code[(j + i + 1) % size];
           }
           ans.emplace_back(sum);
       }
       return ans;
    }
    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = 0; j > k; j--){
            sum += code[(i + j - 1 + size) % size];
        }
        ans.emplace_back(sum);
    }
    return ans;
}

#endif //LEETCODE_DECRYPT1652_H
