#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &a, int left, int right, int k)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cin >> k;
    int index = search(num, 0, n - 1, k);
    if (index != -1)
        cout << index << endl;

    else
        cout << "Not Found" << endl;

    return 0;
}