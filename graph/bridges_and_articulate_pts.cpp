#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<int, 20> disc, low;
array<vector<int>, 20> adj;
set<int> pts;
set<array<int, 2>> bgs;

int n, m, time_=1;

void dfs(int u, int p=-1) {
    int child = 0;
    disc[u] = time_; low[u] = time_; time_++ ;
    for (auto v : adj[u]) {
        if (v == p) continue;
        else if (disc[v] != -1) {
            low[u] = min(low[u], disc[v]);
        } else {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        if (low[v] >= disc[u]) {
            if (p != -1)
                pts.insert(u);
            if (low[v] > disc[u]) {
                bgs.insert({min(u, v), max(u, v)});
            }
        }
    }
    if (child > 1 && p == -1) {
        pts.insert(u);
    }
}

void solve() {
    cin >> n >> m;
    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    disc.fill(-1);
    low.fill(-1);
    for (int i=1; i<=n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1);
        }
    }
    cout << pts.size() << endl;
    for (auto x: pts) {
        cout << x << " ";
    }
    cout << endl;
    cout << bgs.size() << endl;
    for (auto x: bgs) {
        cout << x[0] << " " << x[1] << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
