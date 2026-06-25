#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& n) {
    int l = 0;
    int sum = 0;
    int ans = INT_MAX;

    for (int r = 0; r < n.size(); r++) {
        sum += n[r];

        while (sum >= target) {
            ans = min(ans, r - l + 1);

            sum -= n[l];
            l++;
        }
    }

    return ans == INT_MAX ? 0 : ans;
}

int main() {
    int n, target;
    cin >> target >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << minSubArrayLen(target, nums);

    return 0;
}