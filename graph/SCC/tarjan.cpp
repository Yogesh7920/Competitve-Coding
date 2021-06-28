#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<vector<int>, 20> adj;
array<int, 20> disc, low, comp;
array<bool, 20> stack_mem;
stack<int> st;
int t = 1, scc = 0;

void tarjan(int u) {
    disc[u] = t; low[u] = t; t++;
    stack_mem[u] = true;
    st.push(u);
    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (stack_mem[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    int w=-1, ct=0;
    if (disc[u] == low[u]) {
        while (w != u) {
            w = st.top(); st.pop();
            stack_mem[w] = false;
            ct++;
        }
        comp[scc] = ct;
        scc++;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    disc.fill(-1);
    low.fill(-1);
    stack_mem.fill(false);
    for (int i=1; i<=n; i++) {
        if (disc[i] == -1)
            tarjan(i);
    }
    int e=0, o=0;
    for (int i=0; i<scc; i++) {
        if ((comp[i] & 1) == 0) {
            e += comp[i];
        } else {
            o += comp[i];
        }
    }
    cout << o - e << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}