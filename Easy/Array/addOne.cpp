#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> digits = {1,2,9};
    int num= 0, lastDig = 0;
    for(int i : digits){
        num = num * 10 + i; // merging nums
    }
    num+=1;
    digits.clear();
    while(num!=0){
        lastDig = num % 10;
        num /= 10;
        digits.insert(digits.begin(),lastDig);
    }
    cout << endl;
    for(int i : digits){
        cout << i<< " ";
    }
    
    return 0;
}