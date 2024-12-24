#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=2e3+7;
const int mod=998244353;
const double eps=1e-9;
const double pi=    3.14159265358979323846;
using namespace std;  
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    op_set;

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<long long> ar(n);
        for(int i=0;i<n;i++)
            cin >> ar[i];

        vector<long long> dp(n);
        vector<long long>pre(n+1);
        stack<int> s;

        long long curr=0ll;//sum of dp[i] for all j such that ar[j]<ar[i]
        for(int i=0;i<n;i++)
        {
            while(!s.empty())
            {
                if(ar[s.top()]>ar[i])
                {
                    curr=(curr-dp[s.top()]+mod)%mod;
                    s.pop();
                }
                else
                    break;
            }

            if(s.empty())
                dp[i]=1ll;
            else
                dp[i]=curr;

            int from=s.empty()?0:s.top()+1;
            dp[i]=(dp[i]+pre[i]-(from?pre[from]:0ll) +mod )%mod;
            pre[i+1]=(pre[i]+dp[i])%mod;

            curr=(curr+dp[i])%mod;
            s.push(i);
        }

        long long ans=0ll;
        while(!s.empty())
        {
            ans=(ans+dp[s.top()])%mod;
            s.pop();
        }

        cout << ans << "\n";
    }
}

/*
Haan chalte chalte shaam dhal gayi
Dekha jo tujhe toh phir ye baat bangayi
*/