//
// Created by Lee on 2022/10/30.
//

#ifndef LEETCODE_LETTERCASEPERMUTATION784_H
#define LEETCODE_LETTERCASEPERMUTATION784_H
#include "iostream"
#include "unordered_set"
#include "vector"

using namespace std;

vector<string> letterCasePermutation(string s) {
    //改成全小写就可以了
    BIT
    vector<string> ans;
    vector<vector<string>> dp(s.size() + 1, vector<string>(s.size() + 1, ""));
    dp[0][0] = s;
    ans.emplace_back(s);
    for(int i = 1; i <= s.size(); i++){
        // 初始化
        string temp = s;
        if(!isdigit(s[i -1])){
           if(s[i - 1] >= 'a' && s[i - 1] <= 'z')
               temp[i - 1] -= 32;
           else
               temp[i - 1] += 32;
           dp[i][i] = temp;
           ans.emplace_back(temp);
        }else{
            dp[i][i] = dp[i -1][i - 1];
            continue;

        }
        for(int j = i + 1; j <= s.size(); j++){
            string temp = dp[i][j - 1];
            if(!isdigit(temp[j - 1])){
                if(temp[j - 1] >= 'a' && temp[j - 1] <='z')
                    temp[j - 1] = temp[j - 1] - 32;
                else
                    temp[j - 1] = temp[j - 1] + 32;
                dp[i][j] = temp;
                ans.emplace_back(temp);
            } else
                dp[i][j] = dp[i][j -1];
        }
    }
    return ans;
}
#endif //LEETCODE_LETTERCASEPERMUTATION784_H
