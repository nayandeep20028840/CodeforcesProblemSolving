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
    map<int,int>mp;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mp[a[i]]+=1;
    }
    vector<int>v;
    for(auto &i:mp){
        v.push_back(i.first);
    }
    sort(v.begin(),v.end());
    n=v.size();
    if(n>=3){
        cout<<"NO"<<endl;
        return true;
    }
    if(n == 1){
        cout<<"YES"<<endl;
    }
    else if(v[0]+1==v[1]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
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


