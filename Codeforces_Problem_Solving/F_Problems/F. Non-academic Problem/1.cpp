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

int n,m;
vector<vector<int>> adj ; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
vector<int> enter, leave;
int timer;
int timersecond;

void dfs(int v, int p , vector<vector<int>> &bridges) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    enter[v] = timersecond+=1;
    for(int to : adj[v]){
        if(to==p) continue;
        if(visited[to]) {
            low[v] = min(low[v], tin[to]);
        } 
        else{
            dfs(to, v, bridges);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                bridges.push_back({v, to});
            }
        }
    }
    leave[v] = timersecond+=1;
}

void find_bridges() {
    timer = 0;
    timersecond=0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    enter.assign(n, -1);
    leave.assign(n, -1);
    vector<vector<int>> bridges ;
    for (int i = 0; i < n; ++i){
        if (!visited[i]){
            dfs(i, -1, bridges);
        }
    }
    int len=bridges.size();
    int ans=n*(n-1)/2;
    for(int i=0;i<len;++i){
        int u=bridges[i][0];
        int v=bridges[i][1];
        if(tin[u]>tin[v]){
            int n1=(leave[u]-enter[u]+1)/2;
            int n2=n-n1;
            ans=min(ans,n1*(n1-1)/2+n2*(n2-1)/2);
        }
        else{
            int n1=(leave[v]-enter[v]+1)/2;
            int n2=n-n1;
            ans=min(ans,n1*(n1-1)/2+n2*(n2-1)/2);
        }
    }
    cout<<ans<<nl;
}

bool solve(){
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        u-=1;
        v-=1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_bridges();
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


