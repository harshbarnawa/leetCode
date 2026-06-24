#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r) {
        int sum = numbers[l] + numbers[r];

        if (sum == target) {
            return {l + 1, r + 1};
        }
        else if (sum < target) {
            l++;
        }
        else {
            r--;
        }
    }

    return {};
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    vector<int> ans = twoSum(numbers, target);

    for (int x : ans)
        cout << x << " ";

    return 0;
}