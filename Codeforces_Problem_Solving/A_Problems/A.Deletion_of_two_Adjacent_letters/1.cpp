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
    string s;
    cin >> s;
    char q;
    cin >> q;
    for(int i=1;i<=s.size();i++){
        int sum=0;int sum1=0;
        if(s[i]=='q'){
            
            for(int j=1;j<i;j++){
                sum += j;
            }
            
            for(int k=i+1;k<s.size();k++){
                sum1 += k;
            }
        }
        if(sum%2==0 && sum1%2==0){
            cout << "YES" << endl;
            return;
        }else{
            cout << "NO" << endl;
            return;
        }
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