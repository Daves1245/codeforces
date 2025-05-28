#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;

    vector<ll> v(n); for (ll &i : v) cin >> i;
    ll mi = *min_element(v.begin(), v.end());

    vector<ll> multiples;
    int cnt = 0;

    for (ll i : v) {
      if (i % mi == 0) {
        multiples.push_back(i );
        cnt += i == mi;
      }
    }

    if (cnt >= 2) {
      cout << "Yes\n";
      continue;
    }

    if (multiples.size() == cnt) {
      cout << "No\n";
      continue;
    }

    ll d = 0;
    for (ll num : multiples) {
      if (num != mi) {
        d = d == 0 ? (num / mi) : gcd(d, num / mi);
      }
    }

    cout << (d == 1 ? "Yes\n" : "No\n");
  }

  return 0;
}
