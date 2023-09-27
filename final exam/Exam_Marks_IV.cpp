#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
vector<vector<int>> dp(1005, vector<int>(1005, -1));
int fun(int n, int m, vector<int> &a)
{
    if (m == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int mark1 = 0, mark2 = 0;
    if (a[n - 1] <= m)
    {
        mark1 = fun(n, m - a[n - 1], a);
    }
    mark2 = fun(n - 1, m, a);
    return dp[n][m] = (mark1 + mark2) % mod;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        m = 1000 - m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = -1;
            }
        }
        int result = fun(n, m, a);
        cout << result << endl;
    }
    return 0;
}