#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
const long long int inf = 1e18;
 
#define ll                long long
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
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll t=3;
    ll t1=3;
    ll a[n][t];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<t1;j++){
            cin>>a[i][j];
            if(a[i][0]==2){
                t1=2;
                continue;
            }
            if(a[i][0]==1){
                t1=3;
                continue;
            }
        }
    }
    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum = sum + v[i];
    }
    ll c=0;
    for(ll i=0;i<n;i++){
        if(a[i][0]==1){
            if(c>0)
            sum = sum + a[i][2] - sum/5; 
            else
            sum = sum + a[i][2] - v[a[i][1]-1]; 
            // sum = sum + a[i][2] - v[a[i][1]-1]; 
            cout<< sum <<endl;
        }
        c=0;
        if(a[i][0]==2){
            c++;
            sum = n*1ll*a[i][1];
            cout<<sum<<endl;
        }
    }
}
 