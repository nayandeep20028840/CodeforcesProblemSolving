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

const int MOD = 1000000007 ; // 998244353 // 10000000069LL // 3006703054056749LL 
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2}; 
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1}; 

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return ((long long)a / (long long)GCD(a, b) * (long long)b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}

bool solve(){
    string s;
    cin >>s;
    int n=s.size();
    // cout<<n<<nl;
    int j=0;
    map<int,int>mp;
    vector<int>cnt(26,0);
    vector<int>bck(26,0);
    for(int i=0;i<n;++i){
        cnt[s[i]-'a']+=1;
        mp[s[i]-'a']+=1;
    }
    j=mp.size();
    // check1(cnt)
    // cout<<j<<nl;
    int f=0;
    vector<int>vis(26,0);
    string sec="";
    for(int i = n - 1 ; i >= 0 ; --i){
        int ii=i;
        // cout<<ii<<" ";
        vector<int>have(26,0);
        while(ii>=0 and vis[s[ii]-'a']==1){
            have[s[ii]-'a']+=1;
            ii-=1;
        }
        if(ii<0){
            f=1;
            break;
        }
        // check1(have)
        int val = cnt[s[ii]-'a'];
        // cout<<ii<< " " ;
        // cout << val << " " ;
        // cout << j << " ";
        vis[s[ii]-'a']=1;
        sec+=s[ii];
        if(val % j){
            f = 1;
            break;
        }
        int need = val / j;
        // cout<<need<<" ";
        char c = s[ii];
        while(ii>=0){
            have[s[ii]-'a']+=1;
            if(c==s[ii]) need-=1;
            ii-=1;
            if(need==0) break;
        }
        bck[c-'a']=val/j;
        // check1(bck)
        // check1(have)
        while(ii>=0 and have != bck){
            have[s[ii]-'a']+=1;
            ii-=1;
        }
        if(have != bck){
            f=1;
            break;
        }
        // cout<<ii<< " ";
        i=ii+1;
        j-=1;
    }
    // cout<<nl;
    reverse(all(sec));
    // cout<<sec<<nl;
    // check1(bck)
    string first="";
    for(int i=0;i<n;++i){
        if(bck[s[i]-'a'] > 0){
            first += s[i];
            bck[s[i]-'a']-=1;
        }
    }
    // cout<<first<<nl;
    string actual="";
    actual+=first;
    vector<int>vis2(26,0);
    for(int j=0;j<sec.size();++j){
        vis2[sec[j]-'a']=1;
        string add="";
        for(int i=0;i<first.size();++i){
            if(vis2[first[i]-'a']){

            }
            else{
                add+=first[i];
            }
        }
        actual+=add;
    }
    // cout << actual << nl ;
    if(actual != s) cout << -1 << nl ;
    else cout << first << " " << sec << nl ;
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


