#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3")
// #pragma GCC optimize(3, "Ofast", "inline")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int query(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

bool solve()
{
    int n;
    cin >> n;
    DSU dsu(n);
    set<pair<int, int>> p;
    for (int i = 1; i <= n; ++i)
    {
        int ft = (i - 1) % (n);
        int se = i % (n);
        int t = 2;
        while (t > 0)
        {
            if(dsu.same(ft, se)){
                break;
            }
            int val = query(ft+1, se+1)-1;
            int last = se;
            while (val != ft)
            {
                last = val;
                val = query(ft+1, val+1)-1;
                // if(dsu.same(val, ft)) break;
            }
            if (ft < last){
                dsu.mergebysize(ft, last);
                p.insert({ft, last});
            }
            else{
                dsu.mergebysize(last, ft);
                p.insert({last, ft});
            }
            swap(ft, se);
            t -= 1;
        }
    }
    cout << "! " << "";
    for (auto &i : p)
    {
        cout << i.first+1 << " " << i.second+1 << " ";
    }
    cout << endl;
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
