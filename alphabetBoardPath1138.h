#ifndef LEETCODE_ALPHABETBOARDPATH1138_H
#define LEETCODE_ALPHABETBOARDPATH1138_H
#include "iostream"
#include "vector"
#include "string"

using namespace std;

// 注意z的位置
//using position = pair<int, int>;
//
//position getPos(char c){
//    int pos = c - 'a';
//    int x = pos / 5;
//    int y = pos % 5;
//    return {x, y};
//}
//
//string alphabetBoardPath(string target) {
//    size_t size = target.size();
//    string ans;
//    target.insert(target.begin(), 'a');
//        for(int i = 1; i <= size; i++){
//        int x = getPos(target[i]).first - getPos(target[i - 1]).first;
//        int y = getPos(target[i]).second - getPos(target[i - 1]).second;
//        if(y > 0){
//            string str2(y, 'R');
//            ans += str2;
//        }else if(y < 0){
//            string str2(abs(y), 'L');
//            ans += str2;
//        }
//        if(x > 0){
//            string str1(x, 'D');
//            ans += str1;
//        }else if(x < 0){
//            string str1(abs(x), 'U');
//            ans += str1;
//        }
//        ans += '!';
//    }
//    return ans;
//}

    string alphabetBoardPath(string target) {
        string ans;
        int x = 0, y = 0;
        for (char c : target) {
            int nx = (c - 'a') / 5, ny = (c - 'a') % 5; // 目标位置
            string v(abs(nx - x), "UD"[nx > x]); // 竖直
            string h(abs(ny - y), "LR"[ny > y]); // 水平
            ans += (c != 'z' ? v + h : h + v) + "!";
            x = nx, y = ny;
        }
        return ans;
    }
    



#endif //LEETCODE_ALPHABETBOARDPATH1138_H
