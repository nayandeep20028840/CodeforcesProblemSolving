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
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(dp)          memset(dp,-1,sizeof(dp))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
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

bool should_i_swap(pair<int,int> &a, pair<int,int> &b){
    
        return(a.second<b.second);
        
}
 
const int N = 1e5 + 4;
const int M = 1e9 + 7;
 
int main(){
    ll n,m;
    vector<pair<int,int>> v;
    cin>>n>>m;
    for (ll i = 0; i < m; i++){
       ll x,y;
       cin>>x>>y;
       v.pb(mp(x,y));
    }
    // for (int i=0; i<m; i++){
    //     cout << v[i].first << " "<< v[i].second << endl;
    // }
    sort(v.begin(),v.end(), should_i_swap); // will sort according to the first element
    // for (int i=0; i<m; i++){
    //     cout << v[i].first << " "<< v[i].second << endl;
    // }
    ll s=0;
    for (ll i = m-1; i>=0; i--){
        if(v[i].fr>=n){
           s=s+(n*v[i].sc);
           break;
        }else{
           s=s+(v[i].fr*v[i].sc);
           n=n-v[i].fr;
        }
    }
    cout<<s<<endl;
}
 