#include<iostream>
#include <vector>

using namespace std;

/*
 * 如果开始或者结束的时候，数对的两个数是相同的，要么是没有经过转发，要么是有0，但不可能有0的
 * 如果一个数字是(a,b)，那么前面的数字必然是(a-b,b)或者(a,b-a)，因为整个过程不可能有负数，所以必然是（a，b）里面最大者减去较小者，这表明之前两种情况只有一种是正确的
 * 然后按照同样的逻辑继续判断
 * 注意得到余数那里，用得挺好的
 * */
bool reachingPoints(int sx, int sy, int tx, int ty) {
    if(tx < sx || ty < sy)
        return false;
    if(tx > ty) {
        if (sy == ty)
            return sx >= (tx % ty) && (tx - sx) % sy == 0;
        return reachingPoints(sx, sy, tx % ty, ty);
    }
    else if(tx < ty) {
        if (sx == tx)
            return sy >= (ty % tx) && (ty - sy) % sx == 0;
        return reachingPoints(sx, sy, tx, ty % tx);
    }else return tx == sx && ty == sy;
}

int main(){

}
