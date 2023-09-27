#include <bits/stdc++.h>
using namespace std;
int main()
{
    int e;
    cin >> e;
    vector<int> a(e);
    vector<int> b(e);
    for (int i = 0; i < e; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<int> order(e);
    for (int i = 0; i < e; i++)
    {
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&](int i, int j)
         { return make_pair(a[i], b[i]) < make_pair(a[j], b[j]); });
    for (int i : order)
    {
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}