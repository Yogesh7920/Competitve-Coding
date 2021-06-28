#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

array<unordered_set<int>, 1001> g;
unordered_set<int> visits;

void dfs(int h) {
    visits.insert(h);
    for (auto x: g[h]) {
        if (!visits.count(x)) {
            dfs(x);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int head;
    cin >> head;
    dfs(head);
    cout << n - visits.size() << endl;
    return 0;
}