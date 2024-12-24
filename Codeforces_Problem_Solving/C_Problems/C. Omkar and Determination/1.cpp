#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Policy based data structures(PBDS) C++ STL
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// order_of_key(k): returns count of elements strictly smaller than k 
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T > using Tree_SET = tree< T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_SET<pair<int , int > > s; for pairs
template<class T > using Tree_MULTISET = tree< T , null_type , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_MULTISET<pair<int , int > > s; for pairs

#define nl                "\n"
#define ll                long long
#define int               ll
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
#define yes               cout << "YES" << nl;
#define no                cout << "NO" << nl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<nl;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<nl; } 
#define pb                push_back
#define bpp               __builtin_popcountll
#define inf               1000000000000000000 // 18 zero's
#define Pi                3.1415926535897932384626
#define EPS               1e-9

const int MOD = 1000000007 ; // 998244353 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor 
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int modpower(int x, int y){long long res = 1; x = x % MOD; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2) ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

bool solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>ch(n,vector<char>(m)),vh;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>ch[i][j];
        }
    }
    vh=ch;
    // queue<pair<int,int>>q;
    // vector<vector<int>>vis(n,vector<int>(m,0));
    // for(int i=0;i<n;++i){
    //     if(ch[i][0]=='.') {
    //         vh[i][0]='T';
    //         q.push({i,0});
    //     }
    //     vis[i][0]=1;
    // }
    // for(int j=0;j<m;++j){
    //     if(ch[0][j]=='.') {
    //         vh[0][j]='T';
    //         q.push({0,j});
    //     }
    //     vis[0][j]=1;
    // }
    // vector<int>dx={0,1};
    // vector<int>dy={1,0};
    // while(!q.empty()){
    //     auto coordinates=q.front();
    //     q.pop();
    //     int x=coordinates.F;
    //     int y=coordinates.S;
    //     for(int i=0;i<2;++i){
    //         int nx=x+dx[i];
    //         int ny=y+dy[i];
    //         if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and vh[nx][ny]=='.'){
    //             vis[nx][ny]=1;
    //             vh[nx][ny]='T';
    //             q.push({nx,ny});
    //         }
    //     }
    // }
    // // for(int i=0;i<n;++i){
    // //     for(int j=0;j<m;++j){
    // //         cout<<vh[i][j]<<" ";
    // //     }
    // //     cout<<nl;
    // // }
    vector<int>pf(m+2,0);
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(ch[j-1][i]=='X' and ch[j][i-1]=='X'){
                pf[i]=1;
                break;
            }
        }
    }
    // for(int i=0;i<m;++i){
    //     int f=0;
    //     for(int j=0;j<n;++j){
    //         if(vh[j][i]=='.'){
    //             f=1;
    //             break;
    //         }
    //     }
    //     if(f){
    //         pf[i+1]=1;
    //     }
    // }
    for(int i=1;i<=m;++i){
        pf[i] = pf[i] + pf[i-1];
    }
    int qu;
    cin>>qu;
    while(qu--){
        int x,y;
        cin>>x>>y;
        y-=1;
        x-=1;
        int val=pf[y]-pf[x];
        if(val==0) yes
        else no
    }
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
    int t = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            
        }else{
            
        }
    }
    return 0 ;
}




