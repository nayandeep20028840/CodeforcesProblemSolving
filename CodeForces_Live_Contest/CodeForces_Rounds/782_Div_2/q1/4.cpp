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
 
void solve(){
    int n,r,b;
    cin>>n>>r>>b;
    if(r-b==3 || r-b==2 || r-b==1){
        int c=0;
        int c2=1;
        for(int i=0;i<r+b;i++){
            if( c2==0 && c!=b){
                cout<<"B";
                c++;
                c2++;
            }else{
                cout<<"R";
                --c2;
            }
        }
        for(int i=r+b;i<n;i++){
            cout<<"R";
        }
        cout<<endl;
    }
    else if(r/b>3){
        int c=b;
        int d=b+1;
        int h=0;
        while(d){
            if(c==0){
                for(int i=0;i<r/(b+1)+1;i++){
                    cout<<"R";
                }
                break;
            }
            for(int i=0;i<r/(b+1);i++){
                cout<<"R";
                
            }
            while(c){
            cout<<"B";
            --c;
            }
            --d;
        }
        cout<<endl;
    }
    else{
        int c=0;
        int c2=0;
        for(int i=0;i<n;i++){
            
            if(c2%2==0 && c2!=0 && c!=b){
                cout<<"B";
                c++;
                c2=0;
            }else{
                cout<<"R";
                c2++;
            }
        }
        cout<<endl;
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