#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rever(int x) {
        
        int rev = 0;
        bool isNeg = false;
        if(x==INT_MIN){
            return 0;
        }
        if(x < 0){
            x *= -1;
            isNeg = true;
        }
        while(x > 0){
             int dig = x % 10;

            if (rev > INT_MAX / 10 ||
               (rev == INT_MAX / 10 && dig > 7))
                return 0;
            rev = rev * 10 + dig;
            x/= 10;
        }

        if(isNeg){
            return rev * -1;
        } else{
            return rev;
        }
    }
};


int main() {
    Solution obj;
    cout << obj.rever(123);

    return 0;
}