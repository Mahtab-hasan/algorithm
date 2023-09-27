#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 1000 - m;
        vector<int> dp(s + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = a[i]; j <= s; j++)
            {
                dp[j] = min(dp[j], 1 + dp[j - a[i]]);
            }
        }
        if (dp[s] == INT_MAX - 1)
            cout << "-1" << endl;
        else
            cout << dp[s] << endl;
    }

    return 0;
}