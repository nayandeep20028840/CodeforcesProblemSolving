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
    int k,n,m;
    cin >> k >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    vector<int> b(m);
    for(int i=0;i<m;++i){
        cin >> b[i];
    }
    vector<int> v;
    if(n > m){
        for(int i=0;i<m;++i){
            if(a[i] < b[i]){
                v.pb(a[i]);
                v.pb(b[i]);
            }else{
                v.pb(b[i]);
                v.pb(a[i]);
            }
        }
        for(int i=m;i<n;++i){
            v.pb(a[i]);
        }
    }
    if(n < m){
        for(int i=0;i<n;++i){
            if(a[i] < b[i]){
                v.pb(a[i]);
                v.pb(b[i]);
            }else{
                v.pb(b[i]);
                v.pb(a[i]);
            }
        }
        for(int i=n;i<m;++i){
            v.pb(b[i]);
        }
    }
    if(n == m){
        for(int i=0;i<m;++i){
            if(a[i] < b[i]){
                v.pb(a[i]);
                v.pb(b[i]);
            }else{
                v.pb(b[i]);
                v.pb(a[i]);
            }
        }
        // for(int i=m;i<n;++i){
        //     v.pb(a[i]);
        // }
    }
    for(auto i : v){
        if(i == 0){
            k++;
        }else{
            if(k < i){
                cout << -1 << '\n';
                return;
            }
        }
    }
    check1(v)
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
 
 
 
 
 