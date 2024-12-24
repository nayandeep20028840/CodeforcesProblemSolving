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
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    vector<int>c(m);
    for(int i=0;i<m;++i){
        cin>>c[i];
    }
    vector<pair<int,int>>p,pr;
    for(int i=0;i<n;++i){
        p.push_back({a[i],b[i]});
    }
    sort(p.begin(),p.end());
    map<int,int>done;
    for(int i=0;i<n;++i){
        int dif=p[i].first-p[i].second;
        // cout<<dif<<" ";
        if(done[dif]>0){

        }
        else{
            done[dif]=1;
            // cout<<dif<<" "<<a[i]<<endl;
            pr.push_back({dif,p[i].first});
        }
    }
    sort(pr.begin(),pr.end());
    int len=pr.size();
    int ans=0;
    // priority_queue<int>pq;
    // for(int i=0;i<m;++i){
    //     pq.push(c[i]);
    // }
    // // cout<<len<<" ";
    // for(int i=0;i<len;++i){
    //     int dif=pr[i].first;
    //     int num=pr[i].second;
    //     while(pq.size()>0 and pq.top()>=num){
    //         int ele=pq.top();
    //         // cout<<ele<<" ";
    //         // cout<<num<<" ";
    //         // cout<<dif<<" ";
    //         ans+=((ele-num)/dif+1)*2;
    //         pq.pop();
    //         pq.push(num-dif+(ele-num)%dif);
    //     }
    //     // cout<<ans<<" ";
    //     if(pq.size()==0) break;
    // }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    for(int i=0;i<m;++i){
        int cur=c[i];
        int j=0;
        while(j<len and cur>=p[j].first){
            int num=p[j].second;
            int dif=p[j].first;
            ans+=((cur-num)/dif+1)*2;
            cur=num-dif+(cur-num)%dif;
        }
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
    int t =1;
    // cin >> t ;  
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

