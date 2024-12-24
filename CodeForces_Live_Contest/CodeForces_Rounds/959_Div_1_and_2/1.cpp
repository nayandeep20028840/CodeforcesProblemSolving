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
    vector<vector<int>>mat(n,vector<int>(m));
    vector<vector<int>>ans(n,vector<int>(m));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mat[i][j]<n*m){
                ans[i][j]=mat[i][j]+1;
            }
            else{
                ans[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(ans[i][j]==mat[i][j]){
                cout<<-1<<endl;
                return true;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<ans[i][j]<<" ";
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


