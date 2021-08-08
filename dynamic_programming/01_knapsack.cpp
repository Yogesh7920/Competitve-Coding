#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int knapsack(int s, int n, vector<int> ws, vector<int> ps) {
    vector<int> dp(s+1, 0); // use 1-d if u want to find only the max value and not the elements itself.
    for (int i=1; i<=n; i++) {
        for (int j=s; j>=ws[i]; j--) { // run from right to left for O(1) storage. 
            if (ws[i] <= j) {
                dp[j] = max(ps[i] + dp[j - ws[i]], dp[j]);
            }
        }
    }
    return dp[s];
}

void solve() {
    int s, n; cin >> s >> n;
    int w, p;
    vector<int> ws {0};
    vector<int> ps {0};
    for (int i=0; i<n; i++) {
        cin >> w >> p;
        ws.push_back(w);
        ps.push_back(p);
    }

    cout << knapsack(s, n, ws, ps) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// int knapsack(int s, int n, vector<int> ws, vector<int> ps) {
//     int dp[n+1][s+1];
//     for (int i=0; i<=n; i++) {
//         for (int j=0; j<=s; j++) {
//             if (i == 0 || j == 0) {
//                 dp[i][j] = 0;
//             } else if (ws[i-1] > j) {
//                 dp[i][j] = dp[i-1][j];
//             }
//             else {
//                 dp[i][j] = max(ps[i-1] + dp[i-1][j - ws[i-1]], dp[i-1][j]);
//             }
//         }
//     }
//     return dp[n][s];
// }

// void solve() {
//     int s, n; cin >> s >> n;
//     int w, p;
//     vector<int> ws;
//     vector<int> ps;
//     for (int i=0; i<n; i++) {
//         cin >> w >> p;
//         ws.push_back(w);
//         ps.push_back(p);
//     }

//     cout << knapsack(s, n, ws, ps) << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr); cout.tie(nullptr);
//     int t; cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }