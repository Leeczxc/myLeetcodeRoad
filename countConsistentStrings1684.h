//
// Created by Lee on 2022/11/8.
//

#ifndef LEETCODE_COUNTCONSISTENTSTRINGS1684_H
#define LEETCODE_COUNTCONSISTENTSTRINGS1684_H
#include "iostream"
#include "vector"
#include "map"

using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
      map<char, int> str;
      for(auto c : allowed){
          if(str.find(c) == str.end()){
              str[c]++;
          }
      }
      int ans = 0;
      for(string s : words){
          bool ok = false;
          for(auto c : s){
              if(str.find(c) == str.end()){
                  ok = true;
                  break;
              }
          }
          if(!ok)
              ans++;
      }
      return ans;
}
#endif //LEETCODE_COUNTCONSISTENTSTRINGS1684_H
