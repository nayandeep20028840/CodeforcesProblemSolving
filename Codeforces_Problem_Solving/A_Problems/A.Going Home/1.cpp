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
    vector<vector<int>>cache(5000005,vector<int>(4,0));
    vector<int>ans;
    int f=0;
    int val=-1;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(cache[a[i]+a[j]]==1){
                ans.push_back(i+1);
                ans.push_back(j+1);
                f=1;
                val=a[i]+a[j];
                break;
            }
            cache[a[i]+a[j]]=1;
        }
        if(f) break;
    }
    f=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(a[i]+a[j]==val){
                ans.push_back(i+1);
                ans.push_back(j+1);
                f=1;
                break;
            }
        }
        if(f) break;
    }
    set<int>st(ans.begin(),ans.end());
    if(ans.size() and st.size()==ans.size() and st.size()==4){
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size();++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
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

