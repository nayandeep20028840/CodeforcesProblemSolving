#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define inf               1000000000000000000 // 18 zero's
#define nl                "\n"
#define ll                long long
#define int               ll
const int MOD = 1000000007 ; // 998244353 
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
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.first != b.first){return a.first < b.first ;}return a.second > b.second ;}

bool solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat1(n,vector<int>(m));
    vector<vector<int>>mat2(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat1[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat2[i][j];
        }
    }
    map<vector<int>,int>mp;
    for(int i=0;i<m;++i){
        vector<int>v;
        for(int j=0;j<n;++j){
            v.push_back(mat1[j][i]);
        }
        sort(v.begin(),v.end());
        mp[v]+=1;
    }
    int f=0;
    for(int i=0;i<m;++i){
        vector<int>v;
        for(int j=0;j<n;++j){
            v.push_back(mat2[j][i]);
        }
        sort(v.begin(),v.end());
        if(mp[v]<=0) f=1;
        mp[v]-=1;
    }
    mp.clear();
    for(int i=0;i<n;++i){
        vector<int>v;
        for(int j=0;j<m;++j){
            v.push_back(mat1[i][j]);
        }
        sort(v.begin(),v.end());
        mp[v]+=1;
    }
    for(int i=0;i<n;++i){
        vector<int>v;
        for(int j=0;j<m;++j){
            v.push_back(mat2[i][j]);
        }
        sort(v.begin(),v.end());
        if(mp[v]<=0) f=1;
        mp[v]-=1;
    }
    if(f){
        cout<<"NO"<<nl;
    }
    else{
        cout<<"YES"<<nl;
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


