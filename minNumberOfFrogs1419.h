#ifndef LEETCODE_MINNUMBEROFFROGS1419_H
#define LEETCODE_MINNUMBEROFFROGS1419_H
#include "iostream"
#include "vector"
#include "map"
using namespace std;

int minNumberOfFrogs(string croakOfFrogs) {
    size_t size = croakOfFrogs.size();
    if(size % 5 != 0)
        return -1;
    int start = 0;
    int end = croakOfFrogs.size();
    for(int i = 0; i < croakOfFrogs.size() - 5; i+=5){
        string sub = croakOfFrogs.substr(i,5);
        if(sub == "croak")
            start += 5;
        else
            break;
    }
    // 没有判断序列
    for(int i = croakOfFrogs.size() - 5; i >= start; i -=5){
        string sub = croakOfFrogs.substr(i, 5);
        if(sub == "croak")
            end -= 5;
        else
            break;
    }
    if(start == end)
        return 1;
    vector<int> times(26, 0);
    for(int i = start; i < end; i++){
        times[croakOfFrogs[i] - 'a']++;
    }
    int t = times[0];
    for(int i = 1; i < 26; i++){
        if(times[i] != 0)
            if(times[i] != t)
                return -1;
    }
    return t;
}
/*
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0) {
            return -1;
        }
        int res = 0, frogNum = 0;
        vector<int> cnt(4);
        unordered_map<char, int> mp = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        for (char c : croakOfFrogs) {
            int t = mp[c];
            if (t == 0) {
                cnt[t]++;
                frogNum++;
                if (frogNum > res) {
                    res = frogNum;
                }
            } else {
                if (cnt[t - 1] == 0) {
                    return -1;
                }
                cnt[t - 1]--;
                if (t == 4) {
                    frogNum--;
                } else {
                    cnt[t]++;
                }
            }
        }
        if (frogNum > 0) {
            return -1;
        }
        return res;
    }
};


作者：LeetCode-Solution
链接：https://leetcode.cn/problems/minimum-number-of-frogs-croaking/solution/shu-qing-wa-by-leetcode-solution-o532/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
#endif //LEETCODE_MINNUMBEROFFROGS1419_H
