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
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>pf;
    int start=0;
    if(n==1){
        cout<<0<<endl;
        return true;
    }
    for(int i=0;i<n;++i){
        if(a[i]>start){
            pf.push_back(start+1);
            start+=1;
        }
        else if(a[i]==start){
            pf.push_back(start);
        }
        else{
            pf.push_back(start-1);
            start-=1;
        }
    }
    vector<int>sf;
    sf.push_back(a[n-1]);
    for(int i=n-2;i>=0;--i){
        if(a[i]<sf.back()){
            sf.push_back(a[i]);
        }
        else{
            if(sf.back()-1>=1){
                sf.push_back(sf.back()-1);
            }
        }
    }
    reverse(sf.begin(),sf.end());
    int ans=1;
    int idx_start=upper_bound(sf.begin(),sf.end(),0)-sf.begin();
    ans=max(ans,(long long)sf.size()-idx_start);
    for(int i=0;i<n;++i){
        if(pf[i]<0) continue;
        int idx=upper_bound(sf.begin(),sf.end(),pf[i])-sf.begin();
        ans=max(ans,pf[i]+((long long)sf.size()-idx));
    }
    if(ans==n) ans-=1;
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


