#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int w, vector<int> &s, vector<int> &v)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (s[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s[i - 1]] + v[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        vector<int> s(n);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int val = knapsack(n, W, s, v);
        cout << val << endl;
    }
    return 0;
}