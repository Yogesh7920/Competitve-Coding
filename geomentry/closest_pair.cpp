#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

float sq(float a) {
    return a*a;
}

float dist(const array<float, 2> &a, const array<float, 2> &b) {
    return sqrt(sq(a[0] - b[0]) + sq(a[1] - b[1]));
}

float mini(const vector<array<float, 2>> &arr, int f, int l) {
    int n = l-f;
    if (n == 3) {
        return min(min(dist(arr[0], arr[1]), dist(arr[1], arr[2])), dist(arr[0], arr[2]));
    }
    if (n == 2) {
        return dist(arr[0], arr[1]);
    }

    int mid = n/2;

    float d1 = mini(arr, f, mid);
    float d2 = mini(arr, mid+1, l);

    float d = min(d1, d2);

    vector<array<float, 2>> split;
    for (int i=f; i<l; i++) {
        auto ar = arr[i];
        float x = ar[0];
        if (abs(x-arr[mid][0]) < d) {
            split.push_back(ar);
        }
    }

    sort(split.begin(), split.end(), [](array<float, 2> a, array<float, 2> b) {
        return a[1] < b[1];
    });

    int sn = split.size();
    float mn = d;

    for (int i=0; i < sn; i++) {
        for (int j=i+1; j < sn && (split[j][1] - split[i][1]) < mn; j++) {
            mn = min(dist(split[i], split[j]), mn);
        }
    }

    return mn;

}

void solve() {
    int n;

    while (true) {
        cin >> n;
        if (!n) break;

        vector<array<float, 2>> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        sort(arr.begin(), arr.end());
        float d = mini(arr, 0, arr.size());

        if (d < 1000) {
            cout << d << endl;
        } else {
            cout << "INFINITY" << endl;
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