#include <bits/stdc++.h>
using namespace std;
bool reach(int n)
{
    vector<bool> dp(n + 1, false);
    dp[1] = true;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i])
        {
            if (i * 2 <= n)
                dp[i * 2] = true;
            if (i + 3 <= n)
                dp[i + 3] = true;
        }
    }
    return dp[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (reach(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}