#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string t; cin >> t;
  ll b = 0, s = 0, c = 0;
  for (char ch : t) {
    b += ch == 'B';
    s += ch == 'S';
    c += ch == 'C';
  }
  ll nb, ns, nc; cin >> nb >> ns >> nc;
  ll pb, ps, pc; cin >> pb >> ps >> pc;
  ll rub; cin >> rub;
  ll z = 0;
  ll ans = 0;
  ll l = 0, r = 1e13;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    ll cb = max(z, b * m - nb) * pb;
    ll cs = max(z, s * m - ns) * ps;
    ll cc = max(z, c * m - nc) * pc;
    ll sum = cb + cs + cc;
    if (sum <= rub) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
