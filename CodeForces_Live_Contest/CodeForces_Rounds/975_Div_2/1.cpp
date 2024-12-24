#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
// started late
bool solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int ans=0;
    int mx=0;
    int cnt=0;
    for(int i=0;i<n;i+=2){
        mx=max(mx,a[i]);
        cnt+=1;
    }
    ans=max(ans,cnt+mx);
    cnt=0;
    mx=0;
    for(int i=1;i<n;i+=2){
        mx=max(mx,a[i]);
        cnt+=1;
    }
    ans=max(ans,cnt+mx);
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


