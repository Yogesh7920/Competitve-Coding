#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void longest_subsequence(vector<int> &a, vector<int> &b, int n, int m) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
        }
    }
    deque<int> res;
    int i=n, j=m;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j-1]) {
            j--;
        }
        else {
            res.push_front(a[i-1]);
            i--; j--;
        }
    }

    for (auto x: res) cout << x << " ";
    cout << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    longest_subsequence(a, b, n, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    int t; cin >> t;
//    while (t--) {
        solve();
//    }
    return 0;
}