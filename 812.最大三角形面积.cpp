#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

double largestTriangleArea(vector<vector<int>>& points) {
    sort(points.begin(),points.end());
}

int main(){
    vector<vector<int>> points = {{2, 0}, {0, 2}, {1, 0}, {0, 1}, {0, 0}};
    sort(points.begin(), points.end());
    for(auto c: points){
        for(auto b: c)
            cout << b << " ";
        cout << endl;
    }
}