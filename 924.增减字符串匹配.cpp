#include "iostream"
#include "vector"

using namespace std;
//模拟
vector<int> diStringMatch(string s) {
   vector<int> ans;
   int min = 0;
   int max = s.size();
   for(auto c : s){
       if(c == 'D')
           ans.emplace_back(max--);
       else
           ans.emplace_back(min++);
   }
   ans.emplace_back(max);
   return ans;
};

int main(){
    for(auto c : diStringMatch("IDID")){
        cout << c << " ";
    }
};