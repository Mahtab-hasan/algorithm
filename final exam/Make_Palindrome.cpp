#include <bits/stdc++.h>
using namespace std;
int make_palindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        int result = make_palindrome(s);
        cout << result << endl;
    }

    return 0;
}