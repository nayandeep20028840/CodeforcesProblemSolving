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
    int n , q;
    cin >> n >> q;
    vector<pair<pair<int,int>,int > > p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i].F.F;
    }
    int maxi = INT_MIN;
    int index = 0;
    for(int i = 0; i < n; ++i){
        if(p[i].F.F > maxi){
            maxi = p[i].F.F;
            index = i;
        }
    }
    for(int i = 0; i < n - 1; ++i){
        if(p[i].F.F > p[i + 1].F.F && (i < index)){
            p[i].F.S = 1;
        }else{
            p[i].F.S = 0;
        }
    }
    while(q--){
        int a , b;
        cin >> a >> b;
        if(a == (index + 1) && b >= (a - 1)){
            if((a - 2 ) >= 0)
            cout << b - (a - 2) << '\n';
            else
            cout << b << '\n';
        }
        else if(a == (index + 1) && b < (a - 1)){
            cout << 0 << '\n';
        }
        else if(b < a - 1){
            cout << 0 << '\n';
        }
        else if(b > (a - 1)){
            cout << p[a - 1].F.S << '\n';
        }
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
 
 
 
 
 