#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll ans, ct=0;
int k;
const ll mx = 2e6;
int trie[mx][26];
int ters[mx];

void dfs(int u, int d=0) {
    for (auto v: trie[u]) {
        if (v) {
            dfs(v, d+1);
            ters[u] += ters[v];
        }
    }

    int groups = ters[u] / k;
    ters[u] -= groups * k;
    ans += d * groups;
}

void build(const vector<string>& arr) {
    for (const auto& s: arr) {
        int temp = 0;
        for (auto c: s) {
            int x = c - 'A';
            if (!trie[temp][x]) {
                trie[temp][x] = ++ct;
            }
            temp = trie[temp][x];
        }
        ters[temp]++;
    }
}

void solve() {
    ans = 0; ct=0;
    memset(trie, 0, sizeof trie);
    memset(ters, 0, sizeof ters);
    int n; cin >> n >> k;
    vector<string> arr(n);
    for (auto &x: arr) cin >> x;
    build(arr);

    dfs(0);
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int i=1; i<=t; i++) {
        cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}