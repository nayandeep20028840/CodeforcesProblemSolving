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
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
int power(int x, int y){int res = 1 ; while(y > 0) {if(y & 1) res = (res * x) ; x = (x * x) ; y = y >> 1 ;} return res ;}
int modpower(int x, int y){int res = 1; x = x % mod97; while(y > 0){if(y&1) res = (res * x) % mod97; y = y >> 1; x = (x * x) % mod97 ;}return res ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
void prime(){isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}}}
void spf(){for(int i = 0; i <= N; ++i) SPF[i] = i; for(int i = 2; i <= N; ++i) if(SPF[i] == i) for(int j = i; j <= N; j += i) if(SPF[j] == j) SPF[j] = i;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
void ncrwithoutmod(int n, int r){long long p = 1, k = 1; if (n-r < r) r = n-r; if (r != 0) {while (r) {p *= n; k *= r; long long m = __gcd(p, k);p /= m; k /= m; n--; r--; }} else cout << p << endl; }
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

bool solve(){
    // Concept Used Toposort.
    /*
    
            2 ---> 1 ---> 3
            2 ---> 4 ---> 3
            
            // firstly remove the node with 0 indegree
            // if there are no 0 indegree node then no toposort.
            // No, a topological sort is typically applied to directed acyclic graphs (DAGs) rather than undirected graphs

            // for detecting a cycle in a directed graph there are many methods 
            1. You can keep a counter and count the number of visited node if its equal to n then no cycle
            2. There is a methods known as make use of color vector(tough method).
            3. Stack Method youtube apna college.
    
    */
    int n ;
    cin >> n ;
    vector<int > adj[n + 1] ;
    vector<int > indegree(n + 1 , 0) ;
    for(int i = 0 ; i < n ; ++i){
        int k ;
        cin >> k ;
        for(int j = 0 ; j < k ; ++j){
            int t ;
            cin >> t ;
            adj[t].pb(i + 1) ;
            indegree[i + 1] += 1 ;
        }
    }
    vector<int > color(n + 1 , 0) ;
    int f = 0 ;
    // for(int i = 1 ; i <= n ; ++i){
    //     for(auto &j : adj[i]){
    //         cout << j << " " ;
    //     }
    //     cout << nl ;
    // }
    // function<bool(int) > dfs = [&](int child) -> bool {
    //     color[child] = 1 ;
    //     for(auto &i : adj[child]){
    //         if(color[i] == 0){
    //             if(dfs(i)){
    //                 return true ;
    //             }
    //         }
    //         else if(color[i] == 1){
    //             return true ;
    //         }
    //     }
    //     color[child] = 3 ;
    //     return false ;
    // };
    // function<bool() > cycle = [&]() -> bool {
    //     for(int i = 1 ; i <= n ; ++i){
    //         // cout << i << " " ;
    //         if(color[i] == 0 && dfs(i)){
    //             return 1 ;
    //         }
    //     }
    //     return 0 ;
    // };
    // if(cycle()){
    //     cout << -1 << nl ;
    //     return true ;
    // }
    vector<int > dp(n + 1 , 1) , vis(n + 1 , 0) ;
    queue<int > q ;
    int check = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(indegree[i] == 0){
            q.push(i) ;
            check = 1 ;
            dp[i] = 1 ;
        }
    }
    // cout << check << " " ;
    if(check == 0) {
        cout << -1 << nl ;
        return true ;
    }
    int del = 0 ;
    while(!q.empty()){
        int node = q.front() ;
        del += 1 ;
        q.pop() ;
        vis[node] = 1 ;
        for(auto &i : adj[node]){
            indegree[i] -= 1 ;
            if(indegree[i] == 0){
                vis[i] = 1 ;
                q.push(i) ;
            }
            // if(i > node) dp[i] = dp[node] ;
            // if(i < node) dp[i] = dp[node] + 1 ;
            dp[i] = max(dp[i] , dp[node] + (node > i)) ;
        }
    }
    // int ans = 1 ;
    // for(int i = 1 ; i <= n ; ++i){
    //     ans = max(ans , dp[i]) ;
    // }
    // cout << ans << nl ;

    if(del == n) cout << *max_element(all(dp)) << nl ;
    else cout << -1 << nl ;
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
 
 
 
 