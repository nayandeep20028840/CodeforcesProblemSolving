#include<bits/stdc++.h>
using namespace std;


void dfs(int child , int parent , vector<int > &level , vector<vector<int > > &adj , vector<int > &vis){
    for(auto &i : adj[child]){
        if(i == parent) continue ;
        if(vis[i] == 0){
            vis[i] = 1 ;
            dfs(i , child , level , adj , vis) ;
        }
    }
    if(level[child]) level[parent] += (level[child] ? level[child] : 1) ;
    else if(level[parent]) level[parent] += (level[child] ? level[child] : 1) ;
    else level[parent] = 1 ;
    return ;
}

void solve(){
    int n ;
    cin >> n ;
    vector<vector<int > > adj(n + 10) ;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u , v ;
        cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    int q ;
    cin >> q ;
    vector<pair<int , int > > p ;
    int qq = q ;
    while(q--){
        int x , y ;
        cin >> x >> y ;
        p.push_back({x , y}) ;
    }
    q = qq ;
    vector<int > level(n + 10 , 0) ;
    vector<int > vis(n + 10 , 0) ;
    vis[0] = 1 ;
    vis[1] = 1 ;
    dfs(1 , 0 , level , adj , vis) ;
    // check1(level) ;
    for(int i = 0 ; i < q ; ++i){
        int t = level[p[i].first] ;
        int tt = level[p[i].second] ;
        if(t == 0 && tt) {
            cout << tt << '\n' ;
        }
        else if(t && tt == 0){
            cout << t << '\n' ;
        }
        else if(!t && !tt){
            cout << 1 << '\n' ;
        }
        else {
            cout << t * tt << '\n' ;
        }
    }
    return ;
}

int main(){
    int t ;
    cin >> t ;
    while(t--){
        solve() ;
    }
}