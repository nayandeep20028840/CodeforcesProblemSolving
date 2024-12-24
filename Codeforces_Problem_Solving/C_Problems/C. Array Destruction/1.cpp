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

const int MOD = 1000000007 ; // 998244353 

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int modpower(int x, int y){long long res = 1; x = x % MOD; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}

/*

1 2 3 4 5 6 7 14 3 11

1 2 3 3 4 ---- 5 6  7  11  14
need             1  4  3

lets start by choosing 
15
1 14
14
3 11 
11
4 7
7
6 1

what went wrong here
should we choose

different condition thinking of dp solution constraints told me to think its 1e3

*/

const int N = 2e3+5 ;
int n ;
vector<int> v(N) ;
int dp[N][N] ;
vector<int>vec(N);
vector<int>vis(N);

bool rec(int i , int j){
    if(i >= n / 2) return 1 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int ans = 0;
    for(int k = 0 ; k < n ; ++k){
        if(k == i) continue;
        if(vis[i]) continue;
        if(rec(i + 1 , j)){

        }
    }
    return dp[i][j] = ans;
}


bool solve(){
    cin >> n ;
    n *= 2 ;
    v.assign(n , 0) ;
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i] ;
    }

    sort(all(v));
    reverse(all(v));
    int mx=v[0];
    vector<pair<int,int>>pr;
    int f=0;
    for(int i=1;i<n;++i){
        int take=v[i];
        pr.pb({v[0],v[i]});
        map<int,int>mp;
        for(int j=1;j<n;++j){
            if(j!=i){
                mp[v[j]]+=1;
            }
        }
        int sum=v[0];
        f=0;
        for(int j=1;j<n;++j){
            if(mp[v[j]] ==0) continue;
            // if(sum != v[j])
            mp[v[j]] -= 1;
            int need = sum-v[j];
            if(mp[need]==0) {
                f=1;
                break;
            }
            mp[need]-=1;
            sum=v[j];
            pr.pb({v[j],need});
        }
        if(!f) break;
        pr.clear();
    }
    if(f) no
    else{
        yes
        cout<<pr[0].F+pr[0].S<<nl;
        check2(pr)
    }
    // vec.assign(n , -1) ;
    // vis.assign(n , 0) ;
    // sort(all(v)) ;
    // reverse(all(v));
    // // check1(v)
    // // cout<<n<<nl;
    // for(int i = 0 ; i <= n ;++i){
    //     for(int j = 0 ; j <= n ; ++j){
    //         dp[i][j] = -1;
    //     }
    // }
    // if(rec(0,0)){
    //     yes
    //     for(int i=0;i<n/2;++i){
    //         // cout<<vec[i+n/2]<<" ";
    //         cout<<v[vec[i+n/2]]<<" "<<v[i+n/2]<<nl;
    //     }
    // }
    // else{
    //     no
    // }
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


