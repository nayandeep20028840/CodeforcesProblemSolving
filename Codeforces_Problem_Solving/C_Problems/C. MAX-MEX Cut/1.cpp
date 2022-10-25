#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define ll                long long
#define all(v)            v.begin(),v.end()
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define pii               pair<int,int>
#define bpp               __builtin_popcount
#define Pi                3.1415926535897932384626
 
 
long long power(long long int a, long long int n)
{
if (n == 0)return 1; if (n % 2 == 0) {long long val = power(a, n / 2); val = (val * val); return val;}
else {long long val = power(a, n / 2); val = ((val * val) * a) ; return val;}
}
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
 
bool checkpalindrome(ll i){  // check palindrome number in n/2 time complexity
    string s=to_string(i);
    bool flag=0;
    int n=s.length();
    for (ll i=0;i<n;i++){
        if (s[i]!=s[n-1-i]){
            flag=1;
            break;
        }
    }
    if(flag){
        return 0;
    }else{
        return 1;
    }
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string s1;
    cin>>s1;
    ll ans = 0;
    ll one = 0;
    ll zero = 0;
    for(ll i=0;i<n;i++){
        if(s[i]!=s1[i]){
            ans += 2;
        }
        if(s[i]==s1[i] && s[i]=='0'){
            zero++;
        }
        if(s[i]==s1[i] && s[i]=='1'){
            one++;
        }
    }
    for(ll i=0;i<n;i++){
        if(s[i]==s1[i] && s[i]=='1'){
            if(s[i+1]==s1[i+1] && s[i+1]=='0'){
                ans += 2;
                i++;
            }
        }
        else if(s[i]==s1[i] && s[i]=='0'){
            if(s[i+1]==s1[i+1] && s[i+1]=='1'){
                ans += 2;
                i++;
            }else{
                ans += 1;
            }
        }
    }
    cout<<ans<<'\n';
    return;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
    int t;
    cin >> t;  // long long int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }

    return 0;
}