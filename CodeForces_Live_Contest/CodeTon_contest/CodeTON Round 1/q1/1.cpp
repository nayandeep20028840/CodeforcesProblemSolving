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
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define Pi                3.1415926535897932384626
 
void solve(){
    int n,a[n];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(abs((a[i]-a[k])+abs(a[k]-a[j])==abs(a[i]-a[j]))){
                    cout << i << j;
                }
            }
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