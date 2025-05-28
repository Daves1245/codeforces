#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    int i1 = 0;
    int i2 = 0;
    while (i1 < n && v[i1] == v[0]) {
      i1++;
    }
    while (i2 < n && v[n - i2 - 1] == v[n - 1]) {
      i2++;
    }

    int res = n;
    if (v[0] == v[n - 1]) {
      res -= i1;
      res -= i2;
    } else {
      res -= max(i1, i2);
    }

    cout << max(0, res) << '\n';
  }
  return 0;
}
