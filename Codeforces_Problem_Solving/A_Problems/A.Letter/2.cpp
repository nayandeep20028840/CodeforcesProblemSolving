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
 
int main(){
    ll i,j,n,m;
    char s[51][51];
    cin>>n>>m;
    while(n && m){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>s[i][j];
            }
        }
        ll minimum_i=n,maximum_i=-1,maximum_j=-1,minimum_j=m;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(s[i][j]=='*'){
                    if(i<minimum_i)  minimum_i=i;
                    if(i>maximum_i)  maximum_i=i;
                    if(j<minimum_j)  minimum_j=j;
                    if(j>maximum_j)  maximum_j=j;
                }
            }
        }
        for(i=minimum_i;i<=maximum_i;i++){
            for(j=minimum_j;j<=maximum_j;j++){
                cout<<s[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
 