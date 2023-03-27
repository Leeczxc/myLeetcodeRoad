#ifndef LEETCODE_MINIMUMDELETIONS_H
#define LEETCODE_MINIMUMDELETIONS_H
#include "iostream"

using namespace std;


// 考虑最大长度
int minimumDeletions(string s ){
   int a = 0, b = 0, n = s.size();
   for(auto&& x : s){
       if (x == 'a')
           a += 1;
       else
           b = max(a, b) + 1;
   }
}


// 考虑删除a的数量
//int minimumDeletions(string s) {
//    int bCnt = 0, ans = 0;
//    for(auto && x : s){
//        if(x == 'a')
//            ans = min(ans + 1, bCnt);
//        else
//            ++bCnt;
//    }
//    return ans;
//}
#endif //LEETCODE_MINIMUMDELETIONS_H
