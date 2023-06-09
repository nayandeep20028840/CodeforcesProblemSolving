#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define int               long long
#define ld                long double
#define vi                vector<int>
#define input(v)(n)       for(int i=0;i<n;++i){int x; cin>>x; v.push_back(x);}
#define yes               cout << " YES" << endl;
#define no                cout << " NO" << endl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.first<<" "<<i.second<<endl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<endl; }
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
int power(int a, int b ) {int res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
int dectobinary(int n){ for(int i=31;i>=0;i--){int k = n >> i;if (k & 1) cout << "1"; else cout << "0";}}

void solve(){
    int n , m , sx , sy , d;
    cin >> n >> m >> sx >> sy >> d;
    int count = 1;
    int count2 = n;
    for(int i = 1; i <= m; ++i){
        if(((abs(sx - count) + abs(sy - i)) <= d) && ((abs(sx - count2) + abs(sy - i)) <= d)){
            cout << -1 << '\n';
            return;
        }
    }
    int count3 = m;
    for(int i = 1; i <= n; ++i){
        if(((abs(sx - i) + abs(sy - count)) <= d) && ((abs(sx - i) + abs(sy - count3)) <= d)){
            cout << -1 << '\n';
            return;
        }
    }
    cout << n + m - 2 << '\n';
    // if(((abs(sx - 2) + abs(sy - 1)) <= d || (abs(sx - 1) + abs(sy - 2)) <= d) && ((abs(sx - (n)) + abs(sy - (m - 1))) <= d || (abs(sx - (n - 1)) + abs(sy - (m))) <= d)){
    //     cout << -1 << '\n';
    // }else{
    //     cout << n + m - 2 << '\n';
    // }
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
 
 
 
 
 