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

const int N = 2e6 + 1 ;
int F[N], iF[N]; // Don't forget to change the value of N. factorial,Inverse Factorial Array
// if you want to use without any mod than mod will be INF 

int fast(int a, int b) {
    int res = 1 ;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD ;
        a = a * a % MOD ;
        b >>= 1 ;
    }
    return res ;
}

void init() {

    F[0] = 1 ;

    for(int i = 1 ; i < N ; ++i) 
        F[i] = (F[i - 1] * i) % MOD ;

    iF[N - 1] = fast(F[N - 1] , MOD - 2) ; // it finds the inverse of F[N - 1] 

    for (int i = N - 2 ; i >= 0 ; --i)
        iF[i] = iF[i + 1] * (i + 1) % MOD ;
}

int NCR(int n, int r) {
    if (r > n || r < 0)
        return 0 ;

    return iF[r] * F[n] % MOD * iF[n - r] % MOD ;
}

bool solve(){
    int n , k ;
    cin >> n >> k ;
    int same_done = 0 ;
    int diff_done = 0 ;
    vector<pair<int,int>>p;
    for(int i = 0 ; i < k ; ++i){
        int x , y ;
        cin >> x >> y ;
        if(x == y) same_done += 1 ;
        else diff_done += 1 ;
        p.pb({x , y}) ;
    }
    int ans = 1 ;
    if(n % 2 == 0){
        int rem = n ;
        rem -= same_done ;
        rem -= (2 * diff_done) ;
        int j = 1 ;
        // cout << rem << " " ;
        if(same_done % 2) {
            int t = 0;
            t = mod_MULTIPLICATION(NCR(rem,1),modpower(2,rem/2,MOD),MOD);
            ans = mod_ADDITION(ans,mod_MULTIPLICATION(j,t,MOD),MOD);
            rem -= 1 ;
        }
        // cout << ans << " " ;
        for(int i = 2 ; i <= rem ; i += 2){
            j *= (i - 1);
            int t = 0;
            t = mod_MULTIPLICATION(NCR(rem,i),modpower(2,i/2,MOD),MOD);
            ans = mod_ADDITION(ans,mod_MULTIPLICATION(j,t,MOD),MOD);
            // cout << ans << " " ;
        }
    }
    else{
        int rem = n ;
        rem -= same_done ;
        rem -= (2 * diff_done) ;
        int have = rem ;
        rem /= 2 ;
        for(int i = have ; i > 0 ; --i){
            ans = mod_ADDITION(ans , modpower(2 , (i / 2) , MOD) , MOD) ;
        }
    }
    cout << ans << nl ;
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
    init();
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


