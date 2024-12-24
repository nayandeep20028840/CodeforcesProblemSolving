#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, q, t[800008]; 
string s; 
int cnt = 0;

void upd(int v, int l, int r, int i, int x){
    if(l == r - 1){
        t[v] = x;
        return;
    }
    int mid = (l + r) / 2;
    if(i < mid){
        upd(v * 2 + 1, l, mid, i, x);
    }
    else{
        upd(v * 2 + 2, mid, r, i, x);
    }
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int qry(int v, int l, int r, int lq, int rq){
    if(l >= rq || lq >= r){
        return 0;
    }
    if(l >= lq && r <= rq){
        return t[v];
    }
    int mid = (l + r) / 2;
    return qry(v * 2 + 1, l, mid, lq, rq) + qry(v * 2 + 2, mid, r, lq, rq);
}

void solve(){
    cin >> n >> m >> q;
    cin >> s;
    vector<pair<int, int>> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i].first >> v[i].second;
    }
    set<int> unused ;
    for(int i = 1; i <= n; i++){
        unused.insert(i);
    }
    vector<int > used ;
    for(int i = 0; i < m; i++){
        auto lb = unused.lower_bound(v[i].first);
        while(lb != unused.end() && *lb <= v[i].second){
            used.push_back(*lb) ;
            unused.erase(lb);
            lb = unused.lower_bound(v[i].first);
        }
    }
    int cnt = used.size() ;
    map<int,int> mp;
    for(int i=0;i<cnt;i++)
            mp[used[i]]=i;
    
    int outside=0;
    for(int i=1;i<=n;i++)
    {
        if(unused.find(i)!=unused.end() && s[i-1]=='1')
                outside++;
    }
    while(q--){
        int x ;
        cin >> x ;
    }




}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    while(t--){
        solve();
    }
}