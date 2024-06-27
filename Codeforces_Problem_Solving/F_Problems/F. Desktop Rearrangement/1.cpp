#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD = 1000000007 ; // 998244353 
#define inf   1000000000000000000 // 18 zero's // LLONG_MAX = 9223372036854775807 - 19 digits
#define int   long long
#define nl    "\n"

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor 
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.first != b.first){return a.first < b.first ;}return a.second > b.second ;}

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
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<char>>mat(n+1,vector<char>(m+1));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
        }
    }
    vector<int>ans(n*m+1,0);
    FT<int>ft(n*m+1);
    int st=0;
    map<pair<int,int>,int>mp;
    int cnt=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(mat[j][i]=='*'){
                ft.inc(st,1);
                cnt+=1;
            }
            mp[{j,i}]=st;
            st+=1;
        }
    }
    // for(int i=0;i<n*m;++i){
    //     cout<<ft.at(i)<<" ";
    // }
    // cout<<nl;
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        x-=1;
        y-=1;
        int idx=mp[{x,y}];
        // cout<<idx<<" ";
        int val=ft.at(idx);
        // cout<<val<<" ";
        if(val==1){
            ft.inc(idx,-1);
            cnt-=1;
        }
        else{
            ft.inc(idx,1);
            cnt+=1;
        }
        // cout<<cnt<<" ";
        int have=ft.at(0,cnt-1);
        // cout<<have<<" ";
        cout<<cnt-have<<nl;
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
    int t = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            
        }else{
            
        }
    }
    return 0 ;
}




