#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int gcd = 2; gcd <= max(n, m); ++gcd)
        {
            for (int g = gcd; g <= m and g <= n; g += gcd)
            {
                int tot = gcd * g;
                for (int b = g; b <= m; b += g)
                {
                    int a = tot - b ;
                    if (a > 0 and a <= n and __gcd(a, b) == g)
                    {
                        ans += 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
