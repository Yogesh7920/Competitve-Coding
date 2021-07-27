#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve() {
    string p, s; cin >> p >> s;
    int m = p.size(), n = s.size();
    vector<int> kmp(m, 0);

    int i=1, j=0;
    while(i < m) {
        if (p[i] == p[j]) {
            j++;
            kmp[i] = j;
            i++;
        }
        else if (j == 0) {
            i++;
        }
        else {
            j = kmp[j-1];
        }
    }

//    for(auto x: kmp) {
//        cout << x << "\t";
//    }
//    cout << endl;
    int ans = 0;
    i=0; j=0;
    while (i < n) {
        if (s[i] == p[j]) {
            j++;
            i++;
        } else if (j == 0) {
            i++;
        } else {
            j = kmp[j-1];
        }
        if (j == m) {
            j = kmp[j-1];
            ans += 1;
        }
    }

    cout << ans << endl;
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