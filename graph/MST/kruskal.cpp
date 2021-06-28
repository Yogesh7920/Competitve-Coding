#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<array<int, 3>> g;
array<int, 10001> parent;
array<int, 10001> r = {0};

int find(int x) {
    auto par = parent[x] == x ? x : find(parent[x]);
    parent[x] = par; // path compression
    return par;
}

void join(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (r[p1] > r[p2]) {
        parent[p2] = p1;
    } 
    else if (r[p1] < r[p2]) {
        parent[p1] = p2;
    }
    else {
        parent[p2] = p1;
        r[p1]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m ;
    int u, v, w;

    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        g.push_back({w, u, v});
    }

    auto f = [](array<int, 3> x, array<int, 3> y) {return x[0] < y[0];};
    sort(g.begin(), g.end(), f);
    for (int i=0; i<=n; i++)
        parent[i] = i;

    int ans = 0;
    for (auto e: g) {
        w = e[0]; u = e[1]; v = e[2];
        int p1 = find(u), p2 = find(v);
        if (p1 != p2) {
            ans += w;
            join(p1, p2);
        }
    }

    cout << ans << endl;

    return 0;
}