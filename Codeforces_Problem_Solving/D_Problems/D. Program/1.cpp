#include<bits/stdc++.h>
using namespace std;

// Policy based data structures(PBDS) C++ STL
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// order_of_key(k): returns count of elements strictly smaller than k 
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // for pairs only define simply by ordered_set s
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
template<class T>using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree<pair<int,int>> s; for pairs

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

#define ll                long long // typedef array<int, 2> ii; pair h ye
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
const int N = 2e1 + 1 ;
const int LOG = 21 ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
int power(int x, int y){int res = 1 ; while(y > 0) {if(y & 1) res = (res * x) ; x = (x * x) ; y = y >> 1 ;} return res ;}
int modpower(int x, int y){int res = 1; x = x % mod97; while(y > 0){if(y&1) res = (res * x) % mod97; y = y >> 1; x = (x * x) % mod97 ;}return res ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
vector<int > giveme_it_isprime_or_not(int n){vector<int > isPrime(n+1, 1);isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}} return isPrime;}
vector<int> givemeprimes(int n) {int*arr = new int[n + 1](); vector<int> vect; for(int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for(int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<vector<int>> givemedivisors(int n){int*arr = new int[n + 1]();vector<vector<int > > vect(n + 1);for(int i = 2; i <= n; ++i){if(arr[i] == 0){for(int j = i; j <= n; j += i){vect[j].pb(i);arr[i] = 1;}}} return vect ;}
vector<int > givemesmallestprimefactors(int n){vector<int > SPF(n + 1);for(int i = 0; i <= N; ++i){SPF[i] = i;}for(int i = 2; i <= N; ++i){if(SPF[i] == i){for(int j = i; j <= N; j += i){if(SPF[j] == j){SPF[j] = i;}}}}return SPF ;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
void ncrwithoutmod(int n, int r){long long p = 1, k = 1; if (n-r < r) r = n-r; if (r != 0) {while (r) {p *= n; k *= r; long long m = __gcd(p, k);p /= m; k /= m; n--; r--; }} else cout << p << endl; }
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

// Lazy Segment Tree with Range Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
struct LazySGT {
    vector<Node > tree ;
    vector<bool > lazy ;
    vector<Update > updates ;
    vector<int > arr ; // type may change
    int n ;
    int sz ; // 2^k where k is the least integer which satisfy 2^k >= n
    LazySGT(int a_len , vector<int > &a) { // change if type updated
        arr = a ;
        n = a_len ;
        sz = 1 ;
        while(__builtin_popcount(n) != 1){
            n ++ ; // as long as n is not the perfect power of two.
        }
        sz = n ;
        tree.resize(sz) ; fill(all(tree) , Node()) ;
        lazy.resize(sz) ; fill(all(lazy) , false) ;
        updates.resize(sz) ; fill(all(updates) , Update()) ;
        build(0 , n - 1 , 1) ;
    }
    void build(int start , int end , int index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]) ;
            return ;
        }
        int mid = (start + end) / 2 ;
        build(start , mid, 2 * index) ;
        build(mid + 1 , end , 2 * index + 1) ;
        tree[index].merge(tree[2 * index] , tree[2 * index + 1]) ;
    }
    void pushdown(int index , int start , int end){
        if(lazy[index]){
            int mid = (start + end) / 2 ; 
            apply(2 * index , start , mid , updates[index]) ;
            apply(2 * index + 1 , mid + 1 , end , updates[index]) ;
            updates[index] = Update() ;
            lazy[index] = 0 ;
        }
    }
    void apply(int index , int start , int end , Update& u){
        if(start != end){
            lazy[index] = 1 ;
            updates[index].combine(u , start , end) ;
        }
        u.apply(tree[index] , start , end) ;
    }
    void update(int start, int end, int index, int left, int right, Update &u) {  // Never Change this
        if(start > right || end < left)
            return ;
        if(start >= left && end <= right){
            apply(index , start , end , u) ;
            return ;
        }
        pushdown(index , start , end) ;
        int mid = (start + end) / 2 ;
        update(start , mid , 2 * index , left , right , u) ;
        update(mid + 1 , end , 2 * index + 1 , left , right , u) ;
        tree[index].merge(tree[2 * index] , tree[2 * index + 1]) ;
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end) ;
        int mid = (start + end) / 2 ;
        Node l , r , ans ;
        l = query(start , mid , 2 * index , left , right) ;
        r = query(mid + 1 , end , 2 * index + 1 , left , right) ;
        ans.merge(l , r) ;
        return ans ;
    }
    void make_update(int left, int right, int val) {  // pass in as many parameters as required
        Update new_update = Update(val) ; // may change
        update(0 , n - 1 , 1 , left , right , new_update) ;
    }
    Node make_query(int left, int right) {
        return query(0 , n - 1 , 1 , left , right) ;
    }
};

struct Node1 {
    // int val ; // may change
    int mx = -INF ;
    int mn = INF ;
    Node1() { // Identity element
        // val = 0 ;    // may change
        mx = -INF ;
        mn = INF ;
    }
    Node1(int p1) {  // Actual Node
        // val = p1 ; // may change
        mx = p1 ;
        mn = p1 ;
    }
    void merge(Node1 &l , Node1 &r) { // Merge two child nodes
        // val = l.val + r.val ;  // may change
        mx = max(l.mx , r.mx) ;
        mn = min(l.mn , r.mn) ;
    }
};

struct Update1 {
    // int val ; // may change
    Update1(){ // Identity update
        // val = 0 ;
    }
    Update1(int val1) { // Actual Update
        // val = val1 ;
    }
    void apply(Node1 &a, int start, int end) { // apply update to given node
        // a.val = val * (end - start + 1) ; // may change
    }
    void combine(Update1& new_update , int start , int end){
        // val = new_update.val ;
    }
};


/*

How to define our segment tree in the main function
vector<int > arr = {1 , 2 , 3 , 4} ;

SegTree<Node1 , Update1> LAZY_SEGMENT_TREE = SegTree<Node1 , Update1 > (4 , arr) ;

*/

bool solve(){
    int n , m ;
    cin >> n >> m ;
    string s ;
    cin >> s ;
    vector<int > v(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; ++i){
        v[i] = v[i - 1] + (s[i - 1] == '+' ? 1 : -1) ;
    }
    // check1(v)
    LazySGT<Node1 , Update1> SEGMENT_TREE = LazySGT<Node1 , Update1 > (n + 1 , v) ;
    for(int i = 0 ; i < m ; ++i){
        int l , r ;
        cin >> l >> r ;
        int mx = 0 ;
        int mn = 0 ;
        if(l > 1){
            mx = max(mx , SEGMENT_TREE.make_query(1 , l - 1).mx) ;
            mn = min(mn , SEGMENT_TREE.make_query(1 , l - 1).mn) ;
        }
        if(r < n){
            int mid = v[r] - v[l - 1] ;
            mx = max(mx , SEGMENT_TREE.make_query(r + 1 , n).mx - mid) ;
            mn = min(mn , SEGMENT_TREE.make_query(r + 1 , n).mn - mid) ;
        }
        cout << mx - mn + 1 << nl ;
    }
    return true ;
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
            // no 
        }
    }
    return 0;
}



 // Don't overthink and try to prove your idea. 