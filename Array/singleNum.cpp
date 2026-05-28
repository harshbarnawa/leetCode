#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int singleNumber(vector<int>& nums) {
        int num = 0;
        for(int i : nums){
            num ^= i;
        }
    return num;

};
};

int main() {

    Solution obj;

    vector<int> nums = {4,1,2,1,2};


    int num = obj.singleNumber(nums);

    cout << num;

    

    return 0;
}