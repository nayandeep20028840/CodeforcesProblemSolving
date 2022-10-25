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

void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<pair<string,string>,pair<int,int>>> p(m);
    for(int i=0;i<m;++i){
        cin >> p[i].F.first;
        cin >> p[i].F.second;
        // p.push_back(make_pair(make_pair(p[i].F.first,p[i].F.second) , make_pair(i,i)));
        p[i].S.F = p[i].F.F.size();
        p[i].S.S = p[i].F.S.size();
    }
    // for(auto i : p){
    //     cout << i.F.F << " " << i.F.S << " " << i.S.F << " " << i.S.S << '\n';
    // }
    vector<string> v;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        // cout << s << '\n';
        for(int j=0;j<m;++j){
            // cout << s << '\n';
            if(s == p[j].F.F){
                if(p[j].S.F <= p[j].S.S){
                    v.pb(p[j].F.F);
                }else{
                    v.pb(p[j].F.S);
                }
                break;
            }
        }
        // cout << s << '\n';
    }
    check1(v)
    return;
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
    int t = 1;
    //cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }

    return 0;
}
 
 
 
 
 