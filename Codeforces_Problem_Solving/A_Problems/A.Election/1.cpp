#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
const long long int inf = 1e18;
 
#define ll                long long
#define ld                long double
#define mp                make_pair
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define lb                lower_bound
#define ub                upper_bound
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(dp)          memset(dp,-1,sizeof(dp))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define Pi                3.1415926535897932384626
 
char convertIntToChar(int num) {
    char ch = 'a'+num;
    return ch;
}
 
const int N = 1e5 + 4;
const int M = 1e9 + 7;
 
void solve(){
    ll a,b,c;
    
        cin>>a>>b>>c;
        if(a==b && b==c){
            cout<<"1 1 1"<<endl;
            return;
        }
        ll max=0;
        if(a>b && a>c){
            max=a;
        }
        else if(b>c){
            max=b;
        }
        else{
            max=c;
        }
        if(max==a){
            cout<<"0 "<<max-b+1<<" "<<max-c+1<<endl;
        }
        else if(max==b){
            cout<<max-a+1<<" 0"<<" "<<max-c+1<<endl;
        }
        else if(max==c){
            cout<<max-a+1<<" "<<max-b+1<<" "<<"0"<<endl;
        }
    
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
    int t;
    cin >> t;  // long long int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }

    return 0;
}