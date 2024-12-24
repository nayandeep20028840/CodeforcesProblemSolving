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
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}

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
        int n = s.length() ;
        s = "$" + s + "^" ;
        // cout << s << "\n" ; 
        p.assign(n + 2 , 0) ;
        int l = 1 ; // l and r are not inclusive 
        int r = 1 ;
        // cout<<p[n+1]<<" ";
        for(int i = 1 ; i <= n ; ++i){
            p[i] = max(0ll , min(p[l + r - i] , r - i)) ;
            while(i - p[i] >= 0 && i + p[i] <= n && s[i - p[i]] == s[i + p[i]]){
                p[i]++ ;
            }
            if(i + p[i] > r){ // or
                l = i - p[i] ;
                r = i + p[i] ;
            }
            
            // cout<<p[i]<<" " ;
        }
        // cout<<p[n+1]<< " ";
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
    vector<int > get_vector_p(){
        return p ;  
    }
    // abbabba // 0 based indexing 
    // centre = 1 , odd = 1 length = 1 this means we have to odd length palindrome with centre as 1 
    // centre = 1 , odd = 0 length = 4 this means we have to even length palindrome with centre as 1 
    int getlongest(int centre, bool odd) {
        int pos = 2 * centre + odd + 1 + (!odd) ;
        return (p[pos] - 1) ;
    }
    bool checkPal(int l, int r) {
        if ((r - l + 1) <= getlongest((r + l) / 2, l % 2 == r % 2)) {
            return 1 ;
        }
        return 0 ;  
    }
} man;


bool solve(){
    string s;
    cin >> s; 
    int n=s.size();
    man.build(s);
    vector<int> p = man.get_vector_p();
    // check1(p)
    int len=p.size();
    // cout<<len<<nl;
    if(p[len / 2] - 1 != n){
        yes
        cout<<1<<nl;
        cout<<s<<nl;
        return true;
    }
    int div = -1 ;
    if(n%2){
        int idx1 = len / 2 - 2 ;
        int idx2 = len - 4 ;
        int cnt=n-2;
        while(idx2 >= len / 2 and idx1 >= 0){
            int val1 = p[idx1];
            int val2 = p[idx2];
            if(p[idx1 - val1] != 0 and p[val2 + idx2] != 0){
                div = cnt;
                break;
            }
            cnt-=1;
            idx1-=1;
            idx2-=1;
        }
    }
    else{
        int idx1 = len / 2 - 2 ;
        int idx2 = len - 4 ;
        int cnt=n - 2;
        while(idx2 >= len / 2 and idx1 >= 0){
            int val1 = p[idx1];
            int val2 = p[idx2];
            if(p[idx1 - val1] != 0 and p[val2 + idx2] != 0){
                div = cnt;
                break;
            }
            cnt-=1;
            idx1-=1;
            idx2-=1;
        }
    }
    if(div == -1){
        no
    }
    else{
        yes
        cout<<2<<nl;
        string ft="";
        string sec="";
        for(int i=0;i<div;++i){
            ft+=s[i];
        }
        for(int i=div;i<n;++i){
            sec+=s[i];
        }
        cout<<ft<<" "<<sec<<nl;
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


