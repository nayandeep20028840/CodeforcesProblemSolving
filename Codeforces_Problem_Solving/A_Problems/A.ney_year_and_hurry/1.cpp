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
 
char convertIntToChar(int num) {
char ch = 'a'+num;
return ch;
}
 
const int N = 1e5 + 4;
const int M = 1e9 + 7;
 
void solve(){
    
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);


    int n,k;
    cin >> n >> k;
    int t=240-k;
    int sum=0;
    int count=-1;
    for(int i=1;i<=10;i++){
        if(sum<=t){
            sum += 5*i;
            count++;
        }
    }
    if(count<=n){
        cout << count  << endl;
    }else{
        cout << n << endl;
    }

    return 0;
}