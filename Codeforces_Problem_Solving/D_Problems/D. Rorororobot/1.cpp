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
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
const int LOG = 21 ;
int SPF[N] ;
vector<bool > isPrime(N , 1) ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);}
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
int power(int x, int y){int res = 1 ; while(y > 0) {if(y & 1) res = (res * x) ; x = (x * x) ; y = y >> 1 ;} return res ;}
int modpower(int x, int y){int res = 1; x = x % mod97; while(y > 0){if(y&1) res = (res * x) % mod97; y = y >> 1; x = (x * x) % mod97 ;}return res ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
void prime(){isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}}}
void spf(){for(int i = 0; i <= N; ++i) SPF[i] = i; for(int i = 2; i <= N; ++i) if(SPF[i] == i) for(int j = i; j <= N; j += i) if(SPF[j] == j) SPF[j] = i;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
void ncrwithoutmod(int n, int r){long long p = 1, k = 1; if (n-r < r) r = n-r; if (r != 0) {while (r) {p *= n; k *= r; long long m = __gcd(p, k);p /= m; k /= m; n--; r--; }} else cout << p << endl; }
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

// O(1) for idempotent O(logN) for general
// Supports multiple sparse tables with minor change in Node

template<typename Node>
struct SparseTable {
    vector<vector<Node > > table ;
    vector<int > logValues ;
    int n ;
    int maxLog ;
    vector<int > a ;
    SparseTable(int n1 , vector<int > &arr) {
        n = n1 ;
        a = arr ;
        table.resize(n) ;
        logValues.resize(n + 1) ;
        maxLog = log2(n) ;
        logValues[1] = 0 ;
        for (int i = 2 ; i <= n ; ++i) {
            logValues[i] = logValues[i / 2] + 1 ;
        }
        for (int i = 0 ; i < n ; ++i) {
            table[i].resize(maxLog + 1) ;
            fill(all(table[i]) , Node()) ;
        }
        build() ;
    }
    void build() {
        for (int i = 0; i < n; i++) {
            table[i][0] = Node(a[i]) ;
        }
        for (int i = 1 ; i <= maxLog ; ++i) {
            for (int j = 0 ; (j + (1 << i)) <= n ; ++j) {
                table[j][i].merge(table[j][i - 1] , table[j + (1 << (i - 1))][i - 1]) ;
            }
        }
    }
    Node queryNormal(int left , int right) {
        Node ans = Node() ;
        for (int j = logValues[right - left + 1] ; j > 0 ; --j) {
            if ((1 << j) <= right - left + 1) {
                ans.merge(ans, table[left][j]) ;
                left += (1 << j) ;
            }
        }
        return ans ;
    }
    Node queryIdempotent(int left, int right) {
        int j = logValues[right - left + 1] ;
        Node ans = Node() ;
        ans.merge(table[left][j] , table[right - (1 << j) + 1][j]) ;
        return ans ;
    }
};
struct Node1 {
    int val = -INF ; // store more info if required
    Node1() { // Identity Element
        val = -INF ;
    }
    Node1(int v) {
        val = v ;
    }
    void merge(Node1 &l , Node1 &r) {
        val = max(l.val , r.val) ;
    }
};

bool solve(){
    int n , m ;
    cin >> n >> m ;
    iv(v , m)
    SparseTable<Node1 > SPARSE_TABLE = SparseTable<Node1 > (m , v) ;
    int q ;
    cin >> q ;
    while(q--){
        int x1 , y1 , x2 , y2 , k ;
        cin >> x1 >> y1 >> x2 >> y2 >> k ;
        if(x1 == x2 && y1 == y2) yes
        else if((abs(x1 - x2) % k) != 0 || (abs(y1 - y2) % k) != 0) no
        else{
            int height = x1 + (abs(x1 - n) / k) * k ;
            if(y1 > y2) swap(y1 , y2) ;
            // cout << y1 << " " << y2 << nl ;
            int ans = SPARSE_TABLE.queryIdempotent(y1 - 1 , y2 - 1).val ;
            // cout << x1 << " " << height << " " << ans << nl ;
            if(height > ans) {yes}
            else {no}
        }
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