

//

#include <bits/stdc++.h>
using namespace std;

int ncr(int n, int r) {
    int ans = 1;
    for (int i = 0; i < (n - r); i++) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

void bfs(int node, vector<int>& vis, vector<int> adj[], int tm) {
    vis[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, 0});
    while (!q.empty()) {
        node = q.front().first;
        int time = q.front().second;
        tm = max(tm, time);

        q.pop();

        // traversal
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                vis[adjacentNode] = 1; // mark visited
                q.push({adjacentNode, time + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(NULL);

    int tt;
    cin >> tt;
    tt += 1 ;
    while (tt--) {
        int n, m;
        cin >> n;
        m = ncr(n, 2);
        vector<int> adj[n + 1]; // 1-based indexing
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // directed graph
        }

        vector<int> king; // array of king nodes

        for (int sn = 1; sn <= n; sn++) {
            int tm = 0;
            vector<int> vis(n + 1, 0); // visited array
            bfs(sn, vis, adj, tm);
            if (tm <= 2 && tm > 0) {
                king.push_back(sn);
            }
        }

        for (auto x : king) {
            cout << x << " ";
        }
        cout << "f" << endl ;
        cout << "\n";
    }

    return 0;
}
// input:
// 1
// 100
// accept nhi ho rah