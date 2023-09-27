#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int S = 1005;
int dp[N][S];
bool subset_suum(vector<int> &a, int n, int s)
{
    if (s == 0)
        return true;
    if (n == 0)
        return false;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (a[n - 1] <= s)
    {
        dp[n][s] = subset_suum(a, n - 1, s - a[n - 1]) || subset_suum(a, n - 1, s);
    }
    else
    {
        dp[n][s] = subset_suum(a, n - 1, s);
    }
    return dp[n][s];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int s = 1000 - m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        if (subset_suum(a, n, s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}