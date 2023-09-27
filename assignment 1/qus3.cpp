#include <bits/stdc++.h>
using namespace std;
bool occurrences(vector<int> &a, int k)
{
    int l = 0;
    int r = a.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == k)
        {
            return (mid > l && a[mid - 1] == k) || (mid < r && a[mid + 1] == k);
        }
        else if (a[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    bool result = occurrences(a, k);
    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}