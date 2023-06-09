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
    int n,h,m;
    cin>>n>>h>>m;
    vector<pair<int,int> > p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].F;
        cin>>p[i].S;
    }
    sort(all(p));
    int ans = 0;
    int ans1 = 0;
    if(h>p[0].F){
        if(p[n-1].F >= h && p[n-1].S >= m){
            ans = p[n-1].F - h;
            ans1 = p[n-1].S - m;
        }
        else if(p[n-1].F > h && p[n-1].S < m){
            ans = p[n-1].F - h - 1;
            ans1 = 60 - m + p[n-1].S;
        }else{
            ans = 23 - h;
            ans1 += 59 - m + 1;
            ans += p[0].F ;
            ans1 += p[0].S;
        }
    }
    else if(h<p[0].F){
        if(p[0].S < m)
        ans = p[0].F - h - 1;
        else
        ans = p[0].F - h;
        ans1 += 59 - m + 1;
        ans1 += p[0].S;
    }else{
        ans = 0;
        if(p[0].S >= m){
            ans = 0;
            ans1 = (p[0].S - m);
        }else{
            
        }
    }
    if(ans1<0){
        ans1 = 0;
    }
    if(ans<0){
        ans = 0;
    }
    if(ans1 > 59){
        ans += (ans1/60);
        ans1 = ans1 - 60*((ans1/60));
    }
    cout<< ans <<" "<<ans1<<'\n';
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
 
 
 
 
 