#include <iostream>
#include <vector>
#include <map>

using namespace std;

int getSmallTime(string& str){
    map<char, int> times;
    for(auto &c : str){
        times[c]++;
    }
    return times.begin()->second;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> queries_times;
    map<int, int> words_times;
    for(auto &c : queries){
        queries_times.emplace_back(getSmallTime(c));
    }

    for(auto &c : words){
        words_times[getSmallTime(c)]++;
    }
    int sum = 0;
    auto ite = words_times.begin();
    while(ite != words_times.end()){
        sum += ite->second;
        ite++;
    }
    vector<int> times{0};
    for(int i = 1; i <= words_times.rbegin()->first; i++){
        if(words_times.find(i) != words_times.end())
            sum -= words_times.find(i)->second;
        times.emplace_back(sum);
    }
    vector<int> ans;
    for(auto &c : queries_times){
        if(c <= times.size() - 1)
            ans.emplace_back(times[c]);
        else
            ans.emplace_back(0);
    }
    return ans;
}