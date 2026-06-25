#include <bits/stdc++.h>
using namespace std;

int countMajoritySubarrays(vector<int>& nums, int target) {
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        int ct = 0;

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == target)
                ct++;

            if (ct > (j - i + 1 - ct))
                ans++;
        }
    }

    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << countMajoritySubarrays(nums, target);

    return 0;
}