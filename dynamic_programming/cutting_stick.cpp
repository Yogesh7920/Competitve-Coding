#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
unordered_map<int, unordered_map<int, int>> dp;

int minCostRec(vector<int>& cuts, int idx, int jdx, int cx, int cy) {
    if (dp[idx].count(jdx)) {
        return dp[idx][jdx];
    }
    if (idx >= jdx || cx > cy) {
        return 0;
    }
    int cost = jdx - idx;
    int mn = INT_MAX;
    for (int i = cx; i<=cy; i++) {
        auto left = minCostRec(cuts, idx, cuts[i], cx, i-1);
        auto right = minCostRec(cuts, cuts[i], jdx, i+1, cy);
        mn = min(mn, left + right);
    }
    dp[idx][jdx] = mn + cost;
    return mn + cost;
}

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    return minCostRec(cuts, 0, n, 0, cuts.size()-1);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> cuts(m);
    for (auto &x: cuts) {
        cin >> x;
    }

    cout << minCost(n, cuts);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    int t; cin >> t;
//    for (int i=1; i<=t; i++) {
//        cout << "Case #" << i  << ": ";
        solve();
//    }
    return 0;
}