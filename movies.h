//
// Created by Lee on 2022/11/19.
//

#ifndef LEETCODE_MOVIES_H
#define LEETCODE_MOVIES_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int seenMovies(vector<int> movies, vector<int> days){
    int ans = 0;
    size_t size = movies.size();
    vector<pair<int, int>> lastDays;
    for(int i = 0; i < size; i++){
        if(lastDays.size() != 0){
            auto ite = lastDays.begin();
            while(ite != lastDays.end()){
                ite->first--;
                if(ite->first < 0 || ite->second == 0){
                    ite = lastDays.erase(ite);
                }else
                    ite++;
            }
        }
        auto c = pair<int, int>(days[i], movies[i]);
        lastDays.emplace_back(c);
        ans++;
        lastDays.begin()->second--;
   }
    while(!lastDays.empty()){
        auto ite = lastDays.begin();
        while(ite != lastDays.end()) {
            if(ite->first < 0 || ite->second == 0)
                ite = lastDays.erase(ite);
            else{
                ite->first--;
                ite->second--;
                ans++;
            }
        }
    }
   return ans;
}
#endif //LEETCODE_MOVIES_H
