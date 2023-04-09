#ifndef LEETCODE_CHECKDISTANCES2399_H
#define LEETCODE_CHECKDISTANCES2399_H
#include "iostream"
#include "vector"

using namespace std;

bool checkDistances(string s, vector<int>& distance) {
    bool same = true;
    int dis = 0;
    for(int i = 0; i < s.size(); i++){
        dis = distance[s[i] - 'a'];
        if(i - dis - 1 >= 0 && s[i - dis - 1] == s[i]) {
            same = same && (s[i] == s[i - dis - 1]);
        }
        if(dis + 1 + i < s.size() && s[i] == s[i + dis + 1]){
            same = same && (s[i] == s[i + dis + 1]);
        }
        if(!same){
            break;
        }
    }
    return same;
}
#endif //LEETCODE_CHECKDISTANCES2399_H
