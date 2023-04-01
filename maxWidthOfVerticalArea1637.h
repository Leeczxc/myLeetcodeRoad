#ifndef LEETCODE_MAXWIDTHOFVERTICALAREA1637_H
#define LEETCODE_MAXWIDTHOFVERTICALAREA1637_H
#include "iostream"
#include "vector"
#include "set"

using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    set<int> width;
    for(auto& c : points){
        width.emplace(c[0]);
    }
    int ans = 0;
    auto ite = width.begin();
    int pre = *ite++;
    while(ite != width.end()){
        ans = max(ans, *ite - pre);
        pre = *ite;
        ite++;
    }
    return ans;
}
#endif //LEETCODE_MAXWIDTHOFVERTICALAREA1637_H
