#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& n) {
    int j = 0;

    for (int i = 0; i < n.size(); i++) {
        if (n[i] != 0) {
            swap(n[i], n[j]);
            j++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    moveZeroes(nums);

    for (int x : nums)
        cout << x << " ";

    return 0;
}