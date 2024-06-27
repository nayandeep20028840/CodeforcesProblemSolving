#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Policy based data structures(PBDS) C++ STL
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// order_of_key(k): returns count of elements strictly smaller than k 
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // for pairs only define simply by ordered_set s
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
template<class T >using Tree_SET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_SET<pair<int , int > > s; for pairs
template<class T >using Tree_MULTISET = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_MULTISET<pair<int , int > > s; for pairs

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define nl                "\n"
#define ll                long long // typedef array<int , 2> p ; pair h ye
#define int               ll
#define ld                long double
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
#define yes               cout << "YES" << nl ;
#define no                cout << "NO" << nl ;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<nl ;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<nl ; } 
#define check3(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S<<nl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<nl; }
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define bpp               __builtin_popcountll
#define inf               1000000000000000000 // 18 zero's
#define Pi                3.1415926535897932384626
#define EPS               1e-9

const int MOD = 1000000007 ; // 998244353 
const int LOG = 21 ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modpower(int x, int y){long long res = 1; x = x % MOD; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int modinv(int x){return modpower(x , MOD - 2) ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){
    if(a.F == b.F){
        return a.S < b.S ;
    }
    return a.F > b.F ;
}
vector<int > giveme_it_isprime_or_not(int n){vector<int > isPrime(n+1, 1);isPrime[0]=isPrime[1]=false;for(int i = 2; i * i <= n; ++i){if(isPrime[i] == true){for(int j = 2 * i; j <= n; j += i){isPrime[j] = false;}}} return isPrime;} // Time Complexity - O(n * sqrt(n) * log(n)) 
vector<int> givemeprimes(int n) {int*arr = new int[n + 1](); vector<int> vect; for(int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for(int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;} // can be calculated in O(n) 
vector<vector<int>> givemedivisors(int n){int*arr = new int[n + 1]();vector<vector<int > > vect(n + 1);for(int i = 2; i <= n; ++i){if(arr[i] == 0){for(int j = i; j <= n; j += i){vect[j].pb(i);arr[i] = 1;}}} return vect ;}
vector<int > givemesmallestprimefactors(int n){vector<int > SPF(n + 1);for(int i = 0; i <= n; ++i){SPF[i] = i;}for(int i = 2; i <= n; ++i){if(SPF[i] == i){for(int j = i; j <= n; j += i){if(SPF[j] == j){SPF[j] = i;}}}}return SPF ;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

struct SegmentTree {
    struct Node {
        int val ; // may change
        Node() { // Identity element
            val = 0 ;    // may change // warning it is for query answers only what should be the output answer 
            // val = power(2 , 30) - 1 ;    // may change
            // val = INF ;    // may change
            // val = -INF ;    // may change
        }
        Node(int p1) {  // Actual Node
            val = p1 ; // may change
        }
        void merge(Node &l , Node &r) { // Merge two child nodes
            val = max(l.val , r.val) ;  // may change
        }
    };
    struct Update { // note if mentioned about update then only it is used 
        int val ; // may change
        Update(int p1) { // Actual Update
            val = p1 ; // may change
        }
        void apply(Node &a) { // apply update to given node
            a.val = val ; // may change
        }
    };

    vector<Node > tree ; // it will change according to the node 
    vector<int > arr ; // type may change 
    int n , s ;
    int sz ; // 2^k where k is the least integer which satisfy 2^k >= n
    SegmentTree(int array_len, vector<int> &a) { // change if type updated
        arr = a ;
        n = array_len ; 
        s = 1 ;
        while(s < 2 * n) {
            s = (s << 1);
        }
        tree.resize(s); 
        fill(all(tree), Node()) ;
        build(0 , n - 1 , 1) ;
    }
    void build(int start, int end, int index)  // Never change this
    {
        if(start == end){
            tree[index] = Node(arr[start]) ; // may change 
            return ;
        }
        int mid = (start + end) / 2 ;
        build(start, mid, 2 * index) ;
        build(mid + 1, end, 2 * index + 1) ;
        tree[index].merge(tree[2 * index] , tree[2 * index + 1]) ;
    }
    void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
    {
        if(start == end){
            u.apply(tree[index]) ;
            return ;
        }
        int mid = (start + end) / 2 ;
        if(mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1 , end , 2 * index + 1 , query_index, u) ;
        tree[index].merge(tree[2 * index], tree[2 * index + 1]) ;
    }
    Node query(int start, int end, int index, int left, int right) { // may change 
        if(start > right || end < left) // may change // both if statements can be removed
            return Node() ;
        if(start >= left && end <= right) // may change // both if statements can be removed
            return tree[index] ; 
        int mid = (start + end) / 2 ; 
        Node l , r , ans ; 
        l = query(start , mid , 2 * index , left, right) ; 
        r = query(mid + 1 , end , 2 * index + 1 , left , right) ; 
        ans.merge(l , r) ; 
        return ans ; 
    }
    void make_update(int index, int val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0 , n - 1 , 1 , index , new_update) ;
    }
    Node make_query(int left , int right) { // may change
        return query(0 , n - 1 , 1 , left , right) ; // may change
    }
    int first(){
        return tree[1].val ;
    }
    void output(){
        for(int i = 1 ; i < s ; ++i){
            cout << tree[i].val <<  " " ;
        }
        cout << "\n" ;
    }
};


/*

How to define our segment tree in the main function
vector<int > arr = {1 , 2 , 3 , 4} ;

SegmentTree st(n, arr);

*/

bool solve(){
    int n , m , d ;
    cin >> n >> m >> d ;
    iv(v , n)
    int ans = 0 ;
    int sum = 0 ;
    priority_queue<int , vector<int > , greater<int > > pq ;
    for (int i = 0 ; i < n ; i++) {
        if (v[i] > 0) {
            pq.push(v[i]) ;
            sum += v[i] ;
        }
        if (pq.size() > m) {
            sum -= pq.top() ;
            pq.pop() ;
        }
        ans = max(ans , sum - (i + 1) * d) ;
    }
    cout << ans << nl ;
    // vector<pair<int , int > > p ;
    // for(int i = 0 ; i < n ; ++i){
    //     p.pb({v[i] , i}) ;
    // }
    // sort(all(p)) ;
    // reverse(all(p)) ;
    // // check2(p)
    // vector<int > ind ;
    // for(int i = 0 ; i < n ; ++i){
    //     ind.pb(p[i].S) ;
    // }
    // // check1(ind)
    // SegmentTree st(n , ind);
    // int cnt = 0 ;
    // int ans = 0 ;
    // int j = 0 ;
    // int sum = 0 ;
    // // bit.output() ;
    // for(int i = 0 ; i < n ; ++i){
    //     if(cnt == m){
    //         sum -= p[j].F ;
    //         j += 1 ;
    //         cnt -= 1 ;
    //     }
    //     cnt += 1 ;
    //     sum += p[i].F ;
    //     int sub = (st.make_query(j , i).val + 1) ;
    //     // cout << sum << " " << sub << nl ; 
    //     ans = max(ans , sum - sub * d) ;
    // }
    // cout << ans << nl ;
    return true ;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif 
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    freopen("error.txt", "w", stderr);
//#endif 
    int t ;
    cin >> t ;  
    //int count = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            //count++ ;
        }else{
            // no 
        }
    }
    return 0 ;
}



 // Talk is Cheap. Show me the code 