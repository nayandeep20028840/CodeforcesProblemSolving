#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define ll                long long
#define int               ll
#define ld                long double
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
// #define im(a , n , m)     vector<vector<int>>a(n,vector<int>(m)); for(int i=0;i<n;++i){for(int j=0;j<m;++j){cin>>a[i][j];}}
#define yes               cout << "YES" << endl;
#define no                cout << "NO" << endl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.first<<" "<<i.second<<endl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<endl; }
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define bpp               __builtin_popcountll
#define Pi                3.1415926535897932384626
#define EPS               1e-9
#define nl                "\n"

const int mod97 = 1000000007;
const int modg = 998244353;
const int N  = 4e3 + 10;
int fac[N],invfact[N];vector<bool> isPrime(N,1);

int gcd(int a, int b) {if(b == 0){return a;} return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}
int power(int a, int b) {int res=1; while(b > 0) {if(b & 1) res= (res*a); a=(a*a); b=b >> 1;} return res;}
int inv_mult(int i) {if (i == 1) return 1; return (mod97 - ((mod97 / i) * inv_mult(mod97 % i)) % mod97) % mod97;}
string decToBinary(int n){string s=""; int i=0; while(n > 0) {s=to_string(n % 2) + s; n=n/2; i++;}return s;}
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x) {if (x>=0) {int sr = sqrt(x);return (sr * sr == x);}return false;}
int modpower(int x, int y){int res=1; x=x % mod97; while(y>0){if(y&1) res = (res*x) % mod97; y=y>>1; x=(x*x) % mod97;}return res;} 
int modInverse(int n){return power(n, modg - 2);} 
int ncr(int n,int r, int p){if(r > n){return 0;}if(n < 0 || r < 0){return 0;}if (r==0) return 1;int fac[n+1]; fac[0] = 1; for (int i=1 ; i<=n; i++) fac[i] = fac[i-1]*i%p;return (fac[n]* power(fac[r], p-2)%p*power(fac[n-r], p-2) % p) % p;}
void prime(){isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}}}
int isqrt(int n){long long x = sqrtl(n);while (x*x>n){--x;} while((x+1) * (x+1)<=n){++x;}return x;}
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
int errichtokabinary(int l,int r,vector<int>&a,int target){int ans=-1; while(l <= r){int mid=(l+(r-l)/2); if(a[mid]==target){ans=mid;return ans;}if(a[mid]<target)l=mid+1;else r=mid-1;}return ans;}
void nCr(int n, int r){long long p = 1, k = 1;if (n - r < r)r = n - r;if (r != 0) {while (r) {p *= n;k *= r;long long m = __gcd(p, k);p /= m;k /= m;n--;r--;}}else cout << p << endl;}

vector<int > adj[N] ;
bool visited[N] ;
int value[N] ;
string s ;

int dfs(int child , int parent){
    visited[child] = true ;
    value[child] = (s[child - 1] == 'W') - (s[child - 1] == 'B') ;
    for(auto &i : adj[child]){
        if(visited[i] == true) continue ;
        value[child] += dfs(i , child) ;
    } 
    return value[child] ;
}

bool solve(){
    memset(adj , 0 , sizeof(adj));
    memset(visited , 0 , sizeof(visited));
    memset(value , 0 , sizeof(value));
    int n ;
    cin >> n ;
    iv(v , n - 1)
    cin >> s ;
    int ans = 0 ;
    for(int i = 0 ; i < n - 1 ; ++i){
        adj[v[i]].pb(i + 2) ;
    }
    visited[1] = true ;
    dfs(1 , -1) ;
    for(int i = 1 ; i <= n ; ++i){
        if(value[i] == 0){
            ans ++ ;
        }
    }
    cout << ans << nl ;
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    freopen("error.txt", "w", stderr);
//#endif 
    int t;
    cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            //count++;
        }else{
            // cout << "NO" << endl;
        }
    }
    return 0;
}
 
 
 
 
 