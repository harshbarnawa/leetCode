#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n) {
        tree.assign(4 * (n + 1), 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n, l, r);
    }
};

vector<bool> getResults(vector<vector<int>>& queries) {
    const int MAXX = 50000;

    set<int> obstacles;
    obstacles.insert(0);
    obstacles.insert(MAXX);

    for (auto &q : queries) {
        if (q[0] == 1) {
            obstacles.insert(q[1]);
        }
    }

    SegmentTree seg(MAXX);

    vector<int> pos(obstacles.begin(), obstacles.end());

    for (int i = 1; i < (int)pos.size(); i++) {
        seg.update(pos[i], pos[i] - pos[i - 1]);
    }

    vector<bool> ans;

    for (int i = (int)queries.size() - 1; i >= 0; i--) {
        auto &q = queries[i];

        if (q[0] == 2) {
            int x = q[1];
            int sz = q[2];

            auto it = obstacles.upper_bound(x);
            --it;

            int p = *it;

            int bestGap = seg.query(0, p);
            int tailGap = x - p;

            ans.push_back(max(bestGap, tailGap) >= sz);
        } else {
            int x = q[1];

            auto it = obstacles.find(x);

            auto prv = prev(it);
            auto nxt = next(it);

            int left = *prv;
            int right = *nxt;

            seg.update(right, right - left);
            seg.update(x, 0);

            obstacles.erase(it);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> queries = {
        {1,2},
        {2,3,3},
        {2,3,1},
        {2,2,2}
    };

    vector<bool> ans = getResults(queries);

    for (bool x : ans) {
        cout << (x ? "true" : "false") << " ";
    }

    return 0;
}