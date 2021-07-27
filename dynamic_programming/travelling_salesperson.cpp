#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
unordered_map<int, unordered_map<int, int>> dp;

int travelling_salesperson(const vector<vector<int>> &cost, int start, int cur, int need, int n)
{
    if (dp[cur].count(need))
    {
        return dp[cur][need];
    }

    if (need == 0)
        return cost[cur][start];

    int mn = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        auto mask = 1 << i;
        if (mask & need)
        {
            mn = min(mn, travelling_salesperson(cost, start, i, need ^ mask, n) + cost[cur][i]);
        }
    }
    dp[cur][need] = mn;
    return mn;
}

int total_cost(const vector<vector<int>> &cost, int n)
{
    return travelling_salesperson(cost, 0, 0, ((1 << n) - 1) ^ 1, n); // You need not see the start as need is 0 we go to start itself.
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (auto &x : cost)
    {
        for (int i = 0; i < n; i++)
            cin >> x[i];
    }
    cout << total_cost(cost, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    int t; cin >> t;
    //    for (int i=1; i<=t; i++) {
    //        cout << "Case #" << i  << ": ";
    solve();
    //    }
    return 0;
}