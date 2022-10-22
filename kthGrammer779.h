//
// Created by Lee on 2022/10/20.
//

#ifndef LEETCODE_KTHGRAMMER_H
#define LEETCODE_KTHGRAMMER_H
#include "iostream"

using namespace std;

int kthGrammar(int n, int k) {
    if(n == 1)
        return 0;
    if(n == 2){
        if(k == 1)
            return 0;
        return 1;
    }
    //  位置
    int t1 = k % 2;
    int t = 0;
    if(k < 2)
         t  = 1;
    else
         t = k / 2;
    int t2 = kthGrammar(n -1, t);
    if(t2 == 0){
        if(t1 == 0)
            return 1;
        return 0;
    }
    if(t2 == 1){
        if(t1 == 0)
            return 0;
        return 1;
    }
}
#endif //LEETCODE_KTHGRAMMER_H
