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

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
       cin>>v[i];
    }
    int max_index,min_index;
    int max=v[0],min=v[0];
    for(int i=0;i<n;i++)
    {   
        if(v[i]>=max)
        {
           max=v[i];
           max_index=i+1;
        }
      if(v[i]<=min)
        {
           min=v[i];
           min_index=i+1;
        }
    }
    cout<<min_index<<" "<<max_index<<"\n";
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