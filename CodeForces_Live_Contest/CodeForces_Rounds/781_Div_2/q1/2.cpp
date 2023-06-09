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
    int n;
    cin >> n;
    int a=0,b=1,c=1,d=1;
    int t=__gcd(a,b);
    int t1=(c*d)/__gcd(c,d);
    int t2=a+b+c+d;
    if(a<n){
        if(t==t1 && t2==n){
            cout<<a<<b<<c<<d<<endl;
            return;
        }
        a++;
        if(a==2){
            b++;
            if(t==t1 && t2==n){
                cout<<a<<b<<c<<d<<endl;
                return;
            }
            c++;
            if(t==t1 && t2==n){
                cout<<a<<b<<c<<d<<endl;
                return;
            }
            d++;
            if(t==t1 && t2==n){
                cout<<a<<b<<c<<d<<endl;
                return;
            }
        }
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