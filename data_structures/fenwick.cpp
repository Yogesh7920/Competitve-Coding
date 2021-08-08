#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int lsb(int x) {    
    // 2's compement will have first 1 from left unchanged and 
    // thus we will get the least significant bit.
    return (x & -x);
}
// * Very Important : index starts from 1 in fenwick tree.

void build(vector<int> &arr) {  // O(n)
    int n = arr.size();
    for (int i=1; i<=n; i++) {
        int p = i + lsb(i);
        if (p <= n) {
            arr[p-1] *= arr[i-1];
        }
    }
}

int prefix(const vector<int> &arr, int x) { // O (log n)
    int ans = 1;
    while (x > 0) {
        ans *= arr[x-1];
        x -= lsb(x);
    }
    return ans;
}

int query(const vector<int> &arr, int l, int r) {
    return (prefix(arr, r) / prefix(arr, l-1)); // * (l-1) as l is inclusive.
}

void update(vector<int> &arr, int x, int v) {
    int n = arr.size();

    while (x <= n) {
        arr[x-1] *= v;
        x += lsb(x);
    }
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x: arr) cin >> x;
    build(arr);
    int q; cin >> q;
    for (int i=0; i<q; i++) {
        char t;
        int l, r; cin >> t >> l >> r;
        if (t == 'q')
            cout << query(arr, l+1, r+1) << endl;
        else
            update(arr, l+1, r);
    }
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