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
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    map<int,int>mp,mp1;
    int ans=0;
    int num=x;
    for(int i=0;i<n;++i){
        // cout<<mp[a[i]]<<" ";
        if(mp[a[i]]>0){
            ans+=1;
            mp.clear();
            mp1.clear();
            if(num%a[i]==0) {
                // cout<<num/a[i]<<" ";
                mp[num/a[i]]=1;
            }
            // cout<<mp[1]<<" ";
            num=x;
        }
        if(x%a[i]==0 and a[i]>1 and x>1){
            int val=x;
            val/=a[i];
            num/=a[i];
            while(mp[val]>0 and val%a[i]==0 and a[i]>1 and val>1 and val>a[i]){
                val/=a[i];
            }
            mp[val]=1;
            mp1[a[i]]=1;
        }
        // cout<<ans<<" ";
        // cout<<mp[1]<<" ";
    }
    if(mp1[num]>0 and num>1) ans+=1;
    ans+=1;
    cout<<ans<<endl;
    return true;
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
    int count = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(count==31){
            int n,x;
            cin>>n>>x;
            vector<int>a(n);
            for(int i=0;i<n;++i){
                cin>>a[i];
            }
            cout<<n<<","<<x<<",";
            for(int i=0;i<n;++i){
                cout<<a[i]<<",";
            }
            cout<<endl;
        }
        else if(solve()){
            //count++ ;
        }else{
            // no 
        }
        count+=1;
    }
    return 0 ;
}
