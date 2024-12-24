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
    int n,k;
    cin>>n>>k;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    vector<vector<int>>ans;
    for(int i=0;i<n;i+=k){
        vector<int>v;
        for(int j=0;j<n;j+=k){
            if(a[i][j]=='0'){
                v.push_back(0);
            }
            else{
                v.push_back(1);
            }
        }
        ans.push_back(v);
    }
    for(int i=0;i<n/k;++i){
        for(int j=0;j<n/k;++j){
            cout<<ans[i][j]<<"";
        }
        cout<<endl;
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


