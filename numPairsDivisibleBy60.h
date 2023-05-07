#ifndef LEETCODE_NUMPAIRSDIVISIBLEBY60_H
#define LEETCODE_NUMPAIRSDIVISIBLEBY60_H
#include "iostream"
#include "vector"
#include "map"
#include "unordered_set"

using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    map<int, int> times;
    for(auto& c : time){
        if(c >= 60)
            c = c % 60;
        times[c]++;
    }
    unordered_set<int> sets;
    long long result = 0;
    auto ite = times.find(0);
    if(ite != times.end()){
        result += (long long)ite->second * (ite->second - 1) / 2;
    }
    ite = times.begin();

    while(ite != times.end()){
        if(ite->first == 30){
            result += (long long )ite->second * (ite->second- 1) / 2;
            sets.emplace(30);
        }else{
            if(sets.find(ite->first) == sets.end()){
                result += ite->second * (times.find(60 - ite->first)->second);
                sets.emplace(ite->first);
                sets.emplace(60 - ite->first);
            }
        }
        ite++;
    }
    return (int)result;
}
#endif //LEETCODE_NUMPAIRSDIVISIBLEBY60_H
