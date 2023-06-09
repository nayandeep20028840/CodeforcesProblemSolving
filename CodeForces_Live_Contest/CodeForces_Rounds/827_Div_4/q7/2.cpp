#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

void solve(){
	int n; cin>>n;
	priority_queue<pi,vector<pi>,less<pi>>pq,Q;
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		pq.push(pi(x,x));
	}
	int OR = 0;
	while(pq.size() && pq.top().first){
		cout<<pq.top().second<<" ";
		OR|=pq.top().second;
		pq.pop();
		while(pq.size()){
			pi cur = pq.top(); pq.pop();
			cur.first-=(cur.first&OR);
			Q.push(cur);
		}
		while(Q.size()){
			pq.push(Q.top());
			Q.pop();
		}
	}
	while(pq.size()){
		cout<<pq.top().second<<" ";
		pq.pop();
	}
	cout<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
}