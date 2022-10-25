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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
    int count[52]{};
    for(int i=0;i<s.length();i++){
        count[s[i]-'a']++;
    }
    
    int c=0;
    for(int i=97;i<123;i++){
        if(count[i-'a']==0){
            c++;
        }
    }
    // int k=0;
    // for(int i=65;i<92;i++){
    //     if(count[i-'a']==0){
    //         k++;
    //     }
    // }
    if(c>0 ) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
 