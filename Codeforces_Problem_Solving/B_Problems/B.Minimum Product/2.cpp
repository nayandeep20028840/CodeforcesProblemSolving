#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define int               long long
#define ld                long double
#define vi                vector<int>
#define inputv            for(auto &i : v) cin >> i;
#define yes               cout << " YES" << endl;
#define no                cout << " NO" << endl;
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
    int a , b , x , y , n;
    cin >> a >> b >> x >> y >> n;
    if(x < y){
        if(n > (a - x)){
            n -= (a - x);
            a = x;
            // n -= (a - x);
        }else{
            a -= n;
            n = 0;
        }
        if(n > (b - y)){
            n -= (b - y);
            b = y;
        }else{
            b -= n;
            n = 0;
        }
    }
    else if(x > y){
        if(n > (b - y)){
            n -= (b - y);
            b = y;
            // n -= (a - x);
        }else{
            b -= n;
            n = 0;
        }
        if(n > (a - x)){
            n -= (a - x);
            a = x;
        }else{
            a -= n;
            n = 0;
        }
    }
    else{
        if(a < b){
            if(n > (a - x)){
                n -= (a - x);
                a = x;
                // n -= (a - x);
            }else{
                a -= n;
                n = 0;
            }
            if(n > (b - y)){
                n -= (b - y);
                b = y;
            }else{
                b -= n;
                n = 0;
            }
        }
        else{
            if(n > (b - y)){
                n -= (b - y);
                b = y;
                // n -= (a - x);
            }else{
                b -= n;
                n = 0;
            }
            if(n > (a - x)){
                n -= (a - x);
                a = x;
            }else{
                a -= n;
                n = 0;
            }
        }
    }
    cout << a * b << '\n';
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
 
 
 
 
 