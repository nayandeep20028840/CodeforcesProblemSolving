
int n;
vector<vector<int>> adj; // adjacency list of the tree
vector<vector<int>> parent; // parent[i][j] is the 2^j-th ancestor of node i
vector<int> level;
int maxlog = 30; // maximum value of x such that 2^x <= n
vector<int> logValues; // logValues[] is the largest x such that 2^x <= i
vector<bool> visited;

void BinaryLifting(int n, int root){
    parent.resize(n);
    level.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; ++i){
        parent[i].resize(maxlog + 1);
        for (int j = 0; j <= maxlog; ++j){
            parent[i][j] = -1;
        }
    }
    precomputeLogs();
    getLevel(root, -1);
    dfsBinaryLifting(root, visited);
    fillParentTable(root);
}

void fillParentTable(int root){
    int intermediate = -1;
    for (int i = 1; i <= maxlog; ++i){
        for (int j = 0; j < n; ++j){
            intermediate = parent[j][i - 1];
            if (intermediate != -1){
                parent[j][i] = parent[intermediate][i - 1];
            }
        }
    }
}

void dfsBinaryLifting(int root, vector<bool> &visited){
    visited[root] = true;
    for (auto &i: adj[root]){
        if (!visited[i]){
            parent[i][0] = root; // 2^0-th parent of i
            dfsBinaryLifting(i, visited);
        }
    }
}

void getLevel(int root, int parent){
    for (auto &i: adj[root]){ // 
        if (i != parent){
            level[i] = level[root] + 1;
            getLevel(i, root);
        }
    }
}

void precomputeLogs(){
    logValues.resize(maxlog + 1);
    logValues[1] = 0;
    for (int i = 2; i <= maxlog; ++i){
        logValues[i] = logValues[i / 2] + 1;
    }
}

int getLog(int x){ // returns the largest x such that 2^x <= i
    return logValues[x];
}

int kthParent(int start, int k){ // k can be upto 1e9, In this we have only one node and we have to calculate its parent by traversing in powers of 2 
    int a = start;
    while(k > 0){ // k is the distance from the start node
        int x = getLog(k);
        a = parent[a][x]; // 2^x-th parent of a
        if(a == -1){
            return a;
        }
        k -= (1 << x);
    }
    return a;
}

int getLCA(int a, int b){
    if (level[a] > level[b]){
        swap(a, b);
    }
    // for calculating distance multiply by two
    b = kthParent(b, level[b] - level[a]); // kth parent of b at level (level[b] - level[a])
    if (a == b){
        return a;
    }
    for (int i = maxlog; i >= 0; --i){
        if (parent[a][i] != parent[b][i] && parent[a][i] != -1 && parent[b][i] != -1){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}
