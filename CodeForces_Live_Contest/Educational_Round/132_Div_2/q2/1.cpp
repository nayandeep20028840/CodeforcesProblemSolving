#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
const long long int inf = 1e18;
 
#define ll                long long
#define all(v)            v.begin(),v.end()
#define ld                long double
#define mp                make_pair
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define lb                lower_bound
#define ub                upper_bound
#define ts                to_string
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(dp)          memset(dp,-1,sizeof(dp))
#define bpp               __builtin_popcount
#define bppll             __builtin_popcountll
#define Pi                3.1415926535897932384626
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
char convertIntToChar(int num) {
    char ch = 'a'+num;
    return ch;
}
 
void binaryform(int num){
    for (int i = 10;i >= 0;--i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
 
void left_right_shift(int num){
    cout << (num>>1) << endl; //if num=5(101) it will return 2(10)
    cout << (num<<1) << endl; //if num=5(101) it will return 10(1010)
}

int binaryTodecimal(string n)
{
    string num = n;
    int decimal_value = 0;
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--){
        if (num[i] == '1'){
            decimal_value += base;
        }
        base = base * 2;
    }
    return decimal_value;
}
 
const int N = 1e5 + 4;
const int M = 1e9 + 7;
 
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> prefix(n);
    vector<ll> suffix(n);
    prefix[0]=0;
    suffix[n-1]=0;
    for(ll i=1;i<n;++i){
        if(a[i-1]>a[i])
        prefix[i] = prefix[i-1] + a[i-1] - a[i];
        else
        prefix[i] = prefix[i-1];
    }
    for(ll i=n-2;i>=0;--i){
        if(a[i+1]>a[i])
        suffix[i] = suffix[i+1] + a[i+1] - a[i];
        else
        suffix[i] = suffix[i+1];
    }
    while(m--){
        ll t,t1;
        cin>>t>>t1;
        if(t<=t1){
            cout<<prefix[t1-1] - prefix[t-1]<<'\n';
        }else{
            cout<<suffix[t1-1] - suffix[t-1]<<'\n';
        }
    }
}
 