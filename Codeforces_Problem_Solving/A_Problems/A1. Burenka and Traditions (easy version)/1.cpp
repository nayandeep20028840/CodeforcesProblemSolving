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

int n;
vector<int>a;
vector<vector<int>>dp;
int rec(int i,int prev){
    if(i >= n) return 0;
    if(i==n-1){
        return dp[i][prev+1]=0;
    }
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int ans=0;
    // cout<<(a[i]^prev)<<" ";
    if(a[i]==0){
        ans=rec(i+1,-1);
    }
    else if(a[i]==a[i+1]){
        // cout<<ans<<" ";
        ans=1+min({rec(i+2,-1),rec(i+1,prev)});
    }
    else{
        // cout<<prev<<" ";
        if(prev==-1){
            ans=1+min({rec(i+1,i),rec(i+1,-1),rec(i+1,prev)});
        }
        else{
            int val=0;
            for(int j=prev;j<=i;++j) val=(val^a[j]);
            if(val==a[i+1]) ans=1+min({rec(i+2,-1),rec(i+1,i),rec(i+1,prev)});
            else ans=1+min({1+rec(i+2,-1),rec(i+1,-1),rec(i+1,i),rec(i+1,prev)});
        }
    }
    // cout<<ans<<" ";
    return dp[i][prev+1]=ans;
}
bool solve(){
    cin>>n;
    a=vector<int>(n);
    int mx=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    cout<<rec(0,-1)<<nl;
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


