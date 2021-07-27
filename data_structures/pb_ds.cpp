#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long int ll;

void solve() {
    ordered_set<array<int, 2>> os;
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        os.insert({arr[i], i});
    }
    for (int i=0; i<q; i++) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == '!') {
            auto it = os.find({arr[a], a});
            os.erase(it);
//            os.erase(os.find_by_order(os.order_of_key({arr[a], a})));
            arr[a] = b;
            os.insert({arr[a], a});
        } else {
            auto last = os.order_of_key({arr[b+1], 0 });
            auto first = os.order_of_key({arr[a], 0});
            cout << last - first << endl;
        }
    }
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