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

int query(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    int x;
    cin>>x;
    if(x==1) return a;
    if(x==2) return b;
    return -1;
}

bool solve(){
    int n;
    cin>>n;
    int tot=power(2,n);
    vector<int>a;
    for(int i=1;i<=tot;++i){
        a.push_back(i);
    }
    int len=0;
    int ans=0;
    while(true){
        len=a.size();
        if(len==2){
            ans=query(a[0],a[1]);
            break;
        }
        if(len==1){
            ans=a[0];
            break;
        }
        vector<int>v;
        for(int i=0;i<len;i+=4){
            int val=query(a[i],a[i+3]);
            if(val==-1){
                v.push_back(query(a[i+1],a[i+2]));
            }
            else if(val==a[i+3]){
                v.push_back(query(a[i+1],a[i+3]));
            }
            else{
                v.push_back(query(a[i],a[i+2]));
            }
        }
        a=v;
    }
    cout<<"! "<<ans<<endl;
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


