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
    map<int,int> m;
    for(int i=0;i<n;++i){
        cin >> v[i];
        // m[v[i]]++;
    }
    vector<int> pf(n);
    pf[0] = v[0];
    for(int i = 1; i < n; ++i){
        pf[i] = min(pf[i - 1] , v[i]);
    }
    // check1(pf)
    vector<int> sf(n);
    sf[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; --i){
        sf[i] = min(sf[i + 1] , v[i]);
    }
    // check1(sf)
    int count = 0;
    for(int i = n - 1; i >= 0; --i){
        if(v[i] <= sf[i]){
            count++;
        }else{
            break;
        }
    }
    // cout << count << '\n';
    set<int> s;
    for(int i=0;i<n-count;++i){
        m[v[i]]++;
    }
    int index = n - count;
    // check2(m)
    for(int i = n-count; i <= n-1;++i){
        if(m[v[i]] > 0){
            index = i;
            // break;
        }
    }
    // cout << index << '\n';
    for(int i=0;i<index;++i){
        s.insert(v[i]);
    }
    cout << s.size() << '\n';
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
 
 
 
 
 