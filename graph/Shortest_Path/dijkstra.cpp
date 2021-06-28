#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<vector<array<int, 2>>, 10001> g;
array<int, 10001> dist ;

void dijkstra(int x, int n) {
    dist.fill(INT_MAX);
    dist[x] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;
    q.push({dist[x], x});
    int du, w, u, v;
    while (!q.empty()) {
        auto ar = q.top(); q.pop();
        du = ar[0]; u = ar[1];
        for (auto arr : g[u]) {
            v = arr[0]; w = arr[1];
            if (du + w < dist[v]) {
                dist[v] = du + w;
                q.push({dist[v], v});
            }
        }
    }

    for (int i=2; i<=n; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int u, v, w;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijkstra(1, n);

    return 0;
}