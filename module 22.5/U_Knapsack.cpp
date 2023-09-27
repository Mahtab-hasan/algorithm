#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int w, vector<int> &weight, vector<int> &val)
{
    if (n == 0 || w == 0)
        return 0;
    if (weight[n - 1] > w)
    {
        return knapsack(n - 1, w, weight, val);
    }
    int choice1 = val[n - 1] + knapsack(n - 1, w - weight[n - 1], weight, val);
    int choice2 = knapsack(n - 1, w, weight, val);
    return max(choice1, choice2);
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> weight(n);
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> val[i];
    }
    int result = knapsack(n, w, weight, val);
    cout << result << endl;

    return 0;
}