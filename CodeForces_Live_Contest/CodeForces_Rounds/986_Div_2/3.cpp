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
    int n,m,v;
    cin>>n>>m>>v;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int low=-1;
    int high=1e18+1;
    int ans=-1;
    while(high-low>1){
        int mid=(high+low)/2;
        int want=m;
        int f=1;
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=a[i];
            if(sum>=mid and sum>=v){
                if(want>0){
                    want-=1;
                }
                else{
                    f=0;
                }
                sum=0;
            }
            else if(sum>=v and want>0){
                want-=1;
                sum=0;
            }
            else if(sum>=mid and f==1){
                f=0;
                sum=0;
            }
        }
        if(want==0 and f==1) ans=max(ans,0ll);
        if(f==0 and want==0) {
            ans=max(ans,mid);
            low=mid;
        }
        else high=mid;
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


