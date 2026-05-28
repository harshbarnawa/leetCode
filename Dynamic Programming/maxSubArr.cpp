//Kadane's Algorithm said if -ve reset to 0;
//Dynamic Programming
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int cS = 0, maxS = INT_MIN;
        for(int i : nums){
            cS += i;
            maxS = max(cS,maxS);
            if(cS < 0){
                cS =0;
            }
        }

        return maxS;
    }
};



int main() {

    Solution obj;

     int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = obj.maxSubArray(nums);

    cout << "Maximum Subarray Sum = " << ans << endl;

    

    return 0;
}