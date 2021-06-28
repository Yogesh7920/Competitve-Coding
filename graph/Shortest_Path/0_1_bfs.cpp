#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<vector<array<int, 2>>, 1001> adj;
vector<int> dist;

void bfs(int s) {
    deque<int> q;
    q.push_front(s);
    dist[s] = 0;
    int u, v, w;
    while (!q.empty()) {
        u = q.front() ;q.pop_front();
        for (auto ar : adj[u]) {
            v = ar[0]; w = ar[1];
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                if (w == 1) {
                    q.push_back(v);
                } else {
                    q.push_front(v);
                }
            }
        }
    }

    for (auto x: dist) {
        cout << x << " ";
    }
    cout << endl;
}


void solve() {
    int n, m; cin >> n;
    int u, v, w;
    while (!cin.eof()) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dist.assign(n, -1);
    bfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}