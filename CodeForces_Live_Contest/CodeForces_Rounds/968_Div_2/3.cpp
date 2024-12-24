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
    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0;i<n;++i){
        mp[s[i]]+=1;
    }
    vector<pair<int,char>>p;
    for(auto &i:mp){
        p.push_back({i.second,i.first});
    }
    sort(p.begin(),p.end());
    string ok="";
    for(auto &i:p){
        char c=i.second;
        for(int j=0;j<i.first;++j){
            ok+=c;
        }
    }
    reverse(ok.begin(),ok.end());
    // cout<<ok<<endl;
    int i=0;
    vector<char>ans(n);
    int j=0;
    while(i<n and j<n){
        ans[i]=ok[j];
        i+=2;
        j+=1;
    }
    i=1;
    while(i<n and j<n){
        ans[i]=ok[j];
        i+=2;
        j+=1;
    }
    for(int i=0;i<n;++i){
        cout<<ans[i]<<"";
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


