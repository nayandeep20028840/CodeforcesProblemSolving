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

ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

char convertIntToChar(int num)
{
    char ch = 'a' + num;
    return ch;
}

void convertnumbertobinary(int num)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

void left_right_shift(int num)
{
    cout << (num >> 1) << endl; // if num=5(101) it will return 2(10)
    cout << (num << 1) << endl; // if num=5(101) it will return 10(1010)
}

int binaryTodecimal(string n)
{
    string num = n;
    int decimal_value = 0;
    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
        {
            decimal_value += base;
        }
        base = base * 2;
    }
    return decimal_value;
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

// calculating factors of a number in sqrt(n) time complexity
// we can calculate whether a number is prime or not in sqrt(N) time complexity
// we can further calculate number of prime factors of a number
//     int num;
//     cin>>num;
//     vector<int> v;
//     for (ll i=1;i<=sqrt(num);i++){
//         if (num%i==0){
//             v.pb(i);
//             // v.pb(num/i);
//         }
//     }
//     for (ll i=sqrt(num);i>0;i--){
//         if (num%i==0){
//             // v.pb(i);
//             v.pb(num/i);
//         }
//     }
//     for(auto i : v){
//         cout<<i<<" ";
//     }
//     cout<<endl;

const int N = 1e5 + 4;
const int M = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int sum4 = 0;
    if (n == 1)
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            sum4 = sum4 + s[i];
        }
        cout << "Bob"
             << " " << sum4 - 96 << endl;
        return;
    }
    // else cout<<"Alice"<<endl;
    int sum = 0;
    int sum1 = 0;
    if (n % 2 != 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            sum = sum + s[i] - 96;
        }
        for (int i = n / 2; i < n; i++)
        {
            sum1 = sum1 + s[i] - 96;
        }
    }
    int sum5 = 0, sum6 = 0;
    if (n % 2 != 0)
    {
        for (int i = 0; i < n / 2 + 1; i++)
        {
            sum5 = sum5 + s[i] - 96;
        }
        for (int i = n / 2 + 1; i < n; i++)
        {
            sum6 = sum6 + s[i] - 96;
        }
    }
    // cout<<sum<<endl;
    // cout<<sum1<<endl;
    if (sum5 > sum1)
    {
        cout << "Alice"
             << " " << sum5 - sum6 << endl;
        return;
    }
    else if (sum1 > sum5)
    {
        cout << "Alice"
             << " " << sum1 - sum << endl;
        return;
    }
    int sum3 = 0;
    if (n % 2 == 0)
    {
        for (int i = 0; s[i] != '\0'; i++)
            sum3 = sum3 + s[i] - 96;
        cout << "Alice"
             << " " << sum3 << endl;
        return;
    }
    if (sum1 == sum5)
    {
        cout << "Alice"
             << " " << sum1 - sum << endl;
        return;
    }
    // int sum3 = 0;
    // if (n % 2 == 0)
    // {
    //     for (int i = 0; s[i] != '\0'; i++)
    //         sum3 = sum3 + s[i] - 96;
    //         cout << "Alice"
    //      << " " << sum3 << endl;
    //      return;
    // }
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