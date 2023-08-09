#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    int ans = 0;
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    while(left <= right){
        if(people[right] >= limit){
            ans += 1;
            right--;
        }else{
            if((people[right] + people[left]) > limit){
                right--;
            }else{
                right--;
                left++;
            }
            ans++;
        }
    }
    return ans;
}

int main(){
    vector<int> people{3, 2, 2, 1};
    cout << numRescueBoats(people, 3);
}