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
    int ans = 0;
    // vector<pair<int,int> p(n);
    vector<pair<int,int> > p(n);
    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;
    int ans4 = 0;
    for(int i=0;i<n;i++){
        cin >> p[i].F;
        cin >> p[i].S;
        if(p[i].F < 0 && p[i].S == 0){
            ans1 = min(p[i].F,ans1);
        }
        if(p[i].F > 0 && p[i].S == 0){
            ans2 = max(p[i].F,ans2);
        }
        if(p[i].F == 0 && p[i].S < 0){
            ans3 = min(p[i].S,ans3);
        }
        if(p[i].F == 0 && p[i].S > 0){
            ans4 = max(p[i].S,ans4);
        }
        ans = abs(ans1)*2 + ans2*2 + abs(ans3)*2 + ans4*2;
    }
    cout << ans << '\n';
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
 
 
 
 
 