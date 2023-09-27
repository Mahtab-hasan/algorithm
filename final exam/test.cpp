// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1005;
// const int S = 1005;
// bool dp[S];
// bool subset_sum(vector<int> &a, int n, int s)
// {
//     memset(dp, false, sizeof(dp));
//     dp[0] = true;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = a[i]; j <= s; j++)
//         {
//             dp[j] = dp[j] || dp[j - a[i]];
//         }
//     }

//     return dp[s];
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int s = 1000 - m;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }

//         if (subset_sum(a, n, s))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int make_palindrome(string s)
// {
//     int n = s.size();
//     vector<vector<int>> dp(n, vector<int>(n, 0));

//     for (int l = 2; l <= n; l++)
//     {
//         for (int i = 0; i < n - l + 1; i++)
//         {
//             int j = i + l - 1;
//             if (s[i] == s[j])
//             {
//                 dp[i][j] = dp[i + 1][j - 1];
//             }
//             else
//             {
//                 dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
//             }
//         }
//     }

//     return dp[0][n - 1];
// }

// int main() {
//     int T;
//     cin >> T;
//     cin.ignore(); // Ignore the newline character after reading T.

//     while (T--) {
//         string s;
//         cin >> s;

//         int minInsertions = make_palindrome(s);
//         cout << minInsertions << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T; // Read the number of test cases

    while (T--)
    {
        string a, b;
        cin >> a >> b; // Read the names of the dolls

        int n = a.size();
        int m = b.size();
        int dp[n + 1][m + 1];

        // Initialize the dp table
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        // Fill the dp table to find the length of the shortest common supersequence
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Calculate the length of the shortest common supersequence
        // The length is (length of a + length of b - length of LCS)
        cout << n + m - dp[n][m] << endl;
    }

    return 0;
}
