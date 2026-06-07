#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> mp;
    unordered_set<int> childs;

    for (auto &d : descriptions) {
        int p = d[0], c = d[1], l = d[2];

        if (!mp.count(p)) mp[p] = new TreeNode(p);
        if (!mp.count(c)) mp[c] = new TreeNode(c);

        if (l) mp[p]->left = mp[c];
        else mp[p]->right = mp[c];

        childs.insert(c);
    }

    for (auto &d : descriptions)
        if (!childs.count(d[0]))
            return mp[d[0]];

    return nullptr;
}

void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        cout << cur->val << " ";

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> descriptions(n, vector<int>(3));

    for (int i = 0; i < n; i++)
        cin >> descriptions[i][0] >> descriptions[i][1] >> descriptions[i][2];

    TreeNode* root = createBinaryTree(descriptions);

    levelOrder(root);

    return 0;
}