#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int dist[10001][10001];

void floyd(int n) {
    for (int k=1;k<=n;k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }

    for (int i=2; i<=n; i++)
        cout << dist[1][i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dist[i][j] = (i==j ? 0 : INT16_MAX);


    int u, v, w;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    floyd(n);

    return 0;
}