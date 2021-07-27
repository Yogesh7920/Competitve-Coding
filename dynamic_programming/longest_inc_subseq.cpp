#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void longest_increasing(const vector<int>& arr){
    vector<int> dp;
    for (auto x: arr) {
        auto e = lower_bound(dp.begin(), dp.end(), x);
        if (e == dp.end()) {
            dp.push_back(x);
        } else {
            *e = x;
        }
    }

    cout << dp.size() << endl;
}


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x: arr) cin >> x;
    longest_increasing(arr);
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