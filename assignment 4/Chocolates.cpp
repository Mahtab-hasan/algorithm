#include <bits/stdc++.h>
using namespace std;
bool divide(int n, vector<int> &c)
{
    int total_Chocolate = 0;
    for (int i = 0; i < n; i++)
    {
        total_Chocolate += c[i];
    }
    if (total_Chocolate % 2 != 0)
        return false;
    int half = total_Chocolate / 2;
    vector<bool> dp(half + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = half; j >= c[i]; j--)
        {
            dp[j] = dp[j] || dp[j - c[i]];
        }
    }
    return dp[half];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        if (divide(n, c))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}