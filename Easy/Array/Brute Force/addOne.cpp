#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> digits = {1,2,9};
    if(digits[digits.size()-1] == 9){
         digits[digits.size() - 2] += 1;
         digits[digits.size() - 1] -= 9;
    } else{
    digits[digits.size() - 1] += 1;
}
    for(int i : digits){
        cout << i<< " ";
    }
    return 0;
}