#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& n) {
    int i = 0;

    for (int j = 1; j < n.size(); j++) {
        if (n[i] != n[j]) {
            i++;
            n[i] = n[j];
        }
    }

    return i + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k = removeDuplicates(nums);

    cout << k << '\n';

    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";

    return 0;
}