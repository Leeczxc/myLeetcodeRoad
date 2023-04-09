#ifndef LEETCODE_NUMMOVESTONESII1040_H
#define LEETCODE_NUMMOVESTONESII1040_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 最多的部分没问题
// 最小的部分分析有问题
int getSpace(vector<int>& stones, int start, int end){
    int ans = stones[end] - stones[start] - stones.size() + 2;
    return ans;
}

vector<int> numMovesStonesII(vector<int>& stones) {
    std::sort(stones.begin(), stones.end());

    int min_1 = getSpace(stones, 1, stones.size() - 1),min_2 = getSpace(stones, 0, stones.size() - 2);
    int max_1 = getSpace(stones, 1, stones.size() - 1), max_2 = getSpace(stones, 0, stones.size() - 2);
    int m_min = (min_1 + min_2) != 0  ? 0 : max(min_1, min_2);
    int m_max = max(max_1, max_2);
    return vector<int>{m_min, m_max};
}
#endif //LEETCODE_NUMMOVESTONESII1040_H
