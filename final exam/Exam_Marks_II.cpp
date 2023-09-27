#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int S = 1005;
bool dp[S];
bool subset_sum(vector<int> &a, int n, int s)
{
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= s; j++)
        {
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    return dp[s];
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
            cin >> a[i];
        if (subset_sum(a, n, s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}