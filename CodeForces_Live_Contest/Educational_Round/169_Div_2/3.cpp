#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

bool solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int ans=0;
    for(int i=1;i<n;i+=2){
        ans+=a[i-1]-a[i];
    }
    ans-=k;
    ans=max(0ll,ans);
    if(n%2) ans+=a.back();
    cout<<ans<<endl;
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
        {
            
        }
        else
        {
            
        }
    }
    return 0;
}


