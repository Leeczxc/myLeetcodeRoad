#ifndef LEETCODE_MINIMUMRECOLORS2379_H
#define LEETCODE_MINIMUMRECOLORS2379_H
#include "iostream"
#include "vector"

using namespace std;

int minimumRecolors(string blocks, int k) {
     size_t size = blocks.size();
     if(size < k)
         return 0;
     int ans = k;
     int blackNum = 0;
     for(int i = 0; i < k; i++){
         if(blocks[i] == 'B')
             blackNum++;
     }
     ans = min(ans, k - blackNum);
     for(int i = k; i < size; i++){
         if(blocks[i - k] == 'B')
             blackNum--;
         if(blocks[i] == 'B'){
             blackNum++;
         }
         ans = min(k - blackNum, ans);
     }
     return ans;
}
#endif //LEETCODE_MINIMUMRECOLORS2379_H
