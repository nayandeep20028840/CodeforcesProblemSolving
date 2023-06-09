#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    i64 ans = 0;
    int c0 = 0, c1 = 0;
    int x0 = -1, x1 = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == 0) {
            c0++;
            ans += c1;
            if (x0 == -1) {
                x0 = i;
            }
        } else {
            c1++;
            x1 = i;
        }
    }
    
    i64 res = ans;
    
    if (x0 != -1) {
        ans = std::max(ans, res + c0 - 1 - x0);
    }
    if (x1 != -1) {
        ans = std::max(ans, res + c1 - 1 - (n - 1 - x1));
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}