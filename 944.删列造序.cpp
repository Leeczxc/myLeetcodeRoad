#include "iostream"
#include "vector"

using namespace std;

int minDeletionSize(vector<string>& strs) {
    int ans = 0;
    int size = strs[0].size();
    for(int i = 0;i < size; i++){
        for(int j = 0; j < strs.size() -1;j++){
            if(strs[i][j] < strs[i][j+1]){
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<string> strs = {"cba","daf","ghi"};
    vector<string> strs1 = {"zyx","wvu","tsr"};
    cout << minDeletionSize(strs1);
//    cout << minDeletionSize(strs);
}