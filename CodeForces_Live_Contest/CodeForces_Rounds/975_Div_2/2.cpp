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
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    map<int,int>mp;
    for(int i=1;i<n;++i){
        int val=i*(n-i);
        int tot=a[i]-a[i-1]-1;
        mp[val]+=tot;
    }
    for(int i=1;i<=n;++i){
        int val=i*(n-i+1)-1;
        int tot=1;
        mp[val]+=tot;
    }
    while(q--){
        int x;
        cin>>x;
        cout<<mp[x]<<" ";
    }
    cout<<endl;
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


