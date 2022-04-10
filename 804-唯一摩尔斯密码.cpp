#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> str = {".-","-...","-.-.","-..",".","..-.","--.",
                      "....","..",".---","-.-",".-..","--","-.",
                      "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};


int uniqueMorseRepresentations(vector<string>& words) {
    map<string,int> translate;
    for(auto c : words){
        string s = "";
        for(auto a : c){
            s += str[a - 'a'];
        }
        if(translate.find(s) == translate.end())
            translate[s];
    }
    return static_cast<int>(translate.size());
}
int main() {
    vector<string> words = {"a"};
    cout << uniqueMorseRepresentations(words);
    return 0;
}
