#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
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

const int MOD = 1000000007 ; // 998244353 // 10000000069LL // 3006703054056749LL 
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2}; 
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1}; 

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return ((long long)a / (long long)GCD(a, b) * (long long)b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}

// O(1) for idempotent O(logN) for general

struct SparseTable {
    struct Node {
        int val ; // store more info if required // may change
        Node() { // Identity Element
            val = 0 ; // may change
        }
        Node(int v) {
            val = v ;
        }
        void merge(Node &l , Node &r) { // problem
            val = GCD(l.val , r.val) ;
        }
    };

    vector<vector<Node > > table ;
    vector<int > logValues ;
    int n ;
    int maxLog ;
    vector<int > a ;
    SparseTable(int n , vector<int > &arr) {
        this->n = n ;
        a = arr ;
        // table.clear();
        // logValues.clear();
        table.resize(n + 1) ;
        maxLog = 60 ;
        logValues.resize(max(maxLog, n + 1)) ;
        logValues[1] = 0 ;
        // 0 1 1 2 2 2 2 3 3 3  3  3  3  3  3  4  . . . . // log values 
        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 . . . . 
        for(int i = 2 ; i <= n ; ++i) {
            logValues[i] = logValues[i / 2] + 1 ;
        }
        for(int i = 0 ; i < n ; ++i) {
            table[i].resize(maxLog + 1) ;
            fill(all(table[i]) , Node()) ;
        }
        build() ;
    }
    void build() {
        for(int i = 0; i < n; i++) {
            table[i][0] = Node(a[i]) ;
        }
        for(int i = 1 ; i <= maxLog ; ++i) {
            for(int j = 0 ; (j + (1ll << i)) <= n ; ++j) {
                table[j][i].merge(table[j][i - 1] , table[j + (1ll << (i - 1))][i - 1]) ;
            }
        }
    }
    Node queryNormal(int left , int right) { // O(log(n))
        Node ans = Node() ;
        for(int j = logValues[right - left + 1] ; j >= 0 ; --j) {
            if((1 << j) <= right - left + 1) {
                ans.merge(ans, table[left][j]) ;
                left += (1ll << j) ; // will not be (j - 1)
            }
        }
        return ans ; 
    }
    Node queryIdempotent(int left, int right) { // O(1)
        int j = logValues[right - left + 1] ;
        Node ans = Node() ;
        ans.merge(table[left][j] , table[right - (1ll << j) + 1][j]) ;
        return ans ;
    }
};


bool solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>d(n-1);
    for(int i=0;i<n-1;++i){
        d[i]=abs(a[i]-a[i+1]);
    }
    // check1(d)
    SparseTable st(n-1 , d);
    int low = 0;
    int high = n ;
    while(high - low > 1){
        int mid = (high + low) / 2 ;
        int j = 0 ;
        int f = 0 ;
        for(int i = mid - 1 ; i < n - 1 ; ++i){
            int gcd = st.queryIdempotent(j , i).val;
            if(gcd > 1){
                f = 1 ;
                break ;
            }
            j += 1 ;
        }
        if(f){
            low = mid ;
        }
        else{
            high = mid ;
        }
    }
    cout << low + 1 << nl ;
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

