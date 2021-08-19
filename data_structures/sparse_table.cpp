#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int prod(int a, int b) {
    return a*b;
}

vector<vector<int>> build(const vector<int>& arr) {
    int n = arr.size();
    int p = floor(log(n) / log(2)); // Max power of 2 possible.

    vector<vector<int>> table(p+1, vector<int>(n));

    for (int i=0; i<n; i++)
        table[0][i] = arr[i];

    for (int i=1; i<=p; i++) {
        for (int j=0; j + (1 << i) <= n; j++) {
            table[i][j] = prod(table[i-1][j], table[i-1][j + ( 1 << (i-1) )]);
        }
    }
    return table;
}

// Works only for overlapping functions.
int queries(const vector<vector<int>>& table, int l, int r) {
    int ln = r-l+1;
    int p = floor(log(ln) / log(2));

    int left = table[p][l];
    int right = table[p][r - (1 << p) + 1]; // p, r - 2^p + 1.
    return min(left, right);
}


pair<vector<vector<int>>, vector<vector<int>>> build_with_index(const vector<int>& nums, int n) {
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
    return make_pair(sparse, sparse_index);
}

int query_with_index(const vector<int>& nums, const vector<vector<int>>& sparse_index, int l, int r) {
    int ln = r - l + 1;
    double t = log(ln) / log(2);
    int p = (int)t;
    int i1 = sparse_index[p][l], i2 = sparse_index[p][r - (1 << p) + 1];
    return min(nums[i1], nums[i2]);
}

// ! Use fenwick's tree instead.
int cascade_queries(const vector<vector<int>>& table, int l, int r) {
    int ln = r-l+1;
    int p = floor(log(ln) / log(2));
    int k = (1 << p);
    int res = 1;
    while (ln > 0) {
        res = prod(table[p][l], res);
        l += k;
        ln = r-l+1;
        p = floor(log(ln) / log(2));
        k = (1 << p);
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    auto table = build(arr);
    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
//        cout << queries(table, l, r) << endl;
        cout << cascade_queries(table, l, r) << endl;
    }

//    for (const auto& ar: table) {
//        for (auto a: ar) {
//            cout << a << " ";
//        }
//        cout << endl;
//    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    int t; cin >> t;
//    while (t--) {
        solve();
//    }
    return 0;
}