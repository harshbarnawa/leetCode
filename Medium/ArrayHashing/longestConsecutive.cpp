#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int longest = 0;

    for (int num : st) {
        if (st.find(num - 1) == st.end()) {

            int currentNum = num;
            int length = 1;

            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << longestConsecutive(nums);

    return 0;
}