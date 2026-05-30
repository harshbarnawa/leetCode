#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 5,maxS=0;
    int arr[n] = {1, 2, 3, 4, 5};
    for(int k = 0;k < n;k++){
        for(int i = k;i < n;i++){
            int cSum = 0;
            
            for(int j = k;j < i + 1;j++){
                cSum += arr[j];
                maxS = max(cSum,maxS);
            }
            
    }
}
cout << maxS;
}