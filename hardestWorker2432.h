#ifndef LEETCODE_HARDESTWORKER2432_H
#define LEETCODE_HARDESTWORKER2432_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int hardestWorker(int n, vector<vector<int>>& logs) {
    vector<int> times;
    int minWork = logs[0][1];
    int people = logs[0][0];
    int work = minWork;

    for(int i = 1; i < logs.size(); i++){
        work = logs[i][1] - logs[i - 1][1];
        if(work > minWork){
            minWork = work;
            people = logs[i][0];
        }else if(work == minWork){
            people = min(people, logs[i][0]);
        }
    }
    return people;
}
#endif //LEETCODE_HARDESTWORKER2432_H
