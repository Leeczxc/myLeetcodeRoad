#ifndef LEETCODE_FINDLONGESTSUBARRAY17_05_H
#define LEETCODE_FINDLONGESTSUBARRAY17_05_H
#include "iostream"
#include "vector"

using namespace std;

// ³¬Ê±
vector<string> findLongestSubarray(vector<string>& array) {
    size_t size = array.size();
    int charNum = 0;
    int intNum = 0;
    vector<pair<int, int>> chNum;
    chNum.emplace_back(0, 0);
    for(int i = 0; i < size; ++i){
        if(isdigit(array[i][0])){
            intNum++;
        }else
            charNum++;
        chNum.emplace_back(charNum, intNum);
    }
    int res = 0;
    int startPos = 0, endPos = 0;
    for(int i = size; i > 0; --i){
        for(int j = i - 1; j >= 0; --j){
            if((chNum[i].first - chNum[j].first) == (chNum[i].second - chNum[j].second)){
                if(res <= (i - j + 1)){
                    res = i - j + 1;
                    startPos = j;
                    endPos = i;
                }
            }
        }
    }
    if(res == 0)
        return vector<string>{};
    auto ite = array.begin();
    return vector<string>(ite + startPos, ite + endPos);
}
#endif //LEETCODE_FINDLONGESTSUBARRAY17_05_H
