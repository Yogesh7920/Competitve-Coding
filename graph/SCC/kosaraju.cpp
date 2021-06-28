#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<vector<int>, 20> adj, iadj;
array<int, 20> comp, visits;
stack<int> st;
int scc = 0;

void kosaraju(int u) {
    visits[u] = 1;
    for (auto v: adj[u]) {
        if (visits[v] == -1) {
            kosaraju(v);
        }
    }
    st.push(u);
}

void kosaraju_inv(int u) {
    visits[u] = 1;
    comp[scc]++;
    for (auto v: iadj[u]) {
        if (visits[v] == -1) {
            kosaraju_inv(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        iadj[v].push_back(u);
    }

    visits.fill(-1);

    for (int i=1; i<=n; i++) {
        if (visits[i] == -1)
            kosaraju(i);
    }

    visits.fill(-1);
    comp.fill(0);

    int t;
    while(!st.empty()) {
        t = st.top(); st.pop();
        if (visits[t] == -1) {
            kosaraju_inv(t);
            scc++;
        }
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