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
    cin>>n;
    if(n==1){
        cout << 2 << '\n';
        return;
    }
    if(n == 5){
        cout << 2 << '\n';
        return;
    }
    if(n == 8){
        cout << 3 << '\n';
        return;
    }
    if(n == 10){
        cout << 4 << '\n';
        return;
    }
    if( n == 4){
        cout << 2 << '\n';
        return;
    }
    if(n == 2){
        cout << 1 << '\n';
        return;
    }
    if( n == 7){
        cout << 3 << '\n';
        return;
    }
    if(n%3 == 0){
        cout << n/3 << '\n';
    }
    else if(n%3 == 1){
        cout << n/3 + 1 << '\n';
    }
    else if(n%3 == 2) {
        cout << n/3  + 1<< '\n';
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
 
 
 
 
 