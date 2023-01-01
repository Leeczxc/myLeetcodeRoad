#ifndef LEETCODE_REPEATEDCHARACTER_H
#define LEETCODE_REPEATEDCHARACTER_H
#include "iostream"
#include "vector"

using namespace std;

char repeatedCharacter(string s) {
    int times[26] = {0};
    for(auto c : s){
        if(times[c - 'a'] == 1)
            return c;
        times[c-'a']++;
    }
    return '0';
}

#endif //LEETCODE_REPEATEDCHARACTER_H
