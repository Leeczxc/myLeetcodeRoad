//
// Created by Leecz on 2022/4/12.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> numberOfLines(vector<int>& widths, string s) {
    int len = 0;
    int size = 0;
    for(auto c : s){
        if((size += widths[c-'a']) > 100){
            len++;
            size = widths[c - 'a'];
        }
    }
    vector<int> res;
    res.emplace_back(++len);
    res.emplace_back(size);
    return res;
}
int main() {
    vector<int> widths = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                          10, 10};
    string S = "bbbcccdddaaa";
    for (auto c: numberOfLines(widths, S))
        cout << c << endl;
}