#include <bits/stdc++.h>

using namespace std;
#define int long long

#ifdef LOCAL
#include "algo/debug.h" 
#else
#define debug(...) 42
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<pair<int, int>> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = {a[i], i};
  }
  sort(b.rbegin(), b.rend());
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cout << a[b[i].second] << ' ';
    bool found = false;
    for (int j = 0; j < 30; j++) {
      if ((cur >> j & 1) == 0 && (b[i].first >> j & 1) == 1) {
        found = true;
      }
    }
    if (cur != (cur | b[i].first)) {
      cur |= b[i].first;
      for (int j = i + 1; j < n; j++) {
        b[j].first &= cur ^ ((1 << 30) - 1);
      }
      sort(b.begin() + i + 1, b.end());
      reverse(b.begin() + i + 1, b.end());
    }
  }

  cout << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc --> 0) solve();
  return 0;
}