#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
array<vector<char>, 1001> area;
array<vector<bool>, 1001> visit;

void room(int n, int m, int i, int j) {

    if (i<0 || i>= n) {
        return;
    }

    if (j < 0 || j >= m) {
        return;
    }

    if (area[i][j] == '#') {
        return;
    }

    visit[i][j] = true;
    room(n, m, i+1, j);
    room(n, m, i, j+1);
}

int main() {
    int n, m; cin >> n >> m;
    char temp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> temp;
            area[i].push_back(temp);
            visit[i].push_back(false);
        }
    }

    int rooms = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (area[i][j] == '.' && (!visit[i][j])) {
                rooms += 1;
                room(n, m, i, j);
            }
        }
    }

    cout << rooms << endl;

    return 0;
}