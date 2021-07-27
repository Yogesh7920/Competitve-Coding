#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<int> coins;

void total_ways_coin_change(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (auto c: coins) {
        for (int i=1; i<=n; i++) {
            if (i>=c) {
                dp[i] = dp[i-c] + dp[i];
            }
        }
    }
    cout << dp[n] << endl;
}

void min_coin_change(int n) {
    vector<int> dp(n+1, INT16_MAX);
    dp[0] = 0;
    for (auto c: coins) {
        for (int i=1; i<=n; i++) {
            if (i >= c) {
                dp[i] = min(dp[i], 1 + dp[i-c]);
            }
        }
    }
    cout << ((dp[n] == INT16_MAX) ? -1 : dp[n]) << endl;

}

void solve() {
    int n, m; cin >> n >> m;
    int t;
    for (int i=0; i<m; i++) {
        cin >> t;
        coins.push_back(t);
    }

//    total_ways_coin_change(n);
    min_coin_change(n);
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