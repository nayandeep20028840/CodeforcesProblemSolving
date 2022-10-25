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
// int dectobinary(int n){ for(int i=31;i>=0;i--){int k = n >> i;if (k & 1) cout << "1"; else cout << "0";}}

void solve(){
    int n;
    cin>>n;
    vector<int> v;
    vector<int> v1;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        v.pb(x);
        v1.pb(x);
    }
    sort(all(v1));
    vector<pair<pair<int,int>,int> > ans;
    for(int i=0;i<n;++i){
        if(v[i] == v1[i])
        continue;
        int index = 0;
        for(int j=i+1;j<n;++j){
            if(v1[i] == v[j]){
                index = j;
                break;
            }
        }
        ans.pb({{i+1,n},index - i});    
        vector<int> v2 = v;
        for(int k=index;k>=i+1;k--)
                    v[k]=v[k-1];
        check1(v)
    }
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i.F.F << " " << i.F.S << " " << i.S << '\n';
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
 
 
 
 
 