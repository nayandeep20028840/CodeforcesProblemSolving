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
    vector<int>a(n+1);
    vector<vector<int>>adj(n+1);
    vector<int>pos(n+1);
    for(int i=1;i<=n-1;++i){
        cin>>a[i];
        pos[a[i]]=i;
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
    }
    vector<int>p(n+1);
    vector<int>permutaion_pos(n+1);
    for(int i=1;i<=n;++i){
        cin>>p[i];
        permutaion_pos[p[i]]=i;
    }
    set<int>wrong;
    for(int i=1;i<=n;++i){
        int f=0;
        int cur_pos=pos[i];
        int parent =-1;
        if(cur_pos/2>0) parent=a[cur_pos/2];
        int left=-1;
        if(cur_pos*2+1<=n)left=a[cur_pos*2+1];
        int right=-1;
        if(cur_pos*2+2) right=a[cur_pos*2+2];
        if(parent!=-1){
            int idx=permutaion_pos[i];
            if(p[idx-1]!=parent) f=1;
        }
        if(left!=-1){
            int idx=permutaion_pos[i];
            if(p[idx+1]!=left){
                if(p[idx+1]!=right) f=1;
            }
        }
        if(f) wrong.insert(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int idx1=permutaion_pos[p[x]];
        int idx2=permutaion_pos[p[y]];
        int idx3=pos[p[x]];
        int idx4=pos[p[y]];
        permutaion_pos[p[x]]=idx2;
        permutaion_pos[p[y]]=idx1;
        pos[p[x]]=idx4;
        pos[p[y]]=idx3;
        {
            int idx5=pos[p[x]];
            int parent=-1;
            if(idx5/2>0) parent=a[idx5/2];
            int left=-1;
            if(idx5*2+1<=n) left=a[idx5*2+1];
            int right=-1;
            if(idx5*2+2<=n) right=a[idx5*2+2];
            int correct1=0;
            int correct2=0;
            int correct3=0;
            int correct4=0;
            if(parent!=-1){
                if(p[permutaion_pos[parent]-1]!=parent) correct1=1;
            }
            if(left!=-1){
                if(p[permutaion_pos[left]+1]!=left){
                    if(p[permutaion_pos[left]+1]!=right) correct1=1;
                }
            }
            int parent_of_parent=-1;

        }
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


