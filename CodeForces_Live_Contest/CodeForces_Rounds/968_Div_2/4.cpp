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
    int n,m;
    cin>>n>>m;
    int mx=0;
    for(int i=0;i<n;++i){
        int l;
        cin>>l;
        map<int,int>mp;
        for(int j=0;j<l;++j){
            int x;
            cin>>x;
            mp[x]+=1;
        }
        int one=0;
        if(mp[0]==0){
            one=1;
            mp[0]=1;
        }
        int start=0;
        while(mp[start]>0){
            start+=1;
            if(mp[start]==0){
                if(one==1) break;
                start+=1;
                one=1;
            }
        }
        mx=max(mx,start);
    }
    int ans=0;
    // cout<<mx<<endl;
    if(m>mx){
        ans+=mx*(mx+1);
        // cout<<ans<<" ";
        ans+=((m*(m + 1)/2) - (((mx)*(mx + 1))/2));
    }
    else{
        ans+=mx*(m+1);
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


