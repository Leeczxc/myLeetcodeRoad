#ifndef LEETCODE_BESTHAND_H
#define LEETCODE_BESTHAND_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

string bestHand(vector<int>& ranks, vector<char>& suits) {
    string ans = "";
    bool same = true;
    for(int i = 0; i < 4; i++){
        if(suits[i] != suits[i + 1]){
            same = false;
            break;
        }
    }
    if(same)
        return "Flush";
    map<int, int> times;
    for(int i = 0; i <= 5; i++){
        times[ranks[i]]++;
    }
    bool hasThree = false;
    bool hasTwo = false;
    auto ite = times.begin();
    while(ite != times.end()){
        if(ite->second >= 2){
            hasTwo = true;
            if(ite->second >= 3){
                hasThree = true;
                break;
            }
        }
        ite++;
    }
    if(hasThree)
        ans = "Three of a Kind";
    else if(hasTwo)
        ans = "Pair";
    else
        ans = "High Card";
    return ans;
}
#endif //LEETCODE_BESTHAND_H
