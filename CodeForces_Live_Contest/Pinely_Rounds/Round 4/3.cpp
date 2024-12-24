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
    vector<int>ans;
    for(int j=1;j<=40;++j){
        int mx=*max_element(a.begin(),a.end());
        if(mx<=40-j){
            break;
        }
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=a[i];
        }
        int val=sum/n;
        for(int i=0;i<n;++i){
            a[i]=abs(a[i]-val);
        }
        ans.push_back(val);
    }
    int mx=*max_element(a.begin(),a.end());
    if(mx+ans.size()>40){
        cout<<-1<<endl;
        return true;
    }
    for(int i=1;i<=mx;++i){
        for(int j=0;j<n;++j){
            a[j]=abs(a[j]-1);
        }
    }
    for(int j=0;j<n;++j){
        if(a[j]>0){
            cout<<-1<<endl;
            return true;
        }
    }
    for(int i=1;i<=mx;++i){
        ans.push_back(1);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
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


