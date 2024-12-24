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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int mn_idx=n+1;
    int mx_idx=-1;
    for(int i=0;i<n-k;++i){
        if(s[i]==s[i+k]){
            mn_idx=min(mn_idx,i);
            mx_idx=max(mx_idx,i);
        }
    }
    int sum=0;
    // cout<<mx_idx<<' '<<mn_idx<<endl;
    if(mx_idx+k>=n || (mn_idx<=mx_idx-k and mn_idx!=n+1)){
        cout<<-1<<endl;
        return true;
    }
    for(int i=mx_idx+1;i<mx_idx+k;++i){
        sum+=(s[i]=='1');
    }
    // cout<<1<<" ";
    for(int i=mx_idx+k;i<n;++i){
        sum+=(s[i]=='1');
        if(mn_idx<=i-k-k and mn_idx!=n+1){
            cout<<-1<<endl;
            return true;
        }
        // cout<<sum<<" ";
        if((sum==k || sum==0) and k==n){
            cout<<n<<endl;
            return true;
        }
        // cout<<sum<<" ";
        if(sum==0 || sum==k){
            int st=i-k;
            int end=n-k;
            int f=0;
            for(int j=end;j<n;++j){
                if(st<0 || j<0) break;
                if(s[j]==s[st]){
                    f=1;
                    break;
                }
                st-=1;
            }
            if(!f and i-k+1>0){
                cout<<i-k+1<<endl;
                return true;
            }
            sum-=(s[i-k+1]=='1');
        }
        else{
            sum-=(s[i-k+1]=='1');
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


