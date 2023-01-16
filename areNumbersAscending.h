#ifndef LEETCODE_ARENUMBERSASCENDING_H
#define LEETCODE_ARENUMBERSASCENDING_H
#include "iostream"
#include "vector"
#include "sstream"

using namespace std;

bool isNum(string str){
    stringstream sin(str);
    int d;
    char c;
    if(!(sin >> d))
        return false;
    if(sin >> c)
        return false;
    return true;
}
bool areNumbersAscending(string s) {
   vector<string> str;
   string temp;
   auto ite = s.begin();
   while(ite != s.end()){
       if(*ite != ' '){
           temp += *ite;
       }else{
           str.emplace_back(temp);
           temp.clear();
       }
       ite++;
   }
   if(temp != "")
      str.emplace_back(temp);
   vector<int> num;
   for(auto c: str){
       if(isNum(c)){
           num.emplace_back(stoi(c));
       }
   }
   if(num.size() == 1)
       return true;
   for(int i = 0; i< num.size() - 1; i++){
       if(num[i] >= num[i + 1])
           return false;
   }
   return true;
}
#endif //LEETCODE_ARENUMBERSASCENDING_H
