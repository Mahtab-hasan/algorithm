// #include <bits/stdc++.h>
// using namespace std;
// int dp[21][20001];
// bool result(vector<int> &a, int s, int c, int i)
// {
//     if (i == a.size())
//     {
//         return c == s;
//     }
//     if (dp[i][c] != -1)
//         return dp[i][c];
//     bool plus = result(a, s, c + a[i], i + 1);
//     bool minus = result(a, s, c - a[i], i + 1);
//     return dp[i][c] = plus || minus;
// }
// int main()
// {
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     memset(dp, -1, sizeof(dp));
//     if (result(a, x, 0, 0))
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Create a 2D DP array to store results
    vector<vector<bool>> dp(n + 1, vector<bool>(2 * x + 1, false));
    dp[0][x] = true; // Starting at position x

    // DP loop
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 2 * x; j++)
        {
            if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]])
            {
                dp[i][j] = true;
            }
            if (j + a[i - 1] <= 2 * x && dp[i - 1][j + a[i - 1]])
            {
                dp[i][j] = true;
            }
        }
    }

    if (dp[n][x])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
