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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxCount = 0, t = s.length();
    int count = 0;
 
    // Traverse string 1 to k
    for(int i = 0; i < t; i++)
    {
         
       // Increment count if
       // character is set bit
       if (s[i] == '1')
           count++;
    }
    int k=3;
    for(int i = k; i < n; i++)
    {
        
       // Remove the contribution of the
       // (i - k)th character which is no
       // longer in the window
       if (s[i - k] == '1')
           count--;
        
       // Add the contribution of
       // the current character
       if (s[i] == '1')
           count++;
            
       // Update maxCount at for
       // each window of size k
       maxCount = max(maxCount, count);
    }
    
    cout << (n-maxCount)*2 << endl;
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