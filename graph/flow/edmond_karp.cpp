#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
unordered_map<int, unordered_map<int, array<int, 2>>> adj;
int max_flow = 0;
int source, sink;

array<int, 27> parent;
deque<int> qe;

void bfs() {
    qe.push_back(source);
    parent[source] = 0;
    int u, v;
    while (!qe.empty()) {
        u = qe.front(); qe.pop_front();
        for (auto x: adj[u]) {
            if (x.second[1] - x.second[0] != 0) {
                v = x.first;
                if (v == sink) {
                    parent[v] = u;
                    return;
                }
                if (parent[v] == -1) {
                    parent[v] = u;
                    qe.push_back(v);
                }
            }
        }
    }
}

void update_flow() {
    int mn = numeric_limits<int>::max();
    int temp = sink;
    int par;
    do {
        par = parent[temp];
        mn = min(mn, adj[par][temp][1]-adj[par][temp][0]);
        temp = par;
    } while(par != source);

    max_flow += mn;

    temp = sink;
    do {
        par = parent[temp];
        adj[par][temp][0] += mn;
        adj[temp][par][0] -= mn;
        temp = par;
    } while(par != source);

}

void edmond_karp() {

    while (true) {
        parent.fill(-1);
        bfs();
        qe.clear();
        if (parent[sink] == -1)
            break;
        update_flow();
    }

}

void solve() {
    int m;
    cin >> m;
    char u, v;
    int w;
    source = 'S' - 'A';
    sink = 'T' - 'A';

    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        adj[u-'A'][v-'A'] = {0, w};
        adj[v-'A'][u-'A'] = {0, 0};
    }

    edmond_karp();

    cout << max_flow << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}