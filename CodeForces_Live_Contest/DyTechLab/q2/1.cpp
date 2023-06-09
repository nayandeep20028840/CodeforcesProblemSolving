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

#define int               long long int
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
const int N  = 1e6;
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


int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;
 
    // Do Binary Search for floor(sqrt(x))
    int start = 1, end = x / 2, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
 
        // If x is a perfect square
        int sqr = mid * mid;
        if (sqr == x)
            return mid;
 
        // Since we need floor, we update answer when
        // mid*mid is smaller than x, and move closer to
        // sqrt(x)
 
        /*
           if(mid*mid<=x)
                   {
                           start = mid+1;
                           ans = mid;
                   }
            Here basically if we multiply mid with itself so
           there will be integer overflow which will throw
           tle for larger input so to overcome this
           situation we can use long or we can just divide
            the number by mid which is same as checking
           mid*mid < x
 
           */
        if (sqr <= x) {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid is greater than x
            end = mid - 1;
    }
    return ans;
}

int dp1[N ];
int dp2[N ];
int dp3[N + 1];

bool solve(){
    int l , r ;
    cin >> l >> r ;
    int count = 0;
    int sum = 0;
    int sum1 = 0;
    if(l < N) {
        sum += dp1[N - 1] - dp1[l - 1];
        if(r < N){
            sum1 += dp1[N - 1] - dp1[r];
            sum -= sum1;
        }
        else if(r >= N && r < (N * N)){
            sum += dp2[r - N];
        }
        else if(r >= (N * N)){
            sum += dp2[N - 1];
            sum += dp3[r - (N * N)];
        }
    }
    else if(l >= N && l < (N * N)){
        sum += dp2[N - 1] - dp2[l - 1];
        if(r >= N && r < (N * N)){
            sum1 += dp2[N - 1] - dp2[r - (N)];
            sum -= sum1;
        }
        else if(r >= (N * N)){
            sum += dp3[r - (N * N)];
        }
    }
    else if(l > (N * N)){
        if(r >= (N * N)){
            sum1 += dp3[N] - dp3[r - (N * N)];
            sum -= sum1;
        }
    }
    cout << sum << endl;
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
    
    dp1[0] = 0;
    dp2[0] = 1;
    dp3[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        int ok = floorSqrt(i);
        if(i % ok == 0){
            dp1[i] = dp1[i - 1] + 1;
        }else{
            dp1[i] = dp1[i - 1];
        }
    }
    for(int i = N + 1 ; i < (N * N) ; ++i){
        int ok = floorSqrt(i);
        if(i % ok == 0){
            dp2[i - N] = dp2[i - 1 - N] + 1;
        }else{
            dp2[i - N] = dp2[i - 1 - N];
        }
    }
    for(int i = (N * N) + 1 ; i <= (N * N * N) ; ++i){
        int ok = floorSqrt(i);
        if(i % ok == 0){
            dp3[i - (N * N)] = dp3[i - 1 - (N * N)] + 1;
        }else{
            dp3[i - (N * N)] = dp3[i - 1 - (N * N)];
        }
    }
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
 
 
 
 
 