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
template<class T > using pbds_SET = tree< T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_SET<pair<int , int > > s; for pairs
template<class T > using pbds_MULTISET = tree< T , null_type , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_MULTISET<pair<int , int > > s; for pairs

#define nl                "\n"
#define ll                long long
#define int               ll
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

const int MOD = 1000000007 ; // 998244353 // 10000000069LL // 3006703054056749LL 
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2}; 
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1}; 

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor 
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}

string s;
int n;

map<int,int>mp[10];

int rec(int i , string temp , string &str){
    if(i >= n){
        int val = stoi(temp);
        // cout << val << " " ;
        if((val % 25) == 0 and val > 0) return 1 ;
        return 0;
    }
    // if(mp[i].find(stoi(temp)) != mp[i].end()) return mp[i][stoi(temp)];
    int ans = 0;
    if(str[i] != '_'){
        ans += rec(i + 1 , (temp + str[i]) , str);
    }
    else{
        for(int j = 0 ; j <= 9 ; ++j){
            if(i == 0 and j == 0) continue;
            ans += rec(i + 1 , (temp + char(j + '0')) , str);
        }
    }
    return ans;
    // return mp[i][stoi(temp)] = ans;
}

bool solve(){
    cin >> s;
    n = s.size();
    for(int i=0;i<10;++i){
        mp[i].clear();
    }
    if(n == 1){
        if(s[0] == 'X' || s[0] == '_' || s[0] == '0'){
            cout << 1 << nl;
        }
        else{
            cout << 0 << nl ;
        }
        return true;
    }
    if(s[0] == '0'){
        cout << 0 << nl ;
        return 0;
    }
    string temp = s ;
    int ans = 0;
    int cnt = 0 ;
    if(n > 2) ans = 1 ;
    for(int j = 0 ; j < n - 2 ; ++j){
        if(s[j] == 'X') cnt = 1 ;
        else if(s[j] == '_'){
            if(j == 0)  ans *= 9 ;
            else ans *= 10 ;
        }
    }
    if(cnt and s[0] == 'X') ans *= 9 ;
    else if(cnt and s[0] != 'X') ans *= 10 ;
    cnt = 0;
    int ex = 0 ;
    for(int i = 0 ; i <= 9 ; ++i){
        for(int j = n - 2 ; j < n ; ++j){
            if(s[j] == 'X'){
                cnt = 1 ;
                temp[j] = char(i + '0') ;
            }
        }
        if(cnt) ex += rec(n - 2 , "0" , temp) ;
        else break ;
        temp = s;
        for(int i=0;i<10;++i){
            mp[i].clear();
        }
    }
    if(cnt == 0) ex += rec(n - 2 , "0" , temp) ;
    if(ex > 0 and ans > 0) ans += ex - 1 ;
    else if(ex > 0) ans += ex ;
    cout << ans << nl ;
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




