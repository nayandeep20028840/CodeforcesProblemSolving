#include<bits/stdc++.h>
using namespace std;

// Policy based data structures(PBDS) C++ STL
// order_of_key(k): returns count of elements strictly smaller than k 
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 2e1 + 10 ;
int SPF[N] ;
vector<bool > isPrime(N , 1) ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int gcd(int a, int b){if(b == 0){return a;} return gcd(b, a % b);}
int lcm(int a, int b){return (a / gcd(a, b) * b) ;}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
int power(int x, int y){int res = 1 ; while(y > 0) {if(y & 1) res = (res * x) ; x = (x * x) ; y = y >> 1 ;} return res ;}
int powermod(int x, int y){int res = 1; x = x % mod97; while(y > 0){if(y&1) res = (res * x) % mod97; y = y >> 1; x = (x * x) % mod97 ;}return res ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
void prime(){isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}}}
void spf(){for(int i = 0; i <= N; ++i) SPF[i] = i; for(int i = 2; i <= N; ++i) if(SPF[i] == i) for(int j = i; j <= N; j += i) if(SPF[j] == j) SPF[j] = i;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int isqrt(int n){long long x = sqrtl(n);while (x*x>n){--x;} while((x+1) * (x+1)<=n){++x;}return x;}
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
int errichtokabinary(int l,int r,vector<int>&a,int target){int ans=-1; while(l <= r){int mid=(l+(r-l)/2); if(a[mid]==target){ans=mid;return ans;}if(a[mid]<target)l=mid+1;else r=mid-1;}return ans;}
void ncrwithoutmod(int n, int r){long long p = 1, k = 1; if (n-r < r) r = n-r; if (r != 0) {while (r) {p *= n; k *= r; long long m = __gcd(p, k);p /= m; k /= m; n--; r--; }} else cout << p << endl; }
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

struct SGT {
    int S ; 
    int sz ; // 2^k where k is the least integer which satisfy 2^k >= n
    vector<int> segtree ;
    SGT(int n) {
        while(__builtin_popcount(n) != 1){
            n ++ ; // as long as n is not the perfect power of two.
        }
        sz = n ;
        segtree.resize(2 * sz) ;
        // 1 . . . 2 * n - 1
    }
    void build(int node , int start , int end , vector<int > &arr , int parity) { // require the input array // time complexity of O(N)
        if (start == end) {
            segtree[node] = arr[start] ;
            return ;
        }
        int mid = (start + end) / 2;
        build(2 * node , start , mid , arr , 1 - parity) ;
        build(2 * node + 1 , mid + 1 , end , arr , 1 - parity) ;
        if(!parity) {segtree[node] = (segtree[2 * node] | segtree[2 * node + 1]) ;} // may change
        else {segtree[node] = (segtree[2 * node] ^ segtree[2 * node + 1]) ;}
        // parity = 1 - parity ;
    }
    int query(int node , int start , int end , int l , int r) { // time complexity of O(log N) 
        if (r < start || end < l) return 0 ;
        if (start >= l && end <= r) return segtree[node] ;
        int mid = (start + end) / 2 ;
        return query(2 * node , start , mid , l , r) + query(2 * node + 1 , mid + 1 , end , l , r) ; // may change
    }
    void update(int node , int start , int end , int pos , int val , int parity , vector<int > &arr) { // time complexity of O(log N) 
        if (start == end) {
            segtree[node] = val ;
            arr[start] = val ;
            return ;
        }
        int mid = (start + end) / 2 ;
        if (pos <= mid) update(2 * node , start , mid , pos , val , 1 - parity , arr) ;
        else update(2 * node + 1 , mid + 1 , end , pos , val , 1 - parity , arr) ;
        if(!parity) {segtree[node] = (segtree[2 * node] | segtree[2 * node + 1]);} // may change
        else {segtree[node] = (segtree[2 * node] ^ segtree[2 * node + 1]) ;}
        // parity = 1 - parity ;
    }
    int output(int node) {
        return segtree[1] ;
    }
};

bool solve(){
    int n , m ;
    cin >> n >> m ;
    int parity = 0 ;
    if (n % 2 == 0) parity = 1 ; // we are changing the parity because in the case
    // of even n height will we even
    /*
            1         ->1
        2       3      ->0 // if zero that means perform OR operation.
    4       5,6     7
    
    */
    iv(v , power(2 , n))
    n = power(2 , n) ;
    SGT tree(n) ;
    tree.build(1 , 0 , n - 1 , v , parity) ;
    while(m--){
        int ind , value ;
        cin >> ind >> value ;
        tree.update(1 , 0 , n - 1 , ind - 1 , value , parity , v) ;
        cout << tree.output(1) << nl ;
    }
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
    int t = 1;
    //cin >> t;  
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
 
 
 
 
 