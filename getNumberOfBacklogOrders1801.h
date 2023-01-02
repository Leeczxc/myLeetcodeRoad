#ifndef LEETCODE_GETNUMBEROFBACKLOGORDERS1801_H
#define LEETCODE_GETNUMBEROFBACKLOGORDERS1801_H
#include "iostream"
#include "vector"
#include "map"
#include "math.h"

using namespace std;

// 贪心算法？
// 在判断map尾部的时候有点问题
// 后面查阅STL源码看看
int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    size_t size = orders.size();
    if(size == 0)
        return 0;
    map<int, int, less<>> buy;
    map<int, int, greater<>> sell;
    for(auto c : orders){
       if(c[2] == 0){
           // buy
           auto ite = sell.begin();
           while(ite != sell.end() && ite->first <= c[0]){
               if(ite->first <= c[0]){
                   if(ite->second > c[1]){
                       ite->second -= c[1];
                       c[1] = 0;
                       break;
                   }
                   else{
                       auto temp = ite;
                       ite++;
                       c[1] -= temp->second;
                       sell.erase(temp);
                   }
               }else{
                   ite++;
               }
           }
           if(c[1] != 0)
               buy[c[0]] += c[1];
       }else{
           // sell
           auto ite = buy.begin();
           while(ite != buy.end()){
               if(ite->first >= c[0]){
                   if(ite->second > c[1]){
                       ite->second -= c[1];
                       c[1] = 0;
                       break;
                   }else{
                       auto temp = ite;
                       ite = ite++;
                       c[1] -= temp->second;
                       buy.erase(temp);
                   }
               }else{
                   ite++;
               }

           }
           if(c[1] != 0)
               sell[c[0]] += c[1];
       }
    }
    int ans = 0;
    auto ite = sell.begin();
    while(ite != sell.end()){
        ans = fmod(ans + ite++->second, pow(10, 9) + 7);
    }
    ite = buy.begin();
    while(ite != buy.end()){
        ans = fmod(ans + ite++->second, pow(10, 9) + 7);
    }
    return ans;
}
#endif //LEETCODE_GETNUMBEROFBACKLOGORDERS1801_H
