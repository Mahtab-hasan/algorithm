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
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    vector<int> result(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] >= arr2[j])
        {
            result[k] = arr1[i];
            i++;
        }
        else
        {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        result[k] = arr1[i];
        i++;
        k++;
    }
    while (j < m)
    {
        result[k] = arr2[j];
        j++;
        k++;
    }
    mergesort(result, 0, n + m - 1);
    for (int i = 0; i < n + m; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}