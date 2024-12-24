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
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>suf(n+1,0);
    if(a[n-1]<=x) suf[n-1]=1;
    for(int i=n-2;i>=0;--i){
        if(a[i]<=x){
            suf[i]=suf[i+1]+1;
        }
        else{
            suf[i]=suf[i+1];
        }
    }
    int ans=0;
    int sum=0;
    int prev=0;
    for(int i=0;i<n;++i){
        sum+=a[i];
        while(prev<=i and sum>x){
            ans+=suf[i+1];
            ans+=(i-prev);
            sum-=a[prev];
            prev+=1;
        }
    }
    while(prev<=n-1){
        ans+=(n-prev);
        prev+=1;
    }
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


