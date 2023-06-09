/// Msaa el 5ra
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i, a, b)  for(int i = a; i < b; i++)
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x,y)
#define popCnt(x) (__builtin_popcountll(x))
#define int ll

using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;

const int N = 1e6 + 5, LG = 18, MOD = (119 << 23) + 1;
const long double PI = acos(-1);
const long double EPS = 1e-7;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void doWork() {

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    // cnt.reserve(n * 4);
    f(i, 0, n) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    sort(all(a));
    a.resize(unique(all(a)) - begin(a));
    int ans = 0;
    for (auto it: cnt)
        ans += it.S * (it.S - 1) * (it.S - 2);
    if (cnt.count(1)) {
        for (auto x: a) {
            if (x * x > 1000000000)break;
            if (x == 1)continue;
            if (cnt.count(x * x))
                ans += cnt[1] * cnt[x] * cnt[x * x];
        }
    }
    for (auto x: a) {
        for (int i = 2; i * i <= x && x * i <= 1000000000; i++) {
            if (x % i == 0) {
                if (cnt.count(x / i) && cnt.count(x * i)) {
                    ans += cnt[x / i] * cnt[x] * cnt[x * i];
                }
                int d = x / i; // 2 4 8 16(64/4) 32(64/2) 64
                if (i != d && x * d <= 1000000000) {
                    ans += cnt[x / d] * cnt[x] * cnt[x * d];
                }
            }
        }
    }

    cout << ans << '\n';

}

int32_t main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE

    int t = 1;
    cin >> t;
    while (t--) {
        doWork();
    }
    return 0;
}

///Look at my code ya codeomk