#include<bits/stdc++.h>
using namespace std;

// Policy based data structures(PBDS) C++ STL
// order_of_key(k): returns count of elements strictly smaller than k 
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define ll                long long
#define int               ll
#define ld                long double
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
#define yes               cout << "YES" << endl;
#define no                cout << "NO" << endl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<endl; } 
#define check3(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S<<endl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<endl; }
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define bpp               __builtin_popcountll
#define INF               1000000000000000000
#define Pi                3.1415926535897932384626
#define EPS               1e-9
#define nl                "\n"

const int mod97 = 1000000007 ;
const int modg = 998244353 ;
const int N = 2e1 + 10 ;
int SPF[N] ;
vector<bool > isPrime(N , 1) ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int gcd(int a, int b){if(b == 0){return a;} return gcd(b, a % b);}
int lcm(int a, int b){return (a / gcd(a, b) * b) ;}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
int power(int x, int y){int res = 1 ; while(y > 0) {if(y & 1) res = (res * x) ; x = (x * x) ; y = y >> 1 ;} return res ;}
int powermod(int x, int y){int res = 1; x = x % mod97; while(y > 0){if(y&1) res = (res * x) % mod97; y = y >> 1; x = (x * x) % mod97 ;}return res ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
void prime(){isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}}}
void spf(){for(int i = 0; i <= N; ++i) SPF[i] = i; for(int i = 2; i <= N; ++i) if(SPF[i] == i) for(int j = i; j <= N; j += i) if(SPF[j] == j) SPF[j] = i;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int isqrt(int n){long long x = sqrtl(n);while (x*x>n){--x;} while((x+1) * (x+1)<=n){++x;}return x;}
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
int errichtokabinary(int l,int r,vector<int>&a,int target){int ans=-1; while(l <= r){int mid=(l+(r-l)/2); if(a[mid]==target){ans=mid;return ans;}if(a[mid]<target)l=mid+1;else r=mid-1;}return ans;}
void ncrwithoutmod(int n, int r){long long p = 1, k = 1; if (n-r < r) r = n-r; if (r != 0) {while (r) {p *= n; k *= r; long long m = __gcd(p, k);p /= m; k /= m; n--; r--; }} else cout << p << endl; }
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1} ;
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1} ;

bool solve(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<char > > mat(n + 2 , vector<char > (m + 2 , '#')) ;
    int f = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            cin >> mat[i][j] ;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            f = 0 ;
            int t = 0 ;
            if(mat[i][j] == '*'){
                if(mat[i + 1][j] == '*' && mat[i][j + 1] == '*'){
                    t = 1 ;
                    // for i , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i + 1) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i) && (j + dy[h] == j + 1)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i + 1 , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + 1 + dx[h] == i) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i + 1 + dx[h] == i) && (j + dy[h] == j + 1)){
                            continue ;
                        }
                        if(mat[i + 1 + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i , j + 1
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i) && (j + 1 + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i + 1) && (j + 1 + dy[h] == j)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j + 1 + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                }
                if(!f && t){
                    mat[i][j] = '.' ;
                    mat[i + 1][j] = '.' ;
                    mat[i][j + 1] = '.' ;
                }
                f = 0 ;
                t = 0 ;
                if(mat[i + 1][j] == '*' && mat[i][j - 1] == '*'){
                    t = 1 ;
                    // for i , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i + 1) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i) && (j + dy[h] == j - 1)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i + 1 , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + 1 + dx[h] == i) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i + 1 + dx[h] == i) && (j + dy[h] == j - 1)){
                            continue ;
                        }
                        if(mat[i + 1 + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i , j - 1
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i) && (j - 1 + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i + 1) && (j - 1 + dy[h] == j)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j - 1 + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                }
                if(!f && t){
                    mat[i][j] = '.' ;
                    mat[i + 1][j] = '.' ;
                    mat[i][j - 1] = '.' ;
                }
                f = 0 ;
                t = 0 ;
                if(mat[i - 1][j] == '*' && mat[i][j + 1] == '*'){
                    t = 1 ;
                    // for i , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i - 1) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i) && (j + dy[h] == j + 1)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i - 1 , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i - 1 + dx[h] == i) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i - 1 + dx[h] == i) && (j + dy[h] == j + 1)){
                            continue ;
                        }
                        if(mat[i - 1 + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i , j + 1
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i) && (j + 1 + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i - 1) && (j + 1 + dy[h] == j)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j + 1 + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                }
                if(!f && t){
                    mat[i][j] = '.' ;
                    mat[i - 1][j] = '.' ;
                    mat[i][j + 1] = '.' ;
                }
                f = 0 ;
                t = 0 ;
                if(mat[i - 1][j] == '*' && mat[i][j - 1] == '*'){
                    t = 1 ;
                    // for i , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i - 1) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i) && (j + dy[h] == j - 1)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i - 1 , j
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i - 1 + dx[h] == i) && (j + dy[h] == j)){
                            continue ;
                        }
                        if((i - 1 + dx[h] == i) && (j + dy[h] == j - 1)){
                            continue ;
                        }
                        if(mat[i - 1 + dx[h]][j + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                    // for i , j - 1
                    for(int h = 0 ; h < 8 ; ++h){
                        if((i + dx[h] == i) && (j - 1 + dy[h] == j)){
                            continue ;
                        }
                        if((i + dx[h] == i - 1) && (j - 1 + dy[h] == j)){
                            continue ;
                        }
                        if(mat[i + dx[h]][j - 1 + dy[h]] == '*'){
                            f = 1 ;
                        }
                    }
                }
                if(!f && t){
                    mat[i][j] = '.' ;
                    mat[i - 1][j] = '.' ;
                    mat[i][j - 1] = '.' ;
                }
                f = 0 ;
                t = 0 ;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(mat[i][j] == '*'){
                f = 1 ;
            }
        }
    }
    if(f) no
    else yes
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    freopen("error.txt", "w", stderr);
//#endif 
    int t;
    cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            //count++;
        }else{
            // cout << "NO" << endl;
        }
    }
    return 0;
}
 
 
 
 
// Think twice, code once. // rab ne bana di jodi 