#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> arr;
ll n;


void max_subarray() {
    ll cur_max = 0;
    ll g_max = numeric_limits<ll>::min();

    for (auto x: arr) {
        cur_max += x;
        g_max = max(g_max, cur_max);
        cur_max = cur_max > 0 ? cur_max : 0;
    }

    cout << g_max ;
}

void max_subseq() {
    vector<ll> dp(n, numeric_limits<ll>::min());
    dp[0] = arr[0];
    for (int i=1; i<n; i++) {
        dp[i] = max(max(arr[i] + dp[i-1], dp[i-1]), arr[i]);
    }
    cout << dp[n-1];
}

void solve() {
    cin >> n;
    ll temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    max_subarray();
    cout << " ";
    max_subseq();
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
        arr.clear();
    }
    return 0;
}