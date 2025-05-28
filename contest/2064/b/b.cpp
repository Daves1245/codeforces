#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    map<int, int> f;
    int ma = 0;
    int la = 0, ra = 0;
    int l = 0;
    for (int i : v) f[i]++;
    for (int r = 0; r < n; r++) {
      if (f[v[r]] == 1) {
        if (r - l + 1 > ma) {
          ma = r - l + 1;
          la = l;
          ra = r;
        }
      } else {
        l = r + 1;
      }
    }

    if (ma) {
      cout << la + 1 << " " << ra + 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
