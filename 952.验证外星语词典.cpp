#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

bool isSorted(string str1, string str2, map<char, int>& orders){
    if(str1 == str2)
        return true;
    size_t size1 = str1.size();
    size_t size2 = str2.size();
    size_t size = min(size1, size2);
    for(int i = 0; i < size; i++){
        if(orders[str1[i]] < orders[str2[i]])
           return true;
        else if(orders[str1[i]] > orders[str2[i]])
            return false;
    }
    return size1 < size2;
}

bool isAlienSorted(vector<string>& words, string order) {
    map<char, int> orders;
    for(int i = 0;i < order.size(); i++)
        orders[order[i]] = i;
    for(int i = 0; i < words.size() - 1; i++)
        if(!isSorted(words[i], words[i + 1], orders))
            return false;
    return true;
}

int main(){
   vector<string> words = {"word","world","row"};
   string order = "worldabcefghijkmnpqstuvxyz";
   if(isAlienSorted(words, order))
       cout << "True";
   else
       cout << "False";
}