#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    mp[0] = 1;
    int sum = 0, ans = 0;

    for (int num : nums) {
        sum += num;

        if (mp.find(sum - k) != mp.end())
            ans += mp[sum - k];

        mp[sum]++;
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << subarraySum(nums, k);

    return 0;
}