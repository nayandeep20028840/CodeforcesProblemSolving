#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
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

void solve(){
    int n , m ;
    cin >> n >> m ;
    string s[n];
    for(int i = 0 ; i < n ; ++i){
        cin >> s[i];
    }
    int zero = 0;
    for(int i = 0 ; i < n; ++i){
        for(int j = 0 ; j < m; ++j){
            if(s[i][j] == '1'){
                zero++;
            }
        }
    }
    if(zero == 0){
        cout <<  "YES" << '\n';
        return;
    }
    for(int i = 0 ; i < n - 1; ++i){
        int flag1 = 0;
        int flag2 = 0;
        for(int j = 0 ; j < m ; ++j){
            if(s[i][j] == s[i + 1][j] && s[i][j] == '1' ){
                flag1++;
            }
            if(s[i][j] == '1' &&  s[i + 1][j] == '0'){
                flag2++;
            }
        }
        if(flag2 > 0 && flag1 == 0){
            cout << "YES" << '\n';
            return;
        }
    }
    if(n == 1 || m == 1){
        cout << "YES" << '\n';
        return;
    }
    for(int i = 0 ; i < m - 1; ++i){
        int flag1 = 0;
        int flag2 = 0;
        for(int j = 0 ; j < n; ++j){
            if(s[j][i] == s[j][i + 1] && s[j][i] == '1' ){
                flag1++;
            }
            if(s[j][i] == '1' &&  s[j][i + 1] == '0'){
                flag2++;
            }
        }
        if(flag2 > 0 && flag1 == 0){
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
 
 
 
 
 