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
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}

bool solve(){
    int n , m ;
    cin >> n >> m ;
    vector<int > a(n) ;
    vector<int > b(n) ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i] ;
        sum += a[i] ;
    }
    for(int i = 0 ; i < n ; ++i){
        cin >> b[i] ;
    }
    if(sum < m){
        cout << -1 << nl ;
        return true ;
    }
    vector<int > one , two ;
    for(int i = 0 ; i < n ; ++i){
        if(b[i] == 1){
            one.pb(a[i]) ;
        }
        else{
            two.pb(a[i]) ;
        }
    }
    sort(all(one)) ;
    sort(all(two)) ;
    reverse(all(one)) ;
    reverse(all(two)) ;
    // check1(two)
    // check1(one)
    int i = 0 ;
    int j = 0 ;
    int move = m ;
    int ans = 0 ;
    while(i < two.size() || j < one.size()){
        int sum1 = 0 ;
        int add1 = 0 ;
        if(i < two.size()) {
            sum1 += two[i] ;
            add1 += 2 ;
        }
        int sum2 = 0 ;
        int add2 = 0 ;
        int len = one.size() ;
        // cout << len << nl ; 
        if(j < len - 1){
            sum2 += one[j] ;
            if(sum2 >= move){
                ans += 1 ;
                move -= sum2 ;
                break ;
            }
            else if(sum2 + sum1 >= move and sum2 + one[j + 1] < move and sum1 < move){
                ans += 3 ;
                move -= (sum2 + sum1) ;
                break ;
            }
            sum2 += one[j + 1] ;
            add2 += 2 ;
        }
        else if(j < len){
            sum2 += one[j] ;
            if(sum2 >= move){
                ans += 1 ;
                move -= sum2 ;
                break ;
            }
            else if(sum2 + sum1 >= move and sum1 < move){
                ans += 3 ;
                move -= (sum2 + sum1) ;
                break ;
            }
            add2 += 1 ;
        }
        if(sum2 >= sum1){
            ans += add2 ;
            j += add2 ;
            move -= sum2 ;
        }
        else{
            ans += add1 ;
            i += 1 ;
            move -= sum1 ;
        }
        // cout << sum1 << " " << sum2 << " " << move << " " << ans << " "<<i<<" "<<j<<nl; 
        if(move <= 0) break ;
    }
    if(i && move + two[i - 1] <= 0) ans -= 2 ;
    else if(j && move + one[j - 1] <= 0) ans -= 1 ;
    else if(j > 1 && move + one[j - 1] + one[j - 2] <= 0) ans -= 2 ;
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
    int cnt = 0 ;
    while (t--){
        cnt += 1 ;
        //cout << "Case #" << count << ": ";
        // if(cnt == 107){
        //     int n , m ;
        //     cin >> n >> m ;
        //     vector<int > a(n) ;
        //     vector<int > b(n) ;
        //     int sum = 0 ;
        //     cout<<m<<",";
        //     for(int i = 0 ; i < n ; ++i){
        //         cin >> a[i] ;
        //         sum += a[i] ;
        //         cout<<a[i]<<",";
        //     }
        //     cout<<"#";
        //     for(int i = 0 ; i < n ; ++i){
        //         cin >> b[i] ;
        //         cout<<b[i]<<",";
        //     }
        //     cout<<nl;
        //     continue ;
        // }
        if(solve()){
            //count++ ;
        }else{
            // no 
        }
    }
    return 0 ;
}


