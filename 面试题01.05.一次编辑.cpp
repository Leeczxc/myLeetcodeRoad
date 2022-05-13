#include "iostream"
#include "vector"

using namespace std;

bool oneEditAway(string first, string second) {
    size_t firstSize = first.size();
    size_t secondSize = second.size();
    if(firstSize == secondSize){
        int diff = 0;
        for(int i = 0; i < firstSize; i++){
            if(first[i] == second[i])
                diff++;
        }
        if(diff <= 1)
            return true;
        else
            return false;
    }
    if(firstSize > secondSize){
        swap(first, second);
        swap(firstSize, secondSize);
    }
    if(secondSize - firstSize > 1)
        return false;
    int diff = 0;
    for(int i = 0; i < firstSize; i++){
        if(first[i - diff] != second[i]){
           diff++;
        }
    }
    if(diff > 1)
        return false;
    return true;
}

int main(){
    string first = "ab", second = "bc";
    if(oneEditAway(first, second)){
        cout << "True";
    }
    else
        cout << "False";
}