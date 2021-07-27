#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{

    int n = startTime.size();
    vector<array<int, 3>> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = array<int, 3>{startTime[i], endTime[i], profit[i]};
    }

    sort(jobs.begin(), jobs.end(), [](auto a, auto b)
         { return array<int, 3>{a[0], -a[2], a[1]} < array<int, 3>{b[0], -b[2], b[1]}; });
    vector<int> dp(n);

    dp[n - 1] = jobs[n - 1][2];

    for (int i = n - 2; i >= 0; i--)
    {
        auto end = jobs[i][1];
        auto it = lower_bound(jobs.begin(), jobs.end(), array<int, 3>{end, 0, 0});
        if (it == jobs.end())
        {
            dp[i] = max(dp[i + 1], jobs[i][2]);
        }
        else
        {
            dp[i] = max(dp[i + 1], jobs[i][2] + dp[(it - jobs.begin())]);
        }
    }

    return dp[0];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n), Profit(n);

    for (auto &x : startTime)
        cin >> x;
    for (auto &x : endTime)
        cin >> x;
    for (auto &x : Profit)
        cin >> x;

    cout << jobScheduling(startTime, endTime, Profit);
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