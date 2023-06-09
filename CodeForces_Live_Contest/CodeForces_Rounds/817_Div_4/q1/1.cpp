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
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c1 = 'T';
    char c2 = 'i';
    char c3 = 'm';
    char c4 = 'u';
    char c5 = 'r';
    // char c2 = 'i';
    int ans = 0;
    if(n != 5){
        cout << "NO" << '\n';
        return;
    }
    for(int i = 0; i < 5; ++i){
        if(s[i] == c1){
            ans++;
            break;
        }
    }
    for(int i = 0; i < 5; ++i){
        if(s[i] == c2){
            ans++;
            break;
        }
    }
    for(int i = 0; i < 5; ++i){
        if(s[i] == c3){
            ans++;
            break;
        }
    }
    for(int i = 0; i < 5; ++i){
        if(s[i] == c4){
            ans++;
            break;
        }
    }
    for(int i = 0; i < 5; ++i){
        if(s[i] == c5){
            ans++;
            break;
        }
    }
    if(ans == 5){
        cout << "YES" << '\n';
    }else{
        cout << "NO" << '\n';
    }
    return;
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        //  freopen("output.txt", "w", stdout); 
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
 
 
 
 
 