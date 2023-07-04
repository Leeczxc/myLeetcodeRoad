#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    size_t size = reward1.size();
    int sum = 0;
    for(auto c : reward2){
        sum += c;
    }
    priority_queue<int, vector<int>, less<int>> diff;
    for(int i = 0; i < size; i++){
        diff.emplace(reward1[i] - reward2[i]);
    };
    while(k > 0){
        sum += diff.top();
        diff.pop();
        k--;
    }
    return sum;
}