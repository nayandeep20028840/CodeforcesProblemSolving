#include<bits/stdc++.h>
using namespace std;
 
#define ll                long long
#define ld                long double
#define mp                make_pair
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define lb                lower_bound
#define ub                upper_bound
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(dp)          memset(dp,-1,sizeof(dp))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define Pi                3.1415926535897932384626
 
void solve(){
    ll x,y;
    cin >> x >> y;
    if(x==0 && y==0){
        cout << "0" << endl;
    }
    ll c=0;
    for(ll i=1;i<=50;i++){
        if(i*i==(x*x + y*y)){
            c++;
            break;
        }
    }
    if(c==1 && (x!=0 || y!=0)){
        cout << "1" << endl;
    }
    else if(c==0 && (x!=0 || y!=0)){
        cout << "2" << endl;
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
 
 
    int t;
    cin >> t;
 
    while (t--){
        solve();
    }
 
    return 0;
}