#ifndef LEETCODE_REARRANGECHARACTERS2287_H
#define LEETCODE_REARRANGECHARACTERS2287_H
#include "iostream"
#include "vector"
#include "map"
using namespace std;

int rearrangeCharacters(string s, string target) {
    int first[26];
    int second[26];
    for(int i = 0; i < 26; i++){
        first[i] = 0;
        second[i] = 0;
    }
    for(auto c : s){
        first[c - 'a']++;
    }
    for(auto c : target)
        second[c - 'a']++;
    int ans = INT_MAX;
    for(int i = 0; i < 26; i++){
        if(second[i] != 0){
            ans = min(ans, first[i] / second[i]);
        }
    }
    return ans;
}
#endif //LEETCODE_REARRANGECHARACTERS2287_H
