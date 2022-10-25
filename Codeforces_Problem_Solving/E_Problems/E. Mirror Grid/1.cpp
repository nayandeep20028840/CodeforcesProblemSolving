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
int powermod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
string decToBinary(int n){string s=""; int i = 0; while (n > 0) {s = to_string(n % 2)+s;n = n / 2;i++;}return s;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}

void solve(){
    int n;
    cin >> n;
    char c[n + 1][n + 1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> c[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= (n + 1) / 2; ++i){
        for(int j = 1; j <= (n) / 2; ++j){
            int sum = (c[i][j] - '0') + (c[j][n + 1 - i] - '0') 
            + (c[n + 1 - j][i] - '0') + (c[n + 1 - i][n + 1 - j] - '0');
            if(sum == 0 || sum == 4){
                ans += 0;
            }
            else if(sum == 1 || sum == 3){
                ans += 1;
            }else{
                ans += 2;
            }
        }
    }
    // for(int i = 1; i <= (n + 1) / 2; ++i){
    //     for(int j = i + 1; j <= (n + 1) / 2; ++j){
    //         int sum = (c[j][i] - '0') + (c[i][n + 1 - j] - '0') 
    //         + (c[n + 1 - i][n + 1 - j] - '0') + (c[j][n + 1 - i] - '0');
    //         if(sum == 0 || sum == 4){
    //             ans += 0;
    //         }
    //         else if(sum == 1 || sum == 3){
    //             ans += 1;
    //         }else{
    //             ans += 2;
    //         }
    //     }
    // }
    cout << ans << '\n';
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
 
 
 
 
 