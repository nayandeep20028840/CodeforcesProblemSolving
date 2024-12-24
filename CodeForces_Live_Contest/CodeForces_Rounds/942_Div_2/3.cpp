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

template <typename T> class BIT {
public:
    vector<T> bit;
    int n;

    BIT() { n = 0; }

    BIT(int _n) {
        n = _n;
        bit.assign(n, 0);
    }

    // increase the value of element at idx idxex i.e a[idx]
    void inc(int idx, T val) {
        // assert(0 <= idx and idx < n);
        for (int i = idx + 1; i <= n; i += (i & -i))
            bit[i - 1] += val;
    }

    // sum of all the elements in [0..idx]
    T query(int idx) {
        // assert(0 <= idx and idx < n);
        T res = 0;
        for (int i = idx + 1; i > 0; i -= (i & -i))
            res += bit[i - 1];
        return res;
    }

    // get the value of element at idx index i.e a[idx]
    T at(int idx) {
        // assert(0 <= idx and idx < n);
        return query(idx) - (idx - 1 >= 0 ? query(idx - 1) : 0);
    }

    // sum of all the element [l..r]
    T at(int l, int r) {
        // assert(0 <= l and l <= r and r < n);
        return query(r) - (l - 1 >= 0 ? query(l - 1) : 0);
    }
};

template <typename T> class FT {
public:
    BIT<T> f1, f2;
    int n;

    FT() { n = 0; }

    FT(int _n) {
        n = _n;
        f1 = f2 = BIT<T>(_n + 1);
    }

    // increase the value of element at idx idxex i.e a[idx]
    void inc(int idx, T val) {
        // assert(0 <= idx and idx < n);
        inc(idx, idx, val);
    }

    // increase all the elements in [l..r] by val
    void inc(int l, int r, T val) {
        // assert(0 <= l and l <= r and r < n);
        f1.inc(l, val);
        f1.inc(r + 1, -val);
        f2.inc(l, val * (l - 1));
        f2.inc(r + 1, -val * r);
    }

    // sum of all the elements in [0..idx]
    T query(int idx) {
        // assert(0 <= idx and idx < n);
        return f1.query(idx) * idx - f2.query(idx);
    }

    // get the value of element at idx index i.e a[idx]
    T at(int idx) {
        // assert(0 <= idx and idx < n);
        return query(idx) - (idx - 1 >= 0 ? query(idx - 1) : 0);
    }

    // get the sum of all the element [l..r]
    T at(int l, int r) {
        // assert(0 <= l and l <= r and r < n);
        return query(r) - (l - 1 >= 0 ? query(l - 1) : 0);
    }
};

bool solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>v;
    sort(all(a));
    // check1(a);
    int rem=k;
    FT<int>ft(n);
    for(int i=0;i<n;++i){
        ft.inc(i,a[i]);
        // cout<<ft.at(i)<<" ";
    }
    // cout<<nl;
    for(int i=0;i<n-1;++i){
        int ele=ft.at(i);
        int want=(i+1)*(a[i+1]-ele);
        // cout<<want<<" ";
        if(want>rem){
            int times = rem / (i + 1);
            int left = rem % (i + 1);
            ft.inc(0,i,times);
            if(left > 0) {
                ft.inc(i-left+1,i,1);
            }
            rem=0;
            break;
        }
        else{
            ft.inc(0,i,a[i+1]-ele);
            rem -= want;
        }
    }
    // cout<<nl;
    if(rem > 0){
        int times = rem / (n);
        int left = rem % (n);
        ft.inc(0,n-1,times);
        if(left > 0) {
            ft.inc(n-1-left+1,n-1,1);
        }
    }
    vector<int>vv;
    for(int i=0;i<n;++i){
        // cout<<ft.at(i)<<" ";
        vv.pb(ft.at(i));
    }
    // cout<<nl;
    int ans=1;
    ans += (vv[0]-1)*n;
    int boss=vv[0];
    int one=0;
    int two=0;
    for(int i=0;i<n;++i){
        int ok = vv[i]-boss;
        if(ok>=2){
            two += 1 ;
            one += 1;
        }
        else if(ok>=1){
            one+=1;
        }
    }
    ans+=one;
    // ans+=two;
    cout<<ans<<nl;
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


