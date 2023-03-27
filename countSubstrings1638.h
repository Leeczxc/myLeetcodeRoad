#ifndef LEETCODE_COUNTSUBSTRINGS1638_H
#define LEETCODE_COUNTSUBSTRINGS1638_H
#include "iostream"
#include "vector"

using namespace std;

bool  sameStr(string& s1, string& s2, int s_start, int t_start, int length){
    int diff = 0;
    for(int i = 0; i <= length; i++){
        if(s1[i + s_start] != s2[i + t_start]){
            diff++;
            if(diff > 1)
                return false;
        }
    }
    if(diff == 1)
        return true;
    return false;
}

int countSubstrings(string s, string t) {
    int ans = 0;
    int length = 0;
    int s_left = 0, s_right = s.size();
    while(s_left + length < s_right){
        for(int i = s_left; i + length < s_right; i++){
            for(int j = 0; j + length < t.size(); j++){
                if(sameStr(s, t, i, j, length))
                    ans++;
            }
        }
        length++;
    }
    return ans;
}
#endif //LEETCODE_COUNTSUBSTRINGS1638_H
