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
    string s1[n];
    string s2[n];
    string s3[n];
    map<string, int> m;
    for(int i = 0 ; i  <n; ++i){
        cin >> s1[i];
        m[s1[i]]++;
    }
    for(int i = 0 ; i  <n; ++i){
        cin >> s2[i];
        m[s2[i]]++;
    }
    for(int i = 0 ; i  <n; ++i){
        cin >> s3[i];
        m[s3[i]]++;
    }
    // check2(m)
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    for(int i = 0; i < n; ++i){
        if(m[s1[i]] == 1){
            sum1 += 3;
        }
        else if(m[s1[i]] == 2){
            sum1 += 1;
        }else{
            sum1 += 0;
        }
    }
    for(int i = 0; i < n; ++i){
        if(m[s2[i]] == 1){
            sum2 += 3;
        }
        else if(m[s2[i]] == 2){
            sum2 += 1;
        }else{
            sum2 += 0;
        }
    }
    for(int i = 0; i < n; ++i){
        if(m[s3[i]] == 1){
            sum3 += 3;
        }
        else if(m[s3[i]] == 2){
            sum3 += 1;
        }else{
            sum3 += 0;
        }
    }
    cout << sum1 << " " << sum2 << " " << sum3 << '\n';
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
 
 
 
 
 