#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, int left, int mid, int right)
{
    int p1 = mid - left + 1;
    int p2 = right - mid;
    vector<int> l(p1), r(p2);
    for (int i = 0; i < p1; i++)
    {
        l[i] = a[left + i];
    }
    for (int j = 0; j < p2; j++)
    {
        r[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < p1 && j < p2)
    {
        if (l[i] >= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < p1)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < p2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    mergesort(num, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}