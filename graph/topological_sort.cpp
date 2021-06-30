#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<vector<int>, 20> adj;
array<int, 20> visits;
stack<int> st;


void topo_sort(int u) {
    visits[u] = 1;
    for (auto v: adj[u]) {
        if (visits[v] == -1) {
            topo_sort(v);
        }
        else if (visits[v] == 1) {
            cout << "NOT DAC!";
            exit(0);
        }
    }
    visits[u] = 2;
    st.push(u);
}


void solve() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    visits.fill(-1);
    for (int i=0; i<n; i++)
        if (visits[i] == -1)
            topo_sort(i);

    int e;
    while(!st.empty()) {
        e = st.top(); st.pop();
        cout << e << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}