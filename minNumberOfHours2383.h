#ifndef LEETCODE_MINNUMBEROFHOURS2383_H
#define LEETCODE_MINNUMBEROFHOURS2383_H
#include "iostream"
#include "vector"

using namespace std;

int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
    int sumEnergy = 0;
    for(auto& c : energy)
        sumEnergy += c;
    int ans = 0;
    if(sumEnergy >= initialEnergy)
        ans = sumEnergy - initialEnergy + 1;
    for(auto& c : experience){
        if(initialExperience <= c){
            ans += c - initialExperience + 1;
            initialExperience = 2 * c + 1;
        }else
            initialExperience += c;
    }
    return ans;
}
#endif //LEETCODE_MINNUMBEROFHOURS2383_H
