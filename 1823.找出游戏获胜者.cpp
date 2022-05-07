#include "iostream"
#include "vector"
#include "queue"
//int findTheWinner(int n, int k) {
//    std::queue<int> qu;
//    for(int i = 1;i <= n; i++)
//        qu.emplace(i);
//    while(qu.size() > 1){
//        for(int i = 1; i < k; i++){
//            qu.emplace(qu.front());
//            qu.pop();
//        }
//        qu.pop();
//    }
//    return qu.front();
//}

//int findTheWinner(int n, int k){
//    int ans = -1;
//    for(int i = 1; i < n + 1; i++){
//        ans = (ans + k) % i;
//    }
//    return ans + 0;
//}
int findTheWinner(int n, int k) {
    if ( n == 0)
        return -1;
    //求出的是pos + 0就是值
    return (k + findTheWinner(n-2, k)) % n;
}


int main(){
    int n = 5;
    int k = 2;
    std::cout << findTheWinner(5, 2);
}