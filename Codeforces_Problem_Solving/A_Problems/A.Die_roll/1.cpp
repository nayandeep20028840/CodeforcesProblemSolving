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
    int a,b;
    cin >> a >> b;
    int t=max(a,b);
    int s=(6-t)+1;
    if(s==1) cout << "1/6";
    else if(s==2) cout << "1/3";
    else if(s==3) cout << "1/2";
    else if(s==4) cout << "2/3";
    else if(s==5) cout << "5/6";
    else if(s==6) cout << "1/1";
    else cout << "0/1";
    cout << endl;
}
 