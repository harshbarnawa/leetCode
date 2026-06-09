#include <bits/stdc++.h>
using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {
    long long mx = *max_element(nums.begin(), nums.end());
    long long mn = *min_element(nums.begin(), nums.end());

    return 1LL * k * (mx - mn);
}

int main() {
    vector<int> nums = {1, 3, 2};
    int k = 2;

    cout << maxTotalValue(nums, k) << "\n";

    return 0;
}