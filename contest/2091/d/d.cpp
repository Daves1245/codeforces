#include <iostream>
using namespace std;
using ll = long long;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = m, ans = m;

    while (l <= r) {
      auto check = [&](ll mid) -> int {
        ll full = m / (mid + 1);
        ll rem = m % (mid + 1);
        ll ma = full * mid + min(rem, mid);
        return n * ma >= k;
      };

      ll mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    cout << ans << endl;
  }

  return 0;
}

