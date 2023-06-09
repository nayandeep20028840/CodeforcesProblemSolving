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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll count = n;
    // ll c=0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            count++;
            //     c++;
            //     if(c>1){
            //         count = count + c;
            //     }
            // }else{
            //     c=0;
            // }
        }
    }
    for (ll i = n - 1; i > 0; i--)
    {
        if (s[i] == '1' && s[i - 1] == '0')
        {

            for (ll j = (i - 1 - 1); j >= 0; j--)
            {
                if (s[j] == '0')
                {
                    count++;
                }
                if(s[j] == '1'){
                    if(j!=0){
                        if(s[j-1]=='0'){
                            count = count + 2;
                        }
                        // }else{
                        //     count++;
                        // }
                    }
                }
            }
            // count = count + (i+1 - 2);
        }
        if (s[i] == '0' && s[i - 1] == '1')
        {

            for (ll j = (i - 1 - 1); j >= 0; j--)
            {
                if (s[j] == '1')
                {
                    count++;
                }
                // if(s[j] == '1'){
                //     if(j!=0){
                //         if(s[j-1]=='0'){
                //             count--;
                //         }else{
                //             count++;
                //         }
                //     }
                // }
            }
            // count = count + (i+1 - 2);
        }
    }
    for(ll i=n-1;i>2;i--){
        if(s[i]=='1' &&  s[i-1]=='0' && s[i-2]=='0' && s[i-3]=='1'){
            count++;
        }
    }
    cout << count << '\n';
    return;
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