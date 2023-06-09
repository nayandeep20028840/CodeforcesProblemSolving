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
    string s;
    cin >> s;
    int n = s.length();
    int first = (s[0] - '0') + 48 - 96;
    int last = (s[n - 1] - '0') + 48 - 96;
    char last_char = s[n - 1];
    char first_char = s[0];
    int minus = abs(last - first);
    // cout << last << '\n';
    vector<pair<pair< char , int > , int >  > p(n - 2);
    for(int i = 0 ; i < n - 2; ++i){
        p[i].F.F = s[i + 1];
        p[i].F.S = (s[i + 1] - '0') + 48 - 96;
        p[i].S = i + 1 + 1;
    }
    sort(all(p));
    
    vector<int> v;
    int ans = 0;
    v.pb(1);
    int i = 0;
    int sinha = first;
    for(i = 0 ; i < n - 3; ++i){
        if(((sinha - p[i].F.S) <= minus)){
            v.pb(p[i].S);
            ans += abs(sinha - p[i].F.S);
            sinha = p[i].F.S;
        }
    }
    if(n == 2){
        ans += minus;
        v.pb(n);
        cout << ans << " " << v.size() << '\n';
        check1(v)
        return;
    }
    // cout << i << '\n';
    sinha = p[i].F.S;
    // cout << sinha << '\n';
    if((abs(sinha - last) <= minus)){
        v.pb(p[i].S);
        ans += abs(sinha - last);
    }
    v.pb(n);
    cout << ans << " " << v.size() << '\n';
    check1(v)
    return;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt", "w", stderr);
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
 
 
 
 
 