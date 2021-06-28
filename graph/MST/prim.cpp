#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<vector<array<int, 2>>, 10001> g;
array<bool, 10001> visits;

int prim(int x, int n) {
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    int ans = 0;
    do {
        visits[x] = true;
        for (auto y: g[x]) {
            if (!visits[y[1]])
               q.push(y);
        }

        while (!q.empty()) {
            auto e = q.top(); q.pop();
            x = e[1];
            if (!visits[x]) {
                ans += e[0];
                break;
            }
        }

    } while (!q.empty());

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    int u, v, w;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    cout << prim(1, n) << endl;

    return 0;
}