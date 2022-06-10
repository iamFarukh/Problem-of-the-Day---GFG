#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    return (a.first * a.second) > (b.first * b.second);
}
int maxCoins(int a[], int b[], int t, int n)
{
    if (t == 0)
        return 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i], b[i]});
    }
    int res = 0;
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (t >= v[i].first)
        {
            res += v[i].first * v[i].second;
            t -= v[i].first;
        }
        else
        {
            res += v[i].second * t;
            break;
        }
    }

    return res;
}
int main()
{
    int T = 3, N = 3;
    int A[] = {1, 2, 3};
    int B[] = {3, 2, 1};
    cout << maxCoins(A, B, T, N) << endl;
}
