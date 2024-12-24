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
const int Declare_Like_This = 17'000'005 ; // Will not give MLE 
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

bool solve(){
    int n , k ;
    cin >> n >> k ;
    vector<vector<int > > v(k , vector<int > (n)) ;
    for(int i = 0 ; i < k ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin >> v[i][j] ;
            v[i][j] -= 1 ;
        }
    }
    vector<int > ans(n , inf) ;
    map<int , set<int > > three ;
    for(int i = 0 ; i < k ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(j == 0) continue ;
            ans[v[i][j]] = min(ans[v[i][j]] , j) ;
            three[v[i][j]].insert(j) ;
        }
    }
    // check1(ans)
    map<int , int > mp ;
    int f = 0 ;
    int cnt_2 = 0 ;
    for(int i = 0 ; i < n ; ++i){
        if(ans[i] == inf) continue ;
        mp[ans[i]] += 1 ;
    }
    for(auto &i : three){
        if(i.S.size() > 2){
            f = 1 ;
        }
        if(i.S.size() == 2){
            // cout << *(i.S.rbegin()) << nl ;
            // cout << *(i.S.begin()) << nl ;
            if(*(i.S.rbegin()) - *(i.S.begin()) > 1) f = 1 ;
        }
    }
    for(auto &i : mp){
        if(i.S == 2) cnt_2 += 1 ;
        if(i.S > 2) f = 1 ;
    }
    if(f || cnt_2 > 1) no
    else {
        // check1(ans)
        int rep = -1 ;
        int rep2 = -1 ;
        map<int , int > th ;
        for(int i = 0 ; i < n ;  ++i){
            th[ans[i]] += 1 ;
            if(th[ans[i]] > 1){
                rep = i ;
                rep2 = ans[i] ;
                break ;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(rep2 == ans[i]){
                rep2 = i ;
                break ;
            }
        }
        // cout << rep << " " << rep2 << nl ;
        // for(int i = 0 ; i < k ; ++i){
        //     for(int j=0 ; j < n ; ++j){
        //         cout << v[i][j] << " " ;
        //     }
        //     cout << nl ;
        // }
        map<int , int > check ;
        for(int i = 0 ; i < k ; ++i){
            if(v[i][0] == rep || v[i][0] == rep2) continue ;
            // cout << i << " " ;
            for(int j = 0 ; j < n ; ++j){
                if(j == 0) continue ;
                if(v[i][j] == rep || v[i][j] == rep2){
                    // cout << rep << " " ;
                    check[v[i][j]] = 1 ;
                    break ;
                }
            }
        }
        if(check.size() > 1) no
        else yes
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
    int t ;
    cin >> t ;  
    //int count = 1 ;
    int test = 0 ;
    while (t--){
        test += 1 ;
        //cout << "Case #" << count << ": ";
        // if(test == 406){
        //     int n , k ;
        //     cin >> n >> k ;
        //     vector<vector<int > > v(k , vector<int > (n)) ;
        //     for(int i = 0 ; i < k ; ++i){
        //         for(int j = 0 ; j < n ; ++j){
        //             cin >> v[i][j] ;
        //             v[i][j] -= 1 ;
        //         }
        //     }
        //     cout << n << "" << k << "" ;
        //     for(int i = 0 ; i < k ; ++i){
        //         for(int j = 0 ; j < n ; ++j){
        //             cout << v[i][j] << "" ;
        //         }
        //     }
        //     cout << nl ;
        // }
        if(solve()){
            //count++ ;
        }else{
            // no 
        }
    }
    return 0 ;
}


