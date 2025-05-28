#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, m, p, q; cin >> n >> m >> p >> q;
    cout << (!(n % p) ? (m == (n / p) * q) ? "YES" : "NO" : "YES") << endl;
  }
  return 0;
}
