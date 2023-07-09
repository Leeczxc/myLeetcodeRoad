#include <iostream>
#include <vector>
#include <array>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.size() == 1)
        return 1;
    array<char, 26> chars;
    for(int i = 0; i < 26; i++){
        chars[i] = '0';
    }
    int start = 0, end = 0;
    int res = 1;
    int length = end - start + 1;
    chars[s[end] - 'a'] = '1';
    end++;
    while(end < s.size()){
        if((chars[s[end] - 'a']) == '1'){
            chars[s[start] - 'a'] = '0';
            start++;
            length--;
        }else{
            chars[s[end] - 'a'] = '1';
            length++;
            res = max(length, res);
            end++;
        }
    }
    return res;
}