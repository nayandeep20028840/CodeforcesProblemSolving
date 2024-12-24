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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int f=0;
            int cur=mat[i][j];
            int mx=-1;
            if(i>0) {
                if(cur>mat[i-1][j]) {
                mx=max(mx,mat[i-1][j]);
                f+=1;
            }
            }
            else f+=1;
            if(j>0) {
                if(cur>mat[i][j-1]) {
                mx=max(mx,mat[i][j-1]);
                f+=1;
            }
            }
            else f+=1;
            if(j<m-1) {
                if(cur>mat[i][j+1]) {
                mx=max(mx,mat[i][j+1]);
                f+=1;
            }
            }
            else f+=1;
            if(i<n-1) {
                if(cur>mat[i+1][j]) {
                mx=max(mx,mat[i+1][j]);
                f+=1;
            }
            }
            else f+=1;
            if(f==4) {
                if(mx!=-1) mat[i][j]=mx;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<mat[i][j]<<" ";
        }
        cout<<nl;
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


