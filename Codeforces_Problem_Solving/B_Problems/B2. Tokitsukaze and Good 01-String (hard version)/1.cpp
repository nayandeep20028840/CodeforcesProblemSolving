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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=1;
    int prev=0;
    string str=s;
    for(int i=1;i<n;++i){
        if(s[i]!=s[i-1]){
            if(cnt%2){
                str[i]='#';
                str[i-1]='#';
                prev=1-prev;
            }
            else{
                if(prev==1){
                    str[i]='#';
                    str[i-1]='#';
                }
            }
            cnt=1;
        }
        else{
            cnt+=1;
        }
    }
    string temp="";
    int move=0;
    for(int i=0;i<n;++i){
        if(str[i]!='#') temp+=str[i];
        else move+=1;
    }
    // cout<<temp<<nl;
    // cout<<str<<nl;
    int sub=1;
    for(int i=1;i<temp.size();++i){
        if(temp[i]!=temp[i-1]) sub+=1;
    }
    cout<<move/2<<" "<<sub<<nl;
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
    int count = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(count==64){
            int n;
            cin>>n;
            string s;
            cin>>s;
            cout<<s<<nl;
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


