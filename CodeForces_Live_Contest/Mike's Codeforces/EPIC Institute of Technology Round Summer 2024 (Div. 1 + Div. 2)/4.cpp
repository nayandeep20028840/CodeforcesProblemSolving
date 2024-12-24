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
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>cnt1(n+1,0);
    for(int i=0;i<n;++i){
        cnt1[a[i]]+=1;
    }
    vector<int>v;
    vector<pair<int,int>>p;
    for(int i=1;i<=n;++i){
        if(cnt1[i]>0){
            v.push_back(i);
            p.push_back({cnt1[i],i});
        }
    }
    sort(p.begin(),p.end());
    sort(v.begin(),v.end());
    int len=v.size();
    int j=0;
    int i=0;
    int ans=0;
    vector<int>vis(n+1,0);
    int mx=0;
    while(i<len){
        while(i<len and vis[v[i]]==1) i+=1;
        if(i<len and vis[v[i]]==0){
            vis[v[i]]=1;
            mx=max(mx,v[i]);
            ans+=1;
            i+=1;
        }
        while(j<len and (p[j].second<=mx || vis[p[j].second]==1)){
            j+=1;
        }
        if(j>=len) break;
        int have=p[j].first;
        have-=1;
        while(i<len and have>0){
            if(vis[v[i]]==0){
                vis[v[i]]=1;
                mx=max(mx,v[i]);
                i+=1;
                ans+=1;
                have-=1;
            }
            else{
                i+=1;
            }
        }
        vis[p[j].second]=1;
    }
    cout<<ans<<endl;
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


