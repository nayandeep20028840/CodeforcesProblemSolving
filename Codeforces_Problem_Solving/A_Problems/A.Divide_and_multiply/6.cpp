#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long int>

int main()
{
    ios_base::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--)
        {
            ll int n, c1 = 0, c2 = 0, c3 = 0, sum = 0, e, f;
            cin >> n;
            vector<ll > v1(n);
            vector<ll > v2;
            vector<ll > v3;
            vector<ll > v4;
            for (ll i = 0; i < n; i++)
            {
                cin >> v1[i];
                if (v1[i] % 2 == 0)
                {
                    c1++;
                    v4.push_back(v1[i]);
                }
                else if (v1[i] == 1)
                {
                    v2.push_back(v1[i]);
                }
                else
                {
                    v3.push_back(v1[i]);
                }
            }
            sort(v1.begin(), v1.end(), greater<ll>());
            if (c1 == n)
            {
                for (ll  i = 1; i < n; i++)
                {
                    while (v1[i] / 2 > 0)
                    {
                        c2++;
                        v1[i] = v1[i] / 2;
                    }
                }
                cout << v1[0] * pow(2, c2) + n - 1 << '\n';
            }
            else
            {
                for (ll  i = 0; i < v4.size(); i++)
                {
                    while (v4[i] / 2 > 0)
                    {
                        c3++;
                        v4[i] = v4[i] / 2;
                    }
                }
                e = *max_element(v3.begin(), v3.end());
                f = accumulate(v3.begin(), v3.end(), 0);
                cout << e * pow(2, c3) + v2.size() + v4.size() + f - e << '\n';
            }
        }
    return 0;
}