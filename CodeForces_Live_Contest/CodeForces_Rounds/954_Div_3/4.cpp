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

int rec(vector<int>&v,int len,int tot,int taken,int i){
    if(tot>500) return 500;
    if(i>=len) return tot;
    int ans=500;
    if(taken==0){
        ans=min({ans,rec(v,len,tot*v[i],0,i+1),
                        rec(v,len,tot+v[i],0,i+1)});
    }
    else{
        ans=min(ans,rec(v,len,tot+v[i],taken,i+1));
    }
    return ans;
}

bool solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==2){
        // cout<<s<<nl;
        int anssss=stoi(s);
        cout<<anssss<<nl;
        return true;
    }
    vector<vector<int>>v;
    // cout<<s<<nl;
    for(int i=1;i<n;++i){
        vector<int>vv;
        int idx1=i-1;
        int idx2=i;
        int done=0;
        for(int j=0;j<n;++j){
            if(j==idx1 || j==idx2) {
                if(done==1) continue;
                int cur=0;
                // cout<<(s[j]-'0')<<nl;
                // cout<<(s[j+1]-'0')<<nl;
                cur+=(s[j]-'0');
                cur*=10;
                cur+=(s[j+1]-'0');
                vv.push_back(cur);
                // cout<<cur<<" ";
                done=1;
            }
            else{
                vv.push_back(s[j]-'0');
            }
        }
        // cout<<nl;
        v.push_back(vv);
    }
    int ans=inf;
    for(int i=0;i<n-1;++i){
        for(int j=0;j<v[i].size();++j){
            if(v[i][j]==0) {
                cout<<0<<nl;
                return true;
            }
        }
    }
    for(int i=0;i<n-1;++i){
        vector<int>last;
        int cal=0;
        for(int j=0;j<v[i].size();++j){
            // cout<<v[i][j]<<" ";
            if(v[i][j]==1){
                
            }
            else{
                cal+=v[i][j];
            }
        }
        // ans=min(ans,rec(v[i],v[i].size(),v[i][0],0,1));
        // cout<<ans<<" ";
        // cout<<nl;
        ans=min(ans,cal);
    }
    ans=max(1ll,ans);
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


