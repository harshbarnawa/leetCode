#include<bits/stdc++.h>
using namespace std;

 bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
            sort(asteroids.begin(), asteroids.end());

        long long planetMass = mass;

        for(int i : asteroids) {
            if(planetMass < i) {
                return false;
            }

            planetMass += i;
        }

        return true;
        }

int main() {
    int mass = 5;
    vector<int> asteroids = {4,9,23,4};
    
    cout << asteroidsDestroyed(mass, asteroids);
    return 0;
}