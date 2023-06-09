#include <bits/stdc++.h>
using namespace std;

const long long int mod97 = 1000000007;
const long long int modg = 998244353;
const long long int inf = 1e18;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(dp) memset(dp, -1, sizeof(dp))
#define bpp __builtin_popcount
#define bppll __builtin_popcountll
#define Pi 3.1415926535897932384626

void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    ll sum4 = 0;
    if (n == 1){
        for (ll i = 0; s[i] != '\0'; i++){
            sum4 = sum4 + s[i];
        }
        cout << "Bob"
             << " " << sum4 - 96 << endl;
        return;
    }
    ll sum = 0;
    ll sum1 = 0;
    if (n % 2 != 0){
        for (ll i = 0; i < n / 2; i++){
            sum = sum + s[i] - 96;
        }
        for (ll i = n / 2; i < n; i++){
            sum1 = sum1 + s[i] - 96;
        }
    }
    ll sum5 = 0, sum6 = 0;
    if (n % 2 != 0){
        for (ll i = 0; i < n / 2 + 1; i++){
            sum5 = sum5 + s[i] - 96;
        }
        for (ll i = n / 2 + 1; i < n; i++){
            sum6 = sum6 + s[i] - 96;
        }
    }
    // cout<<sum<<endl;
    // cout<<sum1<<endl;
    if (sum5 > sum1){
        cout << "Alice"
             << " " << sum5 - sum6 << endl;
        return;
    }
    else if (sum1 > sum5){
        cout << "Alice"
             << " " << sum1 - sum << endl;
        return;
    }
    ll sum3 = 0;
    if (n % 2 == 0){
        for (ll i = 0; s[i] != '\0'; i++)
            sum3 = sum3 + s[i] - 96;
        cout << "Alice"
             << " " << sum3 << endl;
        return;
    }
    if (sum1 == sum5){
        cout << "Alice"
             << " " << sum1 - sum << endl;
        return;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // long long int count = 1;

    while (t--)
    {
        // cout << "Case #" << count << ": ";
        solve();
        // count++;
    }

    return 0;
}