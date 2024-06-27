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
template<class T > using Tree_SET = tree< T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_SET<pair<int , int > > s; for pairs
template<class T > using Tree_MULTISET = tree< T , null_type , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_MULTISET<pair<int , int > > s; for pairs

#define nl                "\n"
#define ll                long long // typedef array<int , 2> p ; pair h ye
#define int               ll
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
#define yes               cout << "YES" << nl ;
#define no                cout << "NO" << nl ;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<nl ;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<nl ; } 
#define pb                push_back
#define bpp               __builtin_popcountll
#define inf               1000000000000000000 // 18 zero's
#define Pi                3.1415926535897932384626
#define EPS               1e-9

const int MOD = 1000000007 ; // 998244353 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int modpower(int x, int y){long long res = 1; x = x % MOD; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2) ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

struct DSU {
    int S ; 
    struct node {
        int p; int siz; int rnk; // by rank, it's based on the height of the trees, while by size, it's based on the number of elements in the sets. 
        // Merging the smaller tree into the larger one helps maintain a more balanced structure.
    };
    vector<node > dsu ; 
    vector<pair<int , node > > history ; // Store history for rollback 
    vector<vector<int > > adj ;
    DSU(int n) { 
        S = n ; 
        for(int i = 0 ; i < n ; ++i) {
            node tmp ; 
            tmp.p = i; tmp.siz = 1; tmp.rnk = 0; 
            dsu.push_back(tmp) ; 
        }
        adj.assign(n, vector<int>()) ;
    }

    void reset(int n) {
        dsu.clear() ; 
        S = n ; 
        for(int i = 0 ; i < n ; ++i) {
            node tmp ; 
            tmp.p = i; tmp.siz = 1; tmp.rnk = 0; 
            dsu.push_back(tmp) ; 
        }
    }

    int parent(int u) {
        if(dsu[u].p == u) return u;
        dsu[u].p = parent(dsu[u].p) ; // Time Complexity O(log n)
        return dsu[u].p ; 
    }

    void mergebysize(int u, int v) {
        u = parent(u); v = parent(v);
        adj[u].pb(v) ;
        adj[v].pb(u) ;
        if(u == v) return ;
        if(dsu[u].siz < dsu[v].siz) swap(u , v) ; 
        history.push_back({u, dsu[u]}) ;
        history.push_back({v, dsu[v]}) ;
        dsu[v].p = u ; 
        dsu[u].siz += dsu[v].siz ; 
    }

    void mergebyrank(int u, int v) {
        u = parent(u); v = parent(v);
        if(u == v) return ;
        history.push_back({u, dsu[u]}) ;
        history.push_back({v, dsu[v]}) ;
        if(dsu[u].rnk < dsu[v].rnk) dsu[u].p = v ;
        if(dsu[u].rnk > dsu[v].rnk) dsu[v].p = u ;
        if(dsu[u].rnk == dsu[v].rnk) dsu[v].p = u , dsu[u].rnk += 1 ; 
    }

    void rollback() { // Each union operation typically involves merging two sets (represented by their representatives) into one. Therefore, when rolling back a union operation, you need to undo the changes for both sets involved in that operation.
        if(history.empty()) return ; // Nothing to rollback
        auto &i = history.back() ; // Retrieve the information about the last union operation
        int u = i.F ;
        auto state_u = i.S ;
        history.pop_back() ;
        dsu[u] = state_u ;

        if(!history.empty()) {
            auto ii = history.back() ; // Retrieve the information about the second-to-last union operation
            int v = ii.F ;
            auto state_v = ii.S ;
            history.pop_back() ;
            dsu[v] = state_v ;
        }
    }

    bool same(int u, int v) {
        if(parent(u) == parent(v)) return true ; 
        return false ; 
    }

    int get_size(int u) {
        return dsu[parent(u)].siz ; 
    }
    vector<vector<int > > get_adj(){
        return adj ;
    }
};

bool solve(){
    int n , m ;
    cin >> n >> m ;
    vector<pair<int , pair<int , int > > > p ;
    vector<vector<int > > adj(n) ;
    for(int i = 0 ; i < m ; ++i){
        int u , v , w ;
        cin >> u >> v >> w ;
        u -= 1 ;
        v -= 1 ;
        p.pb({w , {u , v}}) ;
    }
    sort(all(p)) ;
    reverse(all(p)) ;
    int ans = inf ;
    DSU dsu(n) ;
    int start = 0 ;
    int end = 0 ;
    for(int i = 0 ; i < m ; ++i){
        // cout << p[i].S.F << " " << p[i].S.S << nl ;
        if(dsu.same(p[i].S.F , p[i].S.S)){
            if(ans > p[i].F){
                ans = p[i].F ;
                start = p[i].S.F ;
                end = p[i].S.S ;
            }
        }
        else{
            dsu.mergebysize(p[i].S.F , p[i].S.S) ;
            adj[p[i].S.F].pb(p[i].S.S) ;
            adj[p[i].S.S].pb(p[i].S.F) ;
        }
        // cout << ans << " " << start << " " << end << nl ;
    }
    cout << ans << " " ;
    // adj = dsu.get_adj() ;
    for(auto &vec : adj){
        // cout << vec[0] << " " << vec[1] << nl ;
    }
    vector<int > par(n , -1) ;
    vector<int > vis(n , 0) ;
    function<void(int,int)> dfs=[&](int child,int parent)->void{
        par[child] = parent ;
        vis[child] = 1 ;
        for(auto &i : adj[child]){
            // par[i] = child ;
            if(i == parent || vis[i]) continue ;
            dfs(i , child) ;
        }
    };
    // cout << start << " " << end << nl ;
    dfs(start , -1) ;
    // check1(par)
    vector<int > v ;
    int l = end ;
    while(l != -1){
        v.pb(l + 1) ;
        l = par[l] ;
        // cout << l << " " ;
    }
    // v.pop_back() ;
    // v.pop_back() ;

    // cout << nl ;
    cout << v.size() << nl ;
    check1(v)
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


