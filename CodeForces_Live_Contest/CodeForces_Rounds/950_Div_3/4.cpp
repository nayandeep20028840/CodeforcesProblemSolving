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

int n;
vector<int>a;

int f(int idx){
    if(idx<0 || idx>=n) return 1;
    vector<int>v;
    for(int i=0;i<n;++i){
        if(i==idx) continue;
        v.push_back(a[i]);
    }
    vector<int>gcd2;
    for(int i=1;i<n-1;++i){
        gcd2.push_back(GCD(v[i-1],v[i]));
    }
    int f=0;
    for(int i=1;i<n-2;++i){
        if(gcd2[i]<gcd2[i-1]) f=1;
    }
    if(f==1) return 1;
    return 0;
}

bool solve(){
    cin>>n;
    a=vector<int>(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>gcd(n-1);
    for(int i=1;i<n;++i){
        gcd[i-1]=GCD(a[i-1],a[i]);
    }
    int one=0;
    int idx=-1;
    for(int i=1;i<n-1;++i){
        if(gcd[i]<gcd[i-1]) {
            idx=i;
            one+=1;
        }
    }
    if(one==0){
        cout<<"YES"<<nl;
        return true;
    }
    int cnt=inf;
    for(int i=0;i<10;++i){
        cnt=min(cnt,f(idx-i));
    }
    for(int i=0;i<10;++i){
        cnt=min(cnt,f(idx+i));
    }
    if(cnt==0){
        cout<<"YES"<<nl;
    }
    else{
        cout<<"NO"<<nl;
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


