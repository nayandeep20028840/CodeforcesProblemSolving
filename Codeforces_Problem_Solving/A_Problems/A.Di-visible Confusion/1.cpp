#include<bits/stdc++.h>
using namespace std;

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

#define int               long long
#define ld                long double
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
#define im(a , n , m)     vector<vector<int>>a(n,vector<int>(m)); for(int i=0;i<n;++i){for(int j=0;j<m;++j){cin>>a[i][j];}}
#define yes               cout << "YES" << endl;
#define no                cout << "NO" << endl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.first<<" "<<i.second<<endl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<endl; }
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define bpp               __builtin_popcountll
#define Pi                3.1415926535897932384626
#define endl              "\n"

const int mod97 = 1000000007;
const int modg = 998244353;
const int M  = 1e9+7;
const int N  = 1e5+7;
int fac[N],invfact[N];

int gcd(int a, int b) {if(b == 0){return a;} return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}
//int power(int a, int b ) {int res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
//int powermod(int a, int b, int mod97) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod97; a = (a * a) % mod97; b = b >> 1;} return res;}
string decToBinary(int n){string s=""; int i = 0; while (n > 0) {s = to_string(n % 2)+s;n = n / 2;i++;}return s;}
bool isPowerOfTwo(int n){if(n == 0){return false;} return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}
int power(int x, int y){int res=1; x=x%modg; while(y>0){if(y&1) res=(res*x)%modg; y=y>>1; x=(x*x)%modg;}return res;} 
int modInverse(int n){return power(n, modg - 2);} 
void comp(){fac[0] = 1, invfact[0] = 1; for (int i = 1; i < N; i++){ fac[i] = (fac[i - 1] * i) % modg;invfact[i] = modInverse(fac[i]);}}
int NCR(int n, int r, int p=modg) {if(r<0 || n<0)assert(false);if(n<r) return 0;if (r==0 || r==n)return 1;return(fac[n]*invfact[r]%modg)*invfact[n-r]%modg;}

// how to declare dp vector<vector<int>> dp(n + 1 , vector<int> (3 , -1)) in void solve

bool solve(){
    int n ;
    cin >> n ;
    vector<int> v;
    for(int i = 0 ; i < n ; ++i){
        int x ;
        cin >> x ;
        v.pb(x);
    }
    sort(all(v));
    int count = 0;
    for(int i = n - 1 ; i >= 0 ; --i){
        if(v[i] % (i + 2))
    }
    for(int i = 0 ; i < n ; ++i){
        if(v[i] % (i + 2 - count) == 0){
            no return true;
        }else{
            count++;                           
        }
    }

    yes
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
 
 
 
 
 