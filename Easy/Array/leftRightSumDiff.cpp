#include<bits/stdc++.h>
using namespace std;
    vector<int> leftRightDifference(vector<int>& nums) {

        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            int right = total - left - nums[i];

            ans.push_back(abs(left - right));

            left += nums[i];
        }

        return ans;
    }
int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = leftRightDifference(nums);

    for(int x : ans)
        cout << x << " ";
}