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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll m;
    cin>>m;
    vector<ll> b(m);
    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll c=0;
    // ll t = min(n,m);
    // ll t1 = max(n,m);
    // for(ll i=0;i<t;i++){
    //     for(ll j=0;j<t1;j++){
    //         if(t==n){
    //             if(abs(a[i]-b[j])==0 || abs(a[i]-b[j])==1){
    //                 c++;
    //                 // i++;
    //                 // // b.remove(j);
    //                 // b.erase(b.begin()+j);
    //                 b[j]==110;
    //                 // if(i==(t)){
    //                 //     cout<<c<<endl;
    //                 //     return 0;
    //                 // }
    //                 break;
    //             }
    //         }
    //         else if(t==m){
    //             if(abs(b[i]-a[j])==0 || abs(b[i]-a[j])==1){
    //                 c++;
    //                 // i++;
    //                 // // b.remove(j);
    //                 // b.erase(b.begin()+j);
    //                 a[j]=110;
    //                 // if(i==(t-1)){
    //                 //     cout<<c<<endl;
    //                 //     return 0;
    //                 // }
    //                 break;
    //             }
    //             // cout<<i<<endl;
    //         }
    //     }
    //     // i++;
    // }
    // // cout<<c<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(abs(a[i]-b[j])<2){
                c++;
                b[j]=102;
                break;
            }
        }
    }
    cout<<c<<endl;
}
 