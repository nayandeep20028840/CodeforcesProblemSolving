#include <bits/stdc++.h>
using namespace std;

const long long int mod97 = 1000000007;
const long long int modg = 998244353;

#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define lb lower_bound
#define ub upper_bound
#define fr first
#define sc second
#define pii pair<int, int>
#define bpp __builtin_popcount
#define Pi 3.1415926535897932384626

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

bool checkpalindrome(ll i)
{ // check palindrome number in n/2 time complexity
    string s = to_string(i);
    bool flag = 0;
    int n = s.length();
    for (ll i = 0; i < n; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void solve()
{

    string s;
    cin >> s;
    ll n;
    cin >> n;
    ll a = n / 60;
    ll b = n % 60;
    ll c = 10 * (s[0] - '0') + (s[1] - '0');
    ll d = 10 * (s[3] - '0') + (s[4] - '0');
    ll ans = 0;
    string ss = "";
    ss += s[0];
    ss += s[1];
    ss += s[3];
    ss += s[4];
    if(ss[0] == ss[3] && ss[1] == ss[2]){
        ans++;
    }
    string sss = ss;
    while(1){
        c += a;
        d += b;
        c += d/60;
        d %= 60;
        c %= 24;
        ss = "";
        if(c/10 == 0){
            ss += '0';
        }
        ss += to_string(c);
        if (d/10 == 0){
            ss += '0';
        }
        ss += to_string(d);
        if(ss==sss){
            break;
        }
        if(ss[0]==ss[3] && ss[1]==ss[2]){
            ans++;
        }
    }
    cout << ans << '\n';
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