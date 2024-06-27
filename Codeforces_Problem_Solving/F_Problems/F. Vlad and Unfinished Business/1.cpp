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
    int n,k;
    cin>>n>>k;
    int x,y;
    cin>>x>>y;
    vector<int>nums(k);
    map<int,int>mp;
    for(int i=0;i<k;++i){
        cin>>nums[i];
        mp[nums[i]]=1;
    }
    mp[y]=1;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    q.push(x);
    vector<int>vis(n+1,0);
    vector<int>dist(n+1,0);
    vis[x]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto child:adj[node]){
            if(vis[child]==0){
                vis[child]=1;
                dist[child]=dist[node]+1;
                q.push(child);
            }
        }
    }
    int ans=0;
    ans-=dist[y];
    vis.assign(n+1,0);
    function<int(int,int)> dfs=[&](int child,int parent)->int{
        int have=0;
        for(auto &i : adj[child]){
            if(vis[i]==1 or i==parent) continue;
            int val=dfs(i,child);
            if(val>=1) have=1;
            ans += val*2;
        }
        if(mp[child]==1 || have==1) return 1;
        return 0;
    };
    dfs(x,0);
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


