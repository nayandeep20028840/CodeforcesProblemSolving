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
template<class T > using pbds_SET = tree< T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_SET<pair<int , int > > s; for pairs
template<class T > using pbds_MULTISET = tree< T , null_type , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_MULTISET<pair<int , int > > s; for pairs

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

/*
KMP (Knuth-Morris-Pratt) Algorithm:
Purpose: KMP is a more comprehensive algorithm used to efficiently search for a 
pattern within a text while avoiding unnecessary character comparisons.
Key Concept: It constructs a prefix array (also known as the LPS array) for the
pattern and uses this array to skip characters in the text during the search, 
reducing the number of character comparisons.
Advantages: KMP is known for its linear time complexity, making it efficient for large texts.
Usage: It's widely used in text searching, text processing, and string matching applications.

*/

vector<int > longestprefixsuffix(string s){
    int n = s.size();
    vector<int > lps(n , 0);
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n){
        if(s[i] == s[len]){
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

int kmp(string p, string s){
    int plen = p.size() ; // pattern length // we have to find this pattern in the string 
    int slen = s.size() ; // string length 
    vector<int > pattern_lps = longestprefixsuffix(p) ;
    int len = 0 ;
    int i = 0 ;
    int cnt = 0 ;
    int st = 0;
    // check1(pattern_lps)
    while(i < slen){
        if(s[i] == p[len]){
            len++ ;
            i++ ;
        }
        else{
            if(len != 0){
                len = pattern_lps[len - 1] ;
            }else{
                i++ ;
            }
        }
        if(len == plen){
            int val = i - len ;
            if(val >= st){
                cnt += 1 ;
                st = i ;
            }
            len = pattern_lps[len - 1] ;
        }
    }
    return cnt ; // cnt is the number of times the pattern occurs in the string s 
}

bool solve(){
    int n , l , r ;
    cin >> n >> l >> r ;
    string s ;
    cin >> s ;
    int low = -1 ;
    int high = n + 1 ;
    while(high - low > 1){
        int mid = (high + low) / 2 ;
        int start = mid ;
        string first = "" ;
        for(int i = 0 ; i < mid ; ++i){
            first += s[i];
        }
        int j = 0 ;
        if(first.size() == 0) {
            first += s[0];
        }
        int cnt = kmp(first , s);
        // cout << low << " " <<high << " " << mid << " " << cnt << " " << j << nl ;
        if(cnt >= l){
            low = mid ;
        }
        else{
            high = mid ;
        }
    }
    cout << max(0ll,low) << nl ;
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


