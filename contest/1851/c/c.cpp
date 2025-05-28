#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k; vector<int> v(n); for (int &i : v) cin >> i;
    if (v[0] == v[n - 1]) {
      cout << (count(v.begin(), v.end(), v[0]) >= k ? "YES" : "NO") << endl;
    } else {
      int l = 0, r = n - 1;
      int lc = 0, rc = 0;
      while (l < r && !(lc >= k && rc >= k)) {
        if (v[l] == v[0]) lc++;
        if (v[r] == v[n - 1]) rc++;
        if (lc < k) l++;
        if (rc < k) r--;
      }
      if (n & 1) {
        lc += v[l] == v[0];
        rc += v[r] == v[n - 1];
      }
      cout << (rc >= k && lc >= k ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
