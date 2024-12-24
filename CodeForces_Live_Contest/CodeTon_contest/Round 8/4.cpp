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
#define ll                long long // typedef array<int , 2> p ; pair h ye
#define int               ll
#define yes               cout << "YES" << nl ;
#define no                cout << "NO" << nl ;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<nl ;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<nl ; } 
#define pb                push_back
#define bpp               __builtin_popcountll
#define inf               1000000000000000000 // 18 zero's
#define Pi                3.1415926535897932384626
#define EPS               1e-9

const int MOD = 1000000007 ; // 998244353 

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int modpower(int x, int y){long long res = 1; x = x % MOD; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}


bool solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>idx(x);
    for(int i=0;i<x;++i){
        cin>>idx[i];
    }
    sort(all(idx));
    int shift=idx[x-1]-1;
    for(int i=0;i<x-1;++i){
        if(idx[i]+1!=idx[i+1]){
            shift=idx[i]-1;
            break;
        }
    }
    for(int i=0;i<x;++i){
        int num = idx[i]-shift;
        if(num<=0) num += n %= (n+1);
        idx[i]=num;
    }
    sort(all(idx));
    // check1(idx)
    int ans=0;
    if(x==2){
        if(idx[1]-idx[0]==2) ans+=1;
        if(n+1-idx[1]==2) ans+=1;
    }
    else{
        ans=x-2;
        for(int i=1;i<x;++i){
            if(idx[i]-idx[i-1]==2) ans+=1;
        }
        if(n+1-idx[x-1]==2) ans+=1;
    }
    // (diff - 1) / 2
    int three=0;
    vector<pair<int,int>>v;
    for(int i=1;i<x;++i){
        int diff = (idx[i]-idx[i-1]);
        int minus = (idx[i]-idx[i-1]-1)/2;
        if(diff==3){
            three+=1;
        }
        else if(diff>3 and diff % 2==0){
            v.pb({minus,diff-1});
        }
        else if(diff>3 and diff%2){
            three+=minus;
        }
    }
    int diff = (n+1-idx[x-1]);
    int minus = (n+1-idx[x-1]-1)/2;
    if(diff==3){
        three+=1;
    }
    else if(diff>3 and diff % 2==0){
        v.pb({minus,diff-1});
    }
    else if(diff>3 and diff%2){
        three+=minus;
    }
    // check2(v)
    sort(all(v));
    for(int i=0;i<v.size();++i){
        if(y<=0) break;
        if(v[i].F<=y){
            y -= v[i].F;
            ans+=v[i].S;
        }
        else{
            three+=v[i].F;
        }
    }
    if(y<0) y=0;
    ans += min(three,y) * 2;
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


