#include <bits/stdc++.h>
using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> v;

    for (int x : nums)
        v.push_back(to_string(x));

    sort(v.begin(), v.end(), [](string a, string b) {
        return a + b > b + a;
    });

    if (v[0] == "0")
        return "0";

    string ans = "";

    for (string s : v)
        ans += s;

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << largestNumber(nums);

    return 0;
}