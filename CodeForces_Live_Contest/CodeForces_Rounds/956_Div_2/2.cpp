#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD = 1000000007 ; // 998244353 
const long long inf = 1000000000000000000LL; // 18 zero's // LLONG_MAX = 9223372036854775807 - 19 digits
#define int long long

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
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>b(n,vector<int>(m));
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char c;
            cin>>c;
            if(c=='0') a[i][j]=0;
            if(c=='1') a[i][j]=1;
            if(c=='2') a[i][j]=2;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char c;
            cin>>c;
            if(c=='0') b[i][j]=0;
            if(c=='1') b[i][j]=1;
            if(c=='2') b[i][j]=2;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int sum=0;
            if(b[i][j]>=a[i][j]){
                sum+=(b[i][j]-a[i][j]);
            }
            else{
                sum=((b[i][j]-a[i][j])+3)%3;
            }
            mat[i][j]=sum;
        }
    }
    vector<int>v1;
    for(int i=0;i<n;++i){
        int sum=0;
        for(int j=0;j<m;++j){
            sum+=mat[i][j];
        }
        v1.push_back(sum);
    }
    vector<int>v2;
    for(int i=0;i<m;++i){
        int sum=0;
        for(int j=0;j<n;++j){
            sum+=mat[j][i];
        }
        v2.push_back(sum);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int f=0;
    if(v1.size()==1) if(v1[0]%3) f=1;
    if(v2.size()==1) if(v2[0]%3) f=1;
    for(int i=1;i<v1.size();++i){
        if((v1[i]-v1[i-1])%3 || v1[i]%3){
            f=1;
        }
    }
    for(int i=1;i<v2.size();++i){
        if((v2[i]-v2[i-1])%3 || v2[i]%3){
            f=1;
        }
    }
    if(f) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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


