#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

struct DSU {
    int S; 
    struct node {
        int p; int siz; int rnk; // by rank, it's based on the height of the trees, while by size, it's based on the number of elements in the sets. 
        // Merging the smaller tree into the larger one helps maintain a more balanced structure.
    };
    vector<node> dsu; 
    vector<pair<int, node>> history; // Store history for rollback 

    DSU(int n) { 
        S = n; 
        for(int i = 0; i < n; ++i) {
            node tmp; 
            tmp.p = i; tmp.siz = 1; tmp.rnk = 0; 
            dsu.push_back(tmp); 
        }
    }

    void reset(int n) {
        dsu.clear(); 
        S = n; 
        for(int i = 0; i < n; ++i) {
            node tmp; 
            tmp.p = i; tmp.siz = 1; tmp.rnk = 0; 
            dsu.push_back(tmp); 
        }
    }

    int parent(int u) {
        if(dsu[u].p == u) return u;
        dsu[u].p = parent(dsu[u].p); // Time Complexity O(log n)
        return dsu[u].p; 
    }

    void mergebysize(int u, int v) {
        u = parent(u); v = parent(v);
        if(u == v) return;
        if(dsu[u].siz < dsu[v].siz) swap(u , v); 
        history.push_back({u, dsu[u]});
        history.push_back({v, dsu[v]});
        dsu[v].p = u; 
        dsu[u].siz += dsu[v].siz; 
    }

    void mergebyrank(int u, int v) {
        u = parent(u); v = parent(v);
        if(u == v) return;
        history.push_back({u, dsu[u]});
        history.push_back({v, dsu[v]});
        if(dsu[u].rnk < dsu[v].rnk) dsu[u].p = v;
        if(dsu[u].rnk > dsu[v].rnk) dsu[v].p = u;
        if(dsu[u].rnk == dsu[v].rnk) dsu[v].p = u , dsu[u].rnk += 1; 
    }

    void rollback() { // Each union operation typically involves merging two sets (represented by their representatives) into one. Therefore, when rolling back a union operation, you need to undo the changes for both sets involved in that operation.
        if(history.empty()) return; // Nothing to rollback
        auto &i = history.back(); // Retrieve the information about the last union operation
        int u = i.first;
        auto state_u = i.second;
        history.pop_back();
        dsu[u] = state_u;

        if(!history.empty()) {
            pair<int,node> ii = history.back(); // Retrieve the information about the second-to-last union operation
            int v = ii.first;
            node state_v = ii.second; // try to avoid auto because it makes error while using long long
            history.pop_back();
            dsu[v] = state_v;
        }
    }

    bool same(int u, int v) {
        if(parent(u) == parent(v)) return true; 
        return false; 
    }

    int get_size(int u) {
        return dsu[parent(u)].siz; 
    }
};

bool solve()
{
    int n,m;
    cin>>n>>m;
    set<int>s[11];
    vector<vector<int>>vis(11,vector<int>(n+1,0));
    for(int i=1;i<=10;++i){
        for(int j=1;j<=n;j+=i){
            s[i].insert(j);
        }
    }
    for(int i=0;i<m;++i){
        int a,d,k;
        cin>>a>>d>>k;
        while(true){
            auto it=s[d].lower_bound(a);
            int lag=a%d;
            if(it!=s[d].end() and *it<=a+k*d){
                vis[d][*it]=1;
                s[d].erase(it);
            }
            else{
                break;
            }
        }
    }
    DSU dsu(n);
    for(int i=1;i<=10;++i){
        int prev=-1;
        for(int j=1;j<=n;++j){
            if(vis[i][j]){
                if(prev==-1) prev=j;
                else{
                    dsu.mergebysize(prev-1,j-1);
                    prev=j;
                }
            }
        }
    }
    set<int>ans;
    for(int i=0;i<n;++i){
        int val=dsu.parent(i);
        cout<<val<<" ";
        ans.insert(val);
    }
    cout<<endl;
    cout<<ans.size()<<endl;
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


