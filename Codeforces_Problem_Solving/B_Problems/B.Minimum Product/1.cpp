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
    int a , b , x , y , n;
    cin >> a >> b >> x >> y >> n;
    int a1 = a;
    int b1 = b;
    int n1 = n;
    if(a < b){
        if(n <= (a - x)){
            a -= n;
        }else{
            n -= (a - x);
            a = x;
            if(n <= (b - y)){
                b -= n;
            
            }else{
                b = y;
            }
        }
        if(b < a){
            n = n1;
            if(n <= (b1 - y)){
                b1 -= n;
            }else{
                n -= (b1 - y);
                b1 = y;
                if(n <= (a1 - x)){
                    a1 -= n;
                
                }else{
                    a1 = x;
                }
            }
            cout << a1 * b1 << '\n';
            return;
        }
        cout << a * b << '\n';
    }
    else if(b > a){
        if(n <= (b - y)){
            b -= n;
        }else{
            n -= (b - y);
            b = y;
            if(n <= (a - x)){
                a -= n;
            
            }else{
                a = x;
            
            }
        }
        if(a < b){
            n = n1;
            if(n <= (a1 - x)){
                a1 -= n;
            }else{
                n -= (a1 - x);
                a1 = x;
                if(n <= (b1 - y)){
                    b1 -= n;
                
                }else{
                    b1 = y;
                }
            }
            cout << a1 * b1 << '\n';
            return;
        }
        cout << a * b << '\n';
    }else{
        if(y < x){
            if(n <= (b - y)){
                b -= n;
            }else{
                n -= (b - y);
                b = y;
                if(n <= (a - x)){
                    a -= n;
                }else{
                    a = x;
                }
            }
        }
        if(y >= x){
            if(n <= (a - x)){
                a -= n;
            }else{
                n -= (a - x);
                a = x;
                if(n <= (b - y)){
                    b -= n;
                }else{
                    b = x;
                }
            }
        }
        cout << a * b << '\n';
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
 
 
 
 
    