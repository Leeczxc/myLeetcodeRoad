#ifndef LEETCODE_BESTTEAMSCORE1626_H
#define LEETCODE_BESTTEAMSCORE1626_H
#include "iostream"
#include "vector"
#include "set"
#include "map"

using namespace std;

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    size_t size = scores.size();
    map<int, vector<int>> sco;
    for(int i = 0; i < size; i++){
        sco[ages[i]].emplace_back(scores[i]);
    }
    
}
#endif //LEETCODE_BESTTEAMSCORE1626_H
