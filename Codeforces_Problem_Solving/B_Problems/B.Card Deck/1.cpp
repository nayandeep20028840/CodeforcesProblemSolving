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

bool comperator(pair<int,int> a , pair<int,int> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.S < b.S;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int,int> > p(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
        p[i].S = i;
    }
    p[0].F = v[0];
    for(int i=1;i<n;++i){
        p[i].F = max(p[i - 1].F , v[i]);
    }
    sort(all(p) , comperator);
    // check2(p)
    for(auto i : p){
        cout << v[i.S] << " ";
    }
    cout << '\n';
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
 
 
 
 
 