#ifndef LEETCODE_CHECKPALINDROMEFORMATION1616_H
#define LEETCODE_CHECKPALINDROMEFORMATION1616_H
#include "iostream"
#include "vector"

using namespace std;

bool ifPalindrome(string& s){
    size_t size = s.size() - 1;
    int pos = 0;
    while(pos < size){
        if(s[pos] != s[size])
            return false;
        pos++;
        size--;
    }
    return true;
}

bool checkPalindromeFormation(string a, string b) {
    if(ifPalindrome(a) && ifPalindrome(b))
        return true;
    if(*a.rbegin() == b[0])
        return true;
    if(a[0] == *b.rbegin())
        return true;
    return false;
}
#endif //LEETCODE_CHECKPALINDROMEFORMATION1616_H
