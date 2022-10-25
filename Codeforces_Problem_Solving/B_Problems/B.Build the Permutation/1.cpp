#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " " << x << '\n';
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define int               long long
#define ld                long double
#define input(v)(n)       for(int i=0;i<n;++i){int x; cin>>x; v.push_back(x);}
#define yes               cout << " YES" << endl;
#define no                cout << " NO" << endl;
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

int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }
int lcm(int a, int b){return (a/gcd(a,b)*b);}
int power(int a, int b ) {int res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
int powermod(int a, int b, int mod97) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod97; a = (a * a) % mod97; b = b >> 1;} return res;}
string decToBinary(int n){string s=""; int i = 0; while (n > 0) {s = to_string(n % 2)+s;n = n / 2;i++;}return s;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}

const int mod97 = 1000000007;
const int modg = 998244353;

void solve(){
    int n , a , b ;
    cin >> n >> a >> b;
    vector<int> v(n);
    for(int i = 0 ; i < n ; ++i){
        v[i] = i + 1;
    }
    if((a + b + 2) > n || (abs(a - b) > 1)){
        cout << -1 << '\n';
    }else{
        if(a > b){
            for(int i = n - 1; i >= (n - (a * 2) ) ; i -= 2){
                swap(v[i] , v[i - 1]);
            }
        }
        else if(a == b) {
            for(int i = 1 ; i < (a * 2) ; i += 2){
                swap(v[i] , v[i + 1]);
            }
        }else{
            for(int i = 0 ; i < (b * 2) ; i += 2){
                swap(v[i] , v[i + 1]);
            }
        }
        check1(v)
    }
    return;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif 
    int t;
    cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }
    return 0;
}
 
 
 
 
 