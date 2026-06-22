#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string temp = s;

        sort(temp.begin(), temp.end());
        mp[temp].push_back(s);
    }

    vector<vector<string>> ans;

    for (auto &i : mp)
        ans.push_back(i.second);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++)
        cin >> strs[i];

    vector<vector<string>> ans = groupAnagrams(strs);

    for (auto &group : ans) {
        for (auto &word : group)
            cout << word << " ";

        cout << '\n';
    }

    return 0;
}