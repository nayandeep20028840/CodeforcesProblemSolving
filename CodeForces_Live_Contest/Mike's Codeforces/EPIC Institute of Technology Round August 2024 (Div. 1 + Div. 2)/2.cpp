#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

bool solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    int f = 0;
    int i1 = 0, i2 = 0, j1 = n - 1, j2 = n - 1;
    while (i1 <= j1 and i2 <= j2)
    {
        if (a[i1] == b[i2] and a[j1] == b[j2])
        {
            i1 += 1;
            i2 += 1;
        }
        else if (a[i1] == b[j2] and b[i2] == a[j1])
        {
            i1 += 1;
            j2 -= 1;
        }
        else
        {
            f = 1;
            break;
        }
    }
    if (f)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
        {
        }
        else
        {
        }
    }
    return 0;
}
