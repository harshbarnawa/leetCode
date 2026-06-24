#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& p) {
    int l = 0, r = 1;
    int ans = 0;

    while (r < p.size()) {

        if (p[r] > p[l]) {
            ans = max(ans, p[r] - p[l]);
        }
        else {
            l = r;
        }

        r++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices);

    return 0;
}