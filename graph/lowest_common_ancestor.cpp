#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;

    Node (int x) : val(x), left(nullptr), right(nullptr) {}

}*node;

node dfs(node root, int d, vector<int>& depth, vector<node>& nodes, unordered_map<node, int>& depth_map) {
    if (root == nullptr) return nullptr;
    depth.push_back(d);
    nodes.push_back(root);
    depth_map[root] = depth.size() - 1;
    auto left = dfs(root->left, d+1, depth, nodes, depth_map);
    if (left != nullptr) {
        depth.push_back(d);
        nodes.push_back(root);
        depth_map[root] = depth.size() - 1;
    }
    auto right = dfs(root->right, d+1, depth, nodes, depth_map);
    if (right != nullptr) {
        depth.push_back(d);
        nodes.push_back(root);
        depth_map[root] = depth.size() - 1;
    }

    return root;

}

vector<vector<int>> build_with_index(const vector<int>& nums, int n) {
    double t = log(n) / log(2);
    int p = (int)t;
    vector<vector<int>> sparse(p+1, vector<int>(n, -1)), sparse_index(p+1, vector<int>(n, -1));
    copy(nums.begin(), nums.end(), sparse[0].begin());
    for (int i=0; i<n; i++) sparse_index[0][i] = i;

    for (int i=1; i<=p; i++) {
        int end = n - (1 << i) + 1;
        for (int j=0; j<end; j++) {
            sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j + (1 << (i-1))]);
            sparse_index[i][j] = (sparse[i-1][j] == sparse[i][j]) ? sparse_index[i-1][j] : sparse_index[i-1][j + (1 << (i-1))];
        }
    }
    return sparse_index;
}

int query_with_index(const vector<int>& nums, const vector<vector<int>>& sparse_index, int l, int r) {
    int ln = r - l + 1;
    double t = log(ln) / log(2);
    int p = (int)t;
    int i1 = sparse_index[p][l], i2 = sparse_index[p][r - (1 << p) + 1];
    return nums[i1] == min(nums[i1], nums[i2]) ? i1 : i2;
}

node lowestCommonAncestor(node root, node p, node q) {

    vector<int> depth;
    vector<node> nodes;
    unordered_map<node, int> depth_map;

    dfs(root, 0, depth, nodes, depth_map);

    auto sparse = build_with_index(depth, depth.size());
    int l = depth_map[p], r = depth_map[q];
    int index = query_with_index(depth, sparse, min(l, r), max(l, r));
    return nodes[index];

}

void solve() {
    vector<int> nums {3,5,1,6,2,0,8,-1,-1,7,4};
    vector<node> nodes;
    transform(nums.begin(), nums.end(), back_inserter(nodes), [](int x) -> node {
        if (x == -1) return nullptr;
        else return new Node(x);
    });
    int n = nodes.size();

    for (int i=1; i<=n; i++) {
        int left = 2*i;
        int right = 2*i + 1;
        if (nodes[i-1] != nullptr && left <= n && right <= n) {
            nodes[i-1]->left = nodes[left-1];
            nodes[i-1]->right = nodes[right-1];
        }

    }

    node root = nodes[0];

    cout << lowestCommonAncestor(root, root->left, root->left->right->right)->val;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    int t; cin >> t;
//    for (int i=1; i<=t; i++) {
//        cout << "Case #" << i  << ": ";
    solve();
//    }
    return 0;
}