#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define int               long long
#define ld                long double
#define vi                vector<int>
#define inputvn           for(int i=0;i<n;++i){int x; cin>>x; v.push_back(x);}
#define yes               cout << " YES" << endl;
#define no                cout << " NO" << endl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.first<<" "<<i.second<<endl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.F<<endl; }
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
    int a , b;
    cin >> a >> b;
    // if(a < b){
    //     if(b%2){
    //         if((a - 1) <= (b / 2)){
    //             cout << a << '\n';
    //         }else{
    //             cout << b / 2 + 1 << '\n';
    //         }
    //     }else{
    //         if((a - 1) <= (b / 2)){
    //             cout << a << '\n';
    //         }else{
    //             cout << (b - 3) / 2 + (a - (b - 3) / 2) / 2 << '\n';
    //         }
    //     }
    // }else{
    //     if(a%2){
    //         if((b - 1) <= (a / 2)){
    //             cout << b << '\n';
    //         }else{
    //             cout << a / 2 + 1 << '\n';
    //         }
    //     }else{
    //         if((b - 1) <= (a / 2)){
    //             cout << b << '\n';
    //         }else{
    //             cout << (a - 3) / 2 + (b - (a - 3) / 2) / 2 << '\n';
    //         }
    //     }
    // }    
    cout << min(a , min(b , (a + b)/3)) << '\n';
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
 
 
 
 
 