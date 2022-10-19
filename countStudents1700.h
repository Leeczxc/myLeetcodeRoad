//
// Created by Lee on 2022/10/19.
//

#ifndef LEETCODE_COUNTSTUDENTS1700_H
#define LEETCODE_COUNTSTUDENTS1700_H
#include "iostream"
#include "vector"

using namespace std;

int countstudents(vector<int>& students, vector<int>& sandwiches) {
    int sumone = 0, sumzero = 0;
    int ans = 0;
    for(auto num : students){
        if(num == 0)
            sumzero++;
        else
            sumone++;
    }
    while(students.size() != 0){
        if(students[0] == sandwiches[0]){
            if(students[0] == 0)
                sumzero--;
            else
                sumone--;
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
        }
        else{
            if(sumone * sumzero == 0){
                ans = max(sumone, sumzero);
                break;
            }else{
                int t = students[0];
                students.erase(students.begin());
                students.insert(students.end(), t);
            }
        }
    }
    return ans;
}
#endif //LEETCODE_COUNTSTUDENTS1700_H
