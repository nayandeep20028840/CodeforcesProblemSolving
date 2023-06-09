#include<bits/stdc++.h>

//PBDS : Ordered set
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

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0 ;
// order_of_key(k)   returns count of elements strictly smaller than k ;

#define ll                long long
#define int               ll
#define ld                long double
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
#define yes               cout << "YES" << endl;
#define no                cout << "NO" << endl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<endl; } 
#define check3(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S<<endl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<endl; }
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define bpp               __builtin_popcountll
#define INF               1000000000000000000
#define Pi                3.1415926535897932384626
#define EPS               1e-9
#define nl                "\n"

const int mod97 = 1000000007 ;
const int modg = 998244353 ;
const int N  = 2e1 + 10 ;
int fac[N] , invfact[N] ;
vector<bool> isPrime(N , 1) ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ;

int gcd(int a, int b) {if(b == 0){return a ;} return gcd(b, a % b);}
int lcm(int a, int b){return (a / gcd(a, b) * b) ;}
int power(int x, int y) {int res = 1 ; while(y > 0) {if(y & 1) res = (res * x) ; x = (x * x) ; y = y >> 1 ;} return res ;}
int powermod(int x, int y){int res = 1; x = x % mod97; while(y > 0){if(y&1) res = (res * x) % mod97; y = y >> 1; x = (x * x) % mod97 ;}return res ;} 
int inv_mult(int i) {if (i == 1) return 1; return (mod97 - ((mod97 / i) * inv_mult(mod97 % i)) % mod97) % mod97;}
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
void prime(){isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}}}
int isqrt(int n){long long x = sqrtl(n);while (x*x>n){--x;} while((x+1) * (x+1)<=n){++x;}return x;}
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
int errichtokabinary(int l,int r,vector<int>&a,int target){int ans=-1; while(l <= r){int mid=(l+(r-l)/2); if(a[mid]==target){ans=mid;return ans;}if(a[mid]<target)l=mid+1;else r=mid-1;}return ans;}
void nCr(int n, int r){long long p = 1, k = 1;if (n - r < r)r = n - r;if (r != 0) {while (r) {p *= n;k *= r;long long m = __gcd(p, k);p /= m;k /= m;n--;r--;}}else cout << p << endl;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 
// int inverse(int a)
// {
//     return power(a,MOD-2);
// }

// int ncr(int n,int r)
// {
//     if(n<0 || r<0 || n<r)
//         return 0;
//     int ans=f[n];
//     ans=(ans*invf[r])%MOD;
//     ans=(ans*invf[n-r])%MOD;
//     return ans;
// }

// void precompute()
// {
//     f[0]=1;
//     for(int i=1;i<N;i++)
//         f[i]=(f[i-1]*i)%MOD;
//     for(int i=0;i<N;i++)
//         invf[i]=inverse(f[i]);
// }

vector<vector<int > > adj ;
vector<int > visited ;
vector<int > value ;

bool solve(){
    //adj.assign(n + 1 , vector<int >());
    //visited.assign(n + 1 , false) ;
    //value.assign(n + 1 , 0) ;
    int n ;
    cin >> n ;
    iv(a , n)
    iv(b , n)
    int cnt = 0 ;
    int mx = INT_MIN ;
    int l = 0 ;
    int r = 0 ;
    int lll = 0 ;
    int rr = 0 ;
    int ok = 0 ;
    // for(int i = 0 ; i < n ; ++i){
    //     if(a[i] != b[i]){
    //         lll = i + 1 ;
    //         rr = i + 1 ;
    //     }
    // }
    for(int i = 0 ; i < n - 1 ; ++i){
        if(b[i] <= b[i + 1]){
            if(l == 0) l = i + 1 ;
            r = i + 1 ;
            if(b[i] == a[i]) ok ++ ;
            cnt ++ ;
        }else{
            // cout << cnt << " " << ok << nl ;
            if(mx < cnt + 1 && ok != cnt){
                mx = cnt + 1 ;
                cnt = 0 ;
                lll = l ;
                rr = r ;
                l = 0 ;
                r = 0 ;
                ok = 0 ;
            }else{
                l = 0 ;
                r = 0 ;
                cnt = 0 ;
                ok = 0 ;
            }
        }
    }
    // cout << lll << " " << rr << nl ;
    if(mx < cnt + 1 && ok != cnt){
        mx = cnt + 1 ;
        cnt = 0 ;
        lll = l ;
        rr = r ;
    }
    // cout << mx << nl ;
    cout << lll << " " << rr + 1 << nl ;
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
 
 
 
 
// Think twice, code once. 