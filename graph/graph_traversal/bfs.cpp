#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

array<unordered_set<int>, 1001> g;
unordered_set<int> visits;
deque<array<int, 2>> q;

void bfs(int x) {
    int count = 0;
    q.push_front({1, 1});
    while (!q.empty()) {
        auto val = q.front(); q.pop_front();
        visits.insert(val[0]);
        if (val[1] == x) {
            count ++;
            continue;
        }
        for (auto k: g[val[0]]) {
            if (!visits.count(k)) {
                q.push_back({k, val[1]+1});
            }
        }
    }

    cout << count << endl;
}

int main() {
    int n; cin >> n;
    int u, v;
    for (int i=0; i<n-1; i++) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int x; cin >> x;
    bfs(x);

    return 0;
}