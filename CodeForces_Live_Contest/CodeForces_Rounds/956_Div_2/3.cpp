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

vector<int> f(vector<int>&a,vector<int>&b,vector<int>&c,int tot){
    int i=0;
    int sum=0;
    int n=a.size();
    vector<int>ans;
    while(i<n){
        sum+=a[i];
        i+=1;
        if(sum>=tot) break;
    }
    ans.push_back(1);
    ans.push_back(i);
    int j=n-1;
    sum=0;
    while(j>=i){
        sum+=b[j];
        j-=1;
        if(sum>=tot) break;
    }
    ans.push_back(j+2);
    ans.push_back(n);
    if(sum<tot) return {};
    sum=0;
    ans.push_back(i+1);
    ans.push_back(j+1);
    while(i<=j){
        sum+=c[i];
        i+=1;
    }
    if(sum<tot) return {};
    return ans;
}

bool solve(){
    int n;
    cin>>n;
    int sum=0;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    vector<int>b(n);
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    vector<int>c(n);
    for(int i=0;i<n;++i){
        cin>>c[i];
    }
    int tot=(sum+3-1)/3;
    vector<int> ans=f(a,b,c,tot);
    if(ans.size()>0){
        for(int i=0;i<6;++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    ans=f(a,c,b,tot);
    if(ans.size()>0){
        swap(ans[4],ans[2]);
        swap(ans[5],ans[3]);
        for(int i=0;i<6;++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    ans=f(b,a,c,tot);
    if(ans.size()>0){
        swap(ans[0],ans[2]);
        swap(ans[1],ans[3]);
        for(int i=0;i<6;++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    ans=f(b,c,a,tot);
    if(ans.size()>0){
        swap(ans[4],ans[2]);
        swap(ans[5],ans[3]);
        swap(ans[0],ans[2]);
        swap(ans[1],ans[3]);
        for(int i=0;i<6;++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    ans=f(c,a,b,tot);
    if(ans.size()>0){
        swap(ans[0],ans[2]);
        swap(ans[1],ans[3]);
        swap(ans[4],ans[2]);
        swap(ans[5],ans[3]);
        for(int i=0;i<6;++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    ans=f(c,b,a,tot);
    if(ans.size()>0){
        swap(ans[0],ans[2]);
        swap(ans[1],ans[3]);
        swap(ans[4],ans[2]);
        swap(ans[5],ans[3]);
        swap(ans[0],ans[2]);
        swap(ans[1],ans[3]);
        for(int i=0;i<6;++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return true;
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


