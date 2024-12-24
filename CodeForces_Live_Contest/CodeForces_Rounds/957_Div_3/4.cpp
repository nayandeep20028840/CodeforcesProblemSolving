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
    int n, m, k;
    cin >> n >> m >> k;
    string str;
    cin >> str;
    string s = "";
    s += 'L';
    s += str;
    s += 'L';
    int i = 0;
    int j = 0;
    while (i < n + 1)
    {
        int wehavel = 0;
        if ((s[i] == 'W' and k <= 0) || s[i] == 'C')
        {
            cout << "NO" << endl;
            return true;
        }
        else if (s[i] == 'W')
        {
            k -= 1;
            i += 1;
            while (i < n + 2 and k > 0 and s[i] == 'W')
            {
                k -= 1;
                i += 1;
            }
            continue;
        }
        for (j = i + m; j >= i + 1; --j)
        {
            if (s[j] == 'L')
            {
                wehavel = 1;
                break;
            }
        }
        int wehavew = 0;
        if (!wehavel)
        {
            for (j = i + m; j >= i + 1; --j)
            {
                if (s[j] == 'W')
                {
                    k -= 1;
                    wehavew = 1;
                    break;
                }
            }
        }
        else
        {
            i = j;
            continue;
        }
        if (!wehavew || k < 0)
        {
            cout << "NO" << endl;
            return true;
        }
        else
        {
            i = j + 1;
        }
    }
    cout << "YES" << endl;
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
