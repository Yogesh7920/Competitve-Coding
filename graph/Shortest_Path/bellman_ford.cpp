// bellman_ford.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
auto infinity = numeric_limits<ll>::max();
vector<array<ll, 3>> edges;
array<ll, 10001> dist ;

void distance_vector(ll x, int n) {
    dist.fill(infinity);
    dist[x] = 0;
    for (int i=0; i<n-1; i++) {
        for (auto &edge: edges) {
            int u=edge[0], v=edge[1], w=edge[2];
            if (dist[u] != infinity && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}


int main() {
    ifstream file;
    int n;
    string f;
    cin >> n >> f;
    file.open(f);

    if (file.is_open()) {
        while(!file.eof()) {
            int u, v, w;
            file >> u >> v >> w;
            edges.push_back({u, v, w});
        }
    } else {
        cout << "unable to open file" << endl;
        return 0;
    }


    for (int i=1; i<=n; i++) {
        distance_vector(i, n);
        cout << "Routing table of router " << i << endl;
        for (int j=1; j<=n; j++) {
            cout << j << " = " << dist[j] << ", ";
        }
        cout << endl << endl;
    }

    file.close();

    return 0;
}
