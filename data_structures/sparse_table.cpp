#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int prod(int a, int b) {
    return a*b;
}

vector<vector<int>> build(const vector<int>& arr) {
    int n = arr.size();
    int p = floor(log(n) / log(2));

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

int queries(const vector<vector<int>>& table, int l, int r) {
    int ln = r-l+1;
    int p = floor(log(ln) / log(2));

    int left = table[p][l];
    int right = table[p][r - (1 << p) + 1];
    return min(left, right);
}

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