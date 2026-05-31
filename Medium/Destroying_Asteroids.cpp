#include<bits/stdc++.h>
using namespace std;

int main() {
    int mass = 5;
    vector<int> asteroids = {4,9,23,4};
    int largest = INT_MIN;
    int n = asteroids.size();
    int sum = 0;

    for(int j = 0;j<n;j++){
        if(asteroids[j]>largest){
            largest = asteroids[j];
        }
    }
    for(int i : asteroids){
        sum += i;
    }
    sum -= largest;
    sum += mass;
    if(sum>largest){
        cout << true;
    } else {
        cout << false;
    }
    return 0;
}