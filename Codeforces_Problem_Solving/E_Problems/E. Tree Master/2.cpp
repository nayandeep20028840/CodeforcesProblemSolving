#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " = " << (x) << endl
#define MOD 1000000007

vector<long long > weight ;
vector<long long > parent ;
long long ans = 0;
vector<unordered_map<int  , long long> > mp; 

long long solve(int  x, int  y) {
    if(x == 0 || y == 0)  {
        return 0;   
    }
    if(x > y) swap(x , y) ;
    if(mp[x].find(y) == mp[x].end()) {
        return mp[x][y] = weight[x] * weight[y] + solve(parent[x], parent[y]) ;
    }
    else{
        return mp[x][y];
    }
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long  n , q;
    cin >> n >> q;
    mp.resize(n + 1) ;
    weight.resize(n + 1) ;
    parent.resize(n + 1) ;
    parent[1] = 0;
    for(long long i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    for(long long i = 2; i <= n; i++) {
        cin >> parent[i];
    }
    int x, y;
    while(q--)  {
        ans = 0;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    
    return 0;
}   