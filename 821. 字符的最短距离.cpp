#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

int getPos(string s, char c, int pos) {
    int res = 0;
    while(res < s.size()){
        if((pos + res) <= s.size() && s[pos + res] == c)
            return res;
        if((pos - res) >= 0 && s[pos - res] == c)
            return res;
        res++;
    }
    return -1;
}


vector<int> shortestToChar(string s, char c) {
        int size = s.size();
        vector<int> answer(size , 0);
        for(int i = 0; i < size; i++){
            answer[i] = getPos(s, c, i);
        }
        return answer;
}

int main(){
    string s = "loveleetcode";
    char c = 'e';
    for(auto c : shortestToChar(s,c))
        cout << c << " ";
    cout << endl;
    s = "aaab";
    c = 'b';
    for(auto c : shortestToChar(s,c))
        cout << c << " ";
    cout << endl;
    s = "aaba";
    c = 'b';
    for(auto c : shortestToChar(s,c))
        cout << c << " ";
}