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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
char convertIntToChar(int num) {
    char ch = 'a'+num;
    return ch;
}
 
void binaryform(int num){
    for (int i = 10;i >= 0;--i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
 
void left_right_shift(int num){
    cout << (num>>1) << endl; //if num=5(101) it will return 2(10)
    cout << (num<<1) << endl; //if num=5(101) it will return 10(1010)
}
 
const int N = 1e5 + 4;
const int M = 1e9 + 7;
 
int main(){
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]<s[i+1]){
            swap(s[i],s[i+1]);
            if(t-1==i){
                break;
            }
        }
    }
    cout<<s<<endl;
}
 