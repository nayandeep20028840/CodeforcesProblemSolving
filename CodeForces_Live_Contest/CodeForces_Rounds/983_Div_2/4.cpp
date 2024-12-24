struct SCC{ // only valid for directed graph // scc_using_kosaraju_algorithm_not_using_tarjan_algorithm 
    vector<vector<int>> edges, redges;
    vector<bool>used;
    vector<int>order, component;
    int n;

    void init(int _n) {
        n = _n;
        edges = vector<vector<int>>(n);
        redges = vector<vector<int>>(n);
        order.clear();
        component.clear();
    }

    void edge(int u, int v){
        edges[u].push_back(v);
        redges[v].push_back(u);
    }

    void dfs1(int v) {
        used[v] = true;
        for (size_t i = 0; i < edges[v].size(); ++i) {
            if (!used[edges[v][i]]) {
                dfs1(edges[v][i]);
            }
        }
        order.push_back(v); // time of exit from the node matters (starting time and finishing time) 
    }

    void dfs2(int v) {
        used[v] = true;
        component.push_back(v);
        for(size_t i = 0; i < redges[v].size(); ++i) {
            if(!used[redges[v][i]]) {
                dfs2(redges[v][i]);
            }
        }
    }

    vector<vector<int>>run(){
        vector<vector<int>>components;
        used.assign(n, false);
        for(int i = 0; i < n; ++i) {
            if(!used[i]) {
                dfs1(i);
            }
        }

        used.assign(n, false);
        for(int i = 0; i < n; ++i){
            int v = order[n - 1 - i];
            if(!used[v]){
                dfs2(v);
                components.push_back(component);
                component.clear();
            }
        }

        return components;
    }

    bool visited(int v){
        return used[v];
    }
    void clear(){
        used.assign(n, false);
    }
};