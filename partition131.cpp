#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> ans;
vector<string> path;
int length = 0;

bool isTrue(string& s){
    int start = 0;
    int end = s.size() - 1;
    while(start <= end){
        if(s[start] != s[end]){
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

void backtracing(vector<string> path, string& s,int startIndex){
    if(length == s.size()){
        ans.push_back(path);
    }
    string str = "";
    for(int i = startIndex; i < s.size() ; i++){
        str += s[i];
        length++;
        if(isTrue(str)){
            path.push_back(str);
            backtracing(path, s, i + 1);
            path.pop_back();
        }
        length = i + 1;
    }
    if(length == s.size() && !isTrue(str)){
        return;
    }
}

vector<vector<string>> partition(string s)
{
    backtracing(path, s, 0);
    return ans;
}


int main(){
    string s = "aab";
    auto ans = partition(s);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}