#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int p1 = mid - left + 1;
    int p2 = right - mid;

    vector<int> L(p1), R(p2);

    for (int i = 0; i < p1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < p2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < p1 && j < p2)
    {
        if (L[i] >= R[j])
        { // Use '>=' for descending order
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < p1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < p2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    // Merge the two arrays
    vector<int> result(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] >= arr2[j])
        { // Use '>=' for descending order
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

    // Perform Merge Sort on the merged array
    mergeSort(result, 0, n + m - 1);

    // Print the result array in descending order
    for (int i = 0; i < n + m; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
