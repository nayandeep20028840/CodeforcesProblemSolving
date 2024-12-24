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
int LCM(int a, int b){return ((long long)a / (long long)GCD(a, b) * (long long)b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.first != b.first){return a.first < b.first ;}return a.second > b.second ;}

bool solve(){
    int n,c;
    cin>>n>>c;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    a[0]+=c;
    int idx=-1;
    int mx=-1;
    for(int i=0;i<n;++i){
        if(a[i]>mx){
            mx=a[i];
            idx=i;
        }
    }
    vector<int>pf(n,0);
    pf[0]=a[0];
    for(int i=1;i<n;++i){
        pf[i]=pf[i-1]+a[i];
    }
    vector<int>ans(n,0);
    for(int i=0;i<n;++i){
        if(i==idx){
            continue;
        }
        int val=pf[i];
        // cout<<val<<nl;
        if(val<mx){
            ans[i]=i+1;
        }
        else{
            ans[i]=i;
        }
    }
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }
    cout<<nl;
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


