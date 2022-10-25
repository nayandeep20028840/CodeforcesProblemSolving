#include <bits/stdc++.h>
#define ll              long long int
#define mod             1000000007
#define inf             1000000000000000001;
#define mp(x,y)         make_pair(x,y)
#define mem(a,val)      memset(a,val,sizeof(a))
#define poss(flag)      cout << (flag ? "YES\n" : "NO\n")
#define lld             long double
#define ull             unsigned long long int
using namespace std;


void yes(){
    cout<<"YES"<<"\n";
}
void no(){
    cout<<"NO"<<"\n";
} 
void solve(){
    ll n;
    cin >> n;
    vector<ll>v(n+1);
    ll x = 0;
    ll y = (n/2);
    
    if(n & 1){
        y++;
    }
    vector<ll>odd,even;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] & 1){
            odd.push_back(i);
        }else{
            even.push_back(i);
        }

    }
    if(n == 1){
        cout<<0<<"\n";
        return;
    }
    
    ll a = odd.size();
    ll b = even.size();
    if(abs(a- b) <= 1){
        if(n % 2 == 0){
            ll x = 0;
            ll i = 0;
            ll y = 0;
            for(auto it:odd){
                x += abs(it - i);
                i += 2;
            }
            i=1;
            for(auto it:odd){
                y += abs(it - i);
                i += 2;
            }
            cout<<min(x,y)<<"\n";
        }else{
            if(a > b){
                ll x = 0,y = 0;
                ll i = 0;
                for(auto it:odd){
                    x += abs(it - i);
                    i += 2;
                }
                i = 1;
                for(auto it:even){
                    y += abs(it - i);
                    i += 2;
                }
                cout<<min(x,y)<<"\n";
            }else{
                ll x = 0,y = 0;
                ll i = 0;
                for(auto it:even){
                    x += abs(it - i);
                    i += 2;
                }
                i = 1;
                for(auto it:odd){
                    y += abs(it - i);
                    i += 2;
                }
                cout<<min(x,y)<<"\n";
            }
        }
        

    }else{
        cout<<-1<<"\n";
    }






}
int main()
{
    ios_base::sync_with_stdio(false);
 
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}