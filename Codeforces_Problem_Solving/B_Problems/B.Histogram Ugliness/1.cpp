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
#define bpp               __builtin_popcount
#define Pi                3.1415926535897932384626
 
int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }
int expo(int a, int b ) {int res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
int dectobinary(int n){ for(int i=31;i>=0;i--){int k = n >> i;if (k & 1) cout << "1"; else cout << "0";}}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    if(n == 1){
        cout << v[0] << '\n';
        return;
    }
    int dollar = 0;
    int dollar1 = 0;
    int dollar2 = 0;
    if(n > 1){
        if(v[0] > v[1]){
            dollar1 = v[0] - v[1];
            v[0] = v[0] - dollar1;
        }
        if(v[n - 1] > v[n - 2]){
            dollar2 = v[n - 1] - v[n - 2];
            v[n - 1] = v[n - 1] - dollar2;
        }
    }
    dollar += dollar1 + dollar2;
    for(int i=1;i<n-1;++i){
        if(v[i] > v[i - 1] && v[i] > v[i+1]){
            dollar += v[i] - max(v[i - 1] , v[i + 1]);
            v[i] = max(v[i - 1] , v[i + 1]);
        }
    }
    // cout << dollar << '\n';
    // check1(v)
    int ans = v[0] + v[n - 1];
    for(int i=0;i<n-1;++i){
        if(v[i + 1] > v[i]){
            ans += v[i + 1] - v[i];
        }
        if(v[i + 1] < v[i]){
            ans += v[i] - v[i + 1];
        }
        // cout << ans << '\n';
    }
    cout << dollar + ans << '\n';
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
 
 
 
 
 