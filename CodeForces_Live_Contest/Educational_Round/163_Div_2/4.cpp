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

// USES - Longest Palindromic Substring , 
// Pattern Matching:to find occurrences of a specific
// palindromic pattern within a given text.
/*

aba -->#a#b#a#
abba -->#a#b#b#a#

how to build manacher
m.build(s) ;

*/
struct manacher {
    vector<int > p ;
    int n ;
    void run_manacher(string s) {
        // cout << s << "\n" ; 
        int n = s.length() ;
        s = "$" + s + "^" ;
        p.resize(n + 2) ;
        int l = 1 ; // l and r are not inclusive 
        int r = 1 ;
        for(int i = 1 ; i <= n ; ++i){
            p[i] = max(0ll , min(p[l + r - i] , r - i)) ;
            while(i - p[i] >= 0 && i + p[i] <= n && s[i - p[i]] == s[i + p[i]]){
                p[i]++ ;
            }
            if(i + p[i] > r){ // or
                l = i - p[i] ;
                r = i + p[i] ;
            }
        }
        // cout << s << nl ;
        // for(auto &v : p){
        //     cout << v << " " ;
        // }
        // cout << "\n" ;
    }
    void build(string s){ // so that every substring is odd length 
        string t ;
        for (auto it : s){
            t += string("#") + it ; // making every substring odd length 
        }
        run_manacher(t + "#") ;
    }
    // abbabba 
    // cen = 1 , odd = 1 length = 1 
    // cen = 1 , odd = 0 length = 4 
    vector<int > get_vector_p(){
        return p ;  
    }
    int getlongest(int cen, bool odd) {
        int pos = 2 * cen + odd + 1 + (!odd) ;
        return p[pos] - 1 ;
    }
    bool checkPal(int l, int r) {
        if ((r - l + 1) <= getlongest((r + l) / 2, l % 2 == r % 2)) {
            return 1 ;
        }
        return 0 ;  
    }
} man;


// LPS (Longest Prefix Suffix) Algorithm:

// Purpose: The LPS algorithm is primarily used to find the length of the longest proper prefix which is also a proper suffix of a given string for each position in the string.

// Key Concept: It calculates an array where each element at index i represents the length of the longest proper prefix of the substring ending at position i that is also a proper suffix of the substring.

// Usage: It is used as a building block in other string matching algorithms, like the KMP algorithm.

vector<int > longestprefixsuffix(string s){
    int n = s.size();
    vector<int > lps(n , 0);
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n){
        if(len < (i - len - 1) and s[i] == s[len] || s[i] == '?' || s[len] == '?'){
            len++ ;  
            lps[i] = len ;
            i++ ;
        }else{
            if(len != 0){
                len = lps[len - 1] ;
            }else{
                lps[i] = 0 ;
                i++ ;
            }
        }
    }
    return lps ;
}



bool solve(){
    string s ;
    cin >> s ;
    int n = s.size() ;
    string rev="" ;
    for(int i = 0 ; i < n ; ++i){
        rev += s[i];
    }
    int ans=0;
    for(int i = 0 ; i < n ; ++i){
        vector<int > p = longestprefixsuffix(rev) ;
        check1(p)
        for(int j = 0 ; j < p.size() ; ++j){
            if(p[j]){
                if(j + 1 - (p[j] * 2) <= 0){
                    int t = min(p[j] * 2 , (n / 2) * 2) ;
                    ans = max(ans , t) ;
                }
            }
        }
        reverse(all(rev)) ;
        rev.pop_back() ;
        reverse(all(rev)) ;
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


