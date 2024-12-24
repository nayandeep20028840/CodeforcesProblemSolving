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
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;++i){
        mp[a[i]]+=a[i];
    }
    vector<pair<int,int>>p;
    for(auto &i:mp){
        p.push_back({i.first,i.second});
    }
    sort(p.begin(),p.end());
    int ans=0;
    int val=p[0].first;
    int times=m/val;
    int gotit=times*val;
    ans=min(gotit,p[0].second);
    int rem=0;
    int have=0;
    int run=0;
    if(gotit>=p[0].second){
        rem=m-p[0].second;
        have=p[0].second;
        run=p[0].second/val;
    }
    else{
        run=gotit/val;
    }
    for(int i=1;i<p.size();++i){
        val=p[i].first;
        times=m/val;
        gotit=times*val;
        rem=0;
        ans=max(ans,min(gotit,p[i].second));
        int have=0;
        if(gotit>=p[i].second){
            rem=m-p[i].second;
            have=p[i].second;
            run=p[i].second/val;
        }
        else{
            run=times;
        }
        if(p[i].first-p[i-1].first==1){
            val=p[i-1].first;
            times=rem/val;
            gotit=times*val;
            ans=max(ans,have+min(gotit,p[i-1].second));
            int t=1;
            while(t<=run){
                rem+=t*p[i].first;
                have-=t*p[i].first;
                times=rem/val;
                gotit=times*val;
                ans=max(ans,have+min(gotit,p[i-1].second));
                t+=1;
            }
        }
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