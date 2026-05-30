#include<bits/stdc++.h>
using namespace std;

 int sqrt(int x) {
     int res = 0;
        for(long long i = 1; i * i <= x; i++){
            res = i;
        }
        return res;
    }

int main() {
    int x = 4;

    cout << sqrt(x);
    return 0;
}