#ifndef LEETCODE_ARESENTENCESIMILAR1813_H
#define LEETCODE_ARESENTENCESIMILAR1813_H
#include "iostream"
#include "vector"

using namespace std;

void getString(vector<string>& s, string& str){
    string temp = "";
    for(auto c : str){
        if(c == ' '){
            if(temp != "")
                s.emplace_back(temp);
            temp = "";
            continue;
        }
        temp += c;
    }
    if(temp != "")
        s.emplace_back(temp);
}

bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> s1;
    vector<string> s2;
    getString(s1, sentence1);
    getString(s2, sentence2);
    if(s1.size() == s2.size()){
        for(int i = 0; i< s1.size(); i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }
    if(s1.size() < s2.size())
        swap(s1, s2);
    if(s1[0] != s2[0]){
        for(int i = 0; i < s2.size(); i++){
            if(s1[s1.size() - s2.size() + i] != s2[i])
                return false;
        }
        return true;
    }else{
        int pos = 1;
        while(pos < s2.size() && s1[pos] == s2[pos])
            pos++;
        if(pos == s2.size())
            return true;
        else{
            while(pos < s2.size() && s1[s1.size() - s2.size() + pos] == s2[pos])
                pos++;
        }
        if(pos == s2.size())
            return true;
        return false;
    }
    return false;
}
#endif //LEETCODE_ARESENTENCESIMILAR1813_H
