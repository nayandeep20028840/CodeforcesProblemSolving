#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>  
// #include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
// using namespace __gnu_pbds;  
// typedef tree<int, null_type, less<int>, rb_tree_tag,  tree_order_statistics_node_update>  ordered_set; 
typedef long long ll;
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ff(i, c, n) for (ll i = c; i < n; i++)
#define fr(i, c, n) for (ll i = c; i >= n; --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

// DEBUGGING TEMPLATE
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
const ll mod=1000000007;
const ll mod1=998244353;

ll modpow(ll a, ll b, ll c)
{ //a^b%c in O(logb)
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = (res * a) % c;
		}
		a = (a * a) % c;
		b >>= 1;
	}
	return res;
}
ll modinv(ll m, ll n)
{ //modular inverse of n w.r.t m provided 1<=n<=(m-1) in O(logn) and m is prime
	ll inv[n + 1];
	inv[1] = 1;
	for (int i = 2; i < n + 1; ++i)
		inv[i] = (m - (m / i) * inv[m % i] % m) % m;
	return inv[n];
}



void solve(){
	int n;
	cin >> n;
	vi a(n + 1);
	ff(i, 1, n + 1) cin >> a[i];
	vvll dp(n + 1, vll(n + 1, -1e11));
	dp[0][0] = 0;
	ff(i, 1, n + 1) {
		dp[i][0] = 0;
		ff(j, 1, n + 1) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
			if(dp[i][j] < 0) dp[i][j] = -1e11;
		}
	}
    // for(int i = 0 ; i <= n ; ++i){
    //     for(int j = 0 ; j <= n ; ++j){
    //         cout << dp[i][j] << " " ;
    //     }
    //     cout << endl ;
    // }
	fr(i, n, 0) {
		if(dp[n][i] >= 0) {
			cout << i << endl;
			return;
		}
	}

}

//a+b=a^b+2*(a&b)
int main()
{
#ifndef ONLINE_JUDGE
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#endif

	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	t = 1;
	while(t--){
		solve();
	}


	return 0;
}
