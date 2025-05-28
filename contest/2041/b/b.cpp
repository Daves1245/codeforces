#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;

    auto check = [&](ll m) -> bool {
      return m * (m + 1) / 2 <= a + b;
    };

    ll l = 0, r = 1e9, m;
    ll ans = -1;
    while (l <= r) {
      m = (l + r) / 2;
      // cout << endl << "a " << a << " b " << b << " m " << m << endl << endl;
      if (check(m)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
