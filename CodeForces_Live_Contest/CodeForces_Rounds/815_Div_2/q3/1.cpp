#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define int               long long
#define ld                long double
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.first<<" "<<i.second<<endl; } 
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define pii               pair<int,int>
#define bpp               __builtin_popcountll
#define Pi                3.1415926535897932384626
 
int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }
int expo(int a, int b ) {int res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
int dectobinary(int n){ for(int i=31;i>=0;i--){int k = n >> i;if (k & 1) cout << "1"; else cout << "0";}}

void solve(){
    int n , m;
    cin >> n >> m;
    string s[n];
    for(int i = 0 ; i < n; ++i){
        cin >> s[i];
    }
    int zero = 0;
    int one = 0;
    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '0'){
                zero++;
            }
            else if(s[i][j] == '1'){
                one++;
            }
        }
    }
    // cout << zero << " " << one << '\n';
    if(zero == 0){
        cout << one - 2 << '\n';
        return;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m - 1; ++j){
            if(s[i][j] == '0'){
                if(s[i][j] == s[i][j + 1]){
                    count++;
                }
            }
        }
    }
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '0'){
                if(s[i][j] == s[i + 1][j]){
                    count++;
                }
            }
        }
    }
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < m - 1; ++j){
            if(s[i][j] == '0'){
                if(s[i][j] == s[i + 1][j + 1]){
                    count++;
                }
            }
        }
    }
    for(int i = 0; i < n - 1; ++i){
        for(int j = 1; j < m; ++j){
            if(s[i][j] == '0'){
                if(s[i][j] == s[i + 1][j - 1]){
                    count++;
                }
            }
        }
    }
    // cout << count << '\n';
    if(count > 0){
        cout << one << '\n';
    }
    else if(one > 0){
        cout << one - 1 << '\n';
    }else{
        cout << 0 << '\n';
    }
    return;
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
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
 
 
 
 
 