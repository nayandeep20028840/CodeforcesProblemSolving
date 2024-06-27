#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // for pairs only define simply by ordered_set s
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
template<class T>using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree<pair<int , int > > s; for pairs

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
#define INF               1000000000000000000 // 18 zero's
#define Pi                3.1415926535897932384626
#define EPS               1e-9
#define nl                "\n"

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
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
vector<int > giveme_it_isprime_or_not(int n){vector<int > isPrime(n+1, 1);isPrime[0]=isPrime[1]=false;for(int i = 2; i * i <= n; ++i){if(isPrime[i] == true){for(int j = 2 * i; j <= n; j += i){isPrime[j] = false;}}} return isPrime;} // Time Complexity - O(n * sqrt(n) * log(n)) 
vector<int> givemeprimes(int n) {int*arr = new int[n + 1](); vector<int> vect; for(int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for(int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;} // can be calculated in O(n) 
vector<vector<int>> givemedivisors(int n){int*arr = new int[n + 1]();vector<vector<int > > vect(n + 1);for(int i = 2; i <= n; ++i){if(arr[i] == 0){for(int j = i; j <= n; j += i){vect[j].pb(i);arr[i] = 1;}}} return vect ;}
vector<int > givemesmallestprimefactors(int n){vector<int > SPF(n + 1);for(int i = 0; i <= n; ++i){SPF[i] = i;}for(int i = 2; i <= n; ++i){if(SPF[i] == i){for(int j = i; j <= n; j += i){if(SPF[j] == j){SPF[j] = i;}}}}return SPF ;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

/*

Sparse Table: Binary lifting can be seen as a type of sparse table data structure 
that is customized for trees. It precomputes and stores information about the 
ancestors of each node, allowing for quick LCA queries.
Binary lifting is primarily used for finding the lowest common ancestor (LCA) of two nodes in a tree
this technique itself is applicable to both rooted and unrooted trees not for graphs.
Preprocessing: In binary lifting, you typically preprocess the tree to create 
a data structure that helps answer LCA queries efficiently. This data structure 
often involves storing the ancestors of each node at various power-of-2 levels in the tree.
Time = O(logn) for each query

*/
struct BinaryLifting {
    int n ;
    int maxLog ;
    int maxRequirement ;
    vector<vector<int > > parent ;
    vector<int > logValues ;
    bool precomputedLogs = false ;
    // vector<int> *edges ----> meaning ----> // Declaring a pointer to a vector of integers
    BinaryLifting(int n1 , vector<vector<int > > &edges , int requirement , int root) { // requirement is 1e9 
        n = n1 ;
        parent.resize(n) ;
        maxLog = log2(requirement + 1) ;
        maxRequirement = requirement ;
        for (int i = 0 ; i < n ; ++i) {
            parent[i].resize(maxLog + 1) ;
            for (int j = 0; j <= maxLog; ++j) {
                parent[i][j] = -1 ;
            }
        }
        fillParentTable(root , edges) ;
        if (maxRequirement <= 1000000LL){ // 1e6
            precomputeLogs() ;
        }
    }
    void fillParentTable(int root , vector<vector<int > > &edges) {
        vector<bool > visited(n) ;
        dfsBinaryLifting(root, edges, visited) ;
        int intermediate = -1 ;
        for (int i = 1; i <= maxLog; ++i) {
            for (int j = 0; j < n; ++j) {
                intermediate = parent[j][i - 1] ;
                if (intermediate != -1) {
                    parent[j][i] = parent[intermediate][i - 1] ;
                }
            }
        }
    }
    void dfsBinaryLifting(int root , vector<vector<int > > &edges , vector<bool > &visited) {
        visited[root] = true ;
        for (auto &i : edges[root]) {
            if (!visited[i]) {
                parent[i][0] = root ;
                dfsBinaryLifting(i , edges , visited) ;
            }
        }
    }
    void precomputeLogs() {
        precomputedLogs = true ;
        logValues.resize(maxRequirement + 1) ;
        logValues[1] = 0 ;
        for (int i = 2 ; i <= maxRequirement ; ++i) {
            logValues[i] = logValues[i / 2] + 1 ;
        }
    }
    pair<int , int > kthParent(int start, int k) { // k can be upto 1e9, In this we have only one node and we have to calculate its parent by traversing in powers of 2 
        int a = start ;
        int distance = 0 ;
        while (k > 0) {
            int x = getLog(k) ;
            a = parent[a][x] ;
            if (a == -1){
                return {a , distance} ;
            }
            distance += (1 << x) ;
            k -= (1 << x) ;
        }
        return {a , distance} ; 
    }
    inline int getLog(int x) {
        return precomputedLogs ? logValues[x] : log2(x) ;
    }
};

struct LCA { // Lowest Common Ancestor 
    int n ; // number of nodes
    vector<int > level ; // level of each node
    LCA(int n1 , vector<vector<int > > &edges , int root) { // edges is the adjacency list of the tree
        n = n1 ; // number of nodes
        level.resize(n) ; // level of each node
        dfsLCA(root, edges, -1) ; // -1 is the parent of root
    }
    void dfsLCA(int root , vector<vector<int > > &edges , int parent) { 
        for (auto &i : edges[root]) { // 
            if (i != parent) {
                level[i] = level[root] + 1 ;
                dfsLCA(i, edges, root) ;
            }
        }
    }
    pair<int , int > getLCA(int a , int b , BinaryLifting &bl_object) { // bl_object is the object of BinaryLifting class
        if (level[a] > level[b]) {
            swap(a , b) ;
        }
        auto pr = bl_object.kthParent(b , level[b] - level[a]) ;
        int distance = pr.S ;
        b = pr.F ; // kth parent of b at level (level[b] - level[a])
        // cout << b << " " << distance << nl ;
        if (a == b) {
            return {a , distance} ; 
        }
        for (int i = bl_object.maxLog ; i >= 0 ; --i) {
            int parent1 = bl_object.parent[a][i] ; 
            int parent2 = bl_object.parent[b][i] ; 
            if (parent2 != parent1 && parent1 != -1 && parent2 != -1) {
                distance += (2 * (1 << i)) ;
                a = parent1 ; 
                b = parent2 ; 
            }
        }
        return {bl_object.parent[a][0] , distance + 2} ; 
    }
};

bool solve(){
    int n ;
    cin >> n ;
    vector<vector<int > > adj(n) ;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u , v ;
        cin >> u >> v ;
        u -= 1 ;
        v -= 1 ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    BinaryLifting bt(n , adj , 1e18 , 0) ;
    LCA lca(n , adj , 0) ;
    int q ;
    cin >> q ;
    while(q--){
        int x , y , a , b , k ;
        cin >> x >> y >> a >> b >> k ;
        x -= 1 , y -= 1 , a -= 1 , b -= 1 ;
        int real = lca.getLCA(a , b , bt).S ;
        int first = lca.getLCA(a , x , bt).S ;
        int second = lca.getLCA(b , y , bt).S ;
        int one = 1 ;
        int sum = one + first + second ;
        int sum2 = lca.getLCA(a , y , bt).S + lca.getLCA(x , b , bt).S + 1 ;
        // cout << real << " " << first << " " << second << nl ;
        if(real <= k and real % 2 == k % 2){
            yes
        }
        else if(sum <= k and sum % 2 == k % 2){
            yes
        }
        else if(sum2 <= k and sum2 % 2 == k % 2){
            yes
        }
        else{
            no
        }
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
    int t = 1 ;
    //cin >> t ;  
    //int count = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            //count++;
        }else{
            // no 
        }
    }
    return 0 ;
}




 // Talk is Cheap. Show me the code 
