#ifndef LEETCODE_SORTPEOPLE2418_H
#define LEETCODE_SORTPEOPLE2418_H
#include "iostream"
#include "vector"

using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    for(int i = names.size() - 1; i >= 1; --i){
        for(int j = i; j >= 1; --j){
            if(heights[j] < heights[j - 1]){
                swap(names[j], names[j - 1]);
                swap(heights[j], heights[j - 1]);
            }
        }

    }
}
#endif //LEETCODE_SORTPEOPLE2418_H
