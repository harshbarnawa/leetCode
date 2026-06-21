#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;

    mp[0] = -1;
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)
            sum -= 1;
        else
            sum += 1;

        if (mp.find(sum) != mp.end()) {
            ans = max(ans, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << findMaxLength(nums);

    return 0;
}