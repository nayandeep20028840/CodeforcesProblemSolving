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
    int n;
    cin>>n;
    vector<int>k(n);
    vector<pair<int,int>>p;
    for(int i=0;i<n;++i){
        cin>>k[i];
        p.push_back({k[i],i});
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    int low=0;
    int high=1e9+1;
    while(high-low>1){
        int i=(low+high)/2;
    // for(int i=1;i<=600;++i){
        int tot=i;
        int mx=i*p[0].first;
        vector<int>ans(n,0);
        ans[p[0].second]=i;
        // cout<<i<<" ";
        // cout<<mx<<" ";
        int f=0;
        for(int j=1;j<n;++j){
            int mult=(mx+p[j].first-1)/p[j].first;
            // cout<<mult<<" ";
            tot+=mult;
            ans[p[j].second]=mult;
            if(mult>1e9) f=1;
            mult*=p[j].first;
        }
        // cout<<endl;
        if(tot<mx and f==0){
            for(int j=0;j<n;++j){
                cout<<ans[j]<<" ";
            }
            cout<<endl;
            return true;
        }
        else if(f==1 and tot<mx){
            high=i;
        }
        else{
            low=i;
        }
    }
    cout<<-1<<endl;
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


