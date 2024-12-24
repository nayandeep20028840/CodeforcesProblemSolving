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

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(); // pattern size // we need to find this pattern in the text 
    int T = t.size();

    // Precompute powers of p
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    // Compute hash values for the entire text
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++) {
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Compute hash value for the pattern
    long long h_s = 0;
    for (int i = 0; i < S; i++) {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Store occurrences
    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m) {
            occurrences.push_back(i);
        }
    }

    return occurrences;
}

bool solve(){
    int n;
    cin>>n;
    vector<int> p_pow(4);
    p_pow[0] = 1;
    int p=31;
    for (int i = 1; i < 4; i++) {
        p_pow[i] = (p_pow[i-1] * p) % MOD;
    }
    map<int,int>mp1,mp2,mp3,mp4;
    int f=0;
    mp3[0]=1;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        int len=s.size();
        int pf=0;
        for(int j=0;j<len;++j){
            pf=(pf+ (s[j]-'a'+1) * p_pow[j]) % MOD;
        }
        int sf=0;
        for(int j=len-1;j>=0;--j){
            sf=(sf+ (s[j]-'a'+1) * p_pow[len-1-j]) % MOD;
        }
        // cout<<len<<" "<<pf<<" "<<sf<<nl;
        mp1[pf]+=1;
        mp2[sf]+=1;
        if(mp1[sf]>=1) f=1;
        if(mp2[pf]>=1) f=1;
        if(mp3[sf]>=1) f=1;
        int pf1=0;
        for(int j=0;j<len-1;++j){
            pf1=(pf1+ (s[j]-'a'+1) * p_pow[j]) % MOD;
        }
        mp3[pf1]+=1;
        int sf1=0;
        for(int j=len-1;j>0;--j){
            sf1=(sf1+ (s[j]-'a'+1) * p_pow[len-1-j]) % MOD;
        }
        mp4[sf1]+=1;
        if(mp1[sf1]>=1) f=1;
    }
    for(int i=0;i<n;++i){

    }
    if(f) yes
    else no
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


