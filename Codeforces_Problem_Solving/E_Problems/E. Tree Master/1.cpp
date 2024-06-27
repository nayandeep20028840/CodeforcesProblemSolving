#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " = " << (x) << endl
#define MOD 1000000007

long long parent[100005];
long long weight[100005];
long long ans = 0;
int n ;
unordered_map<long long, long long> m[100005]; 

long long solve(long long x, long long y) {
    if(x == 0)  {
        return 0;
    }
    
    if(!m[x][y]) {
        m[x][y] = weight[x] * weight[y] + solve(parent[x], parent[y]) ;
    }
    
    return m[x][y];
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long  q;
    cin >> n >> q;
    parent[1] = 0;
    for(long long i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    for(long long i = 2; i <= n; i++) {
        cin >> parent[i];
    }
    long long x, y;
    while(q--)  {
        ans = 0;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    
    return 0;
}