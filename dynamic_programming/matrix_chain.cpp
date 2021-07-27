#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// bursting balloon, maximised matrix multiplication
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int left, right, last, window;
    for (window=1; window<=n; window++) {
        for (left=1; left <= n-window+1; left++) {
            right = left + window - 1;
            for (last=left; last <= right; last++) {
                dp[left][right] = max(dp[left][right],
                                      nums[left-1] * nums[last] * nums[right+1] +
                                      dp[left][last-1] + dp[last+1][right]);
            }
        }
    }

    return dp[1][n];
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &x: nums) {
        cin >> x;
    }

    cout << maxCoins(nums);
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