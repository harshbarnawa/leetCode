#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (int num : nums)
        mp[num]++;

    priority_queue<pair<int, int>> pq;

    for (auto it : mp)
        pq.push({it.second, it.first});

    vector<int> ans;

    while (k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = topKFrequent(nums, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}