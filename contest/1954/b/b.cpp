#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; vector<int> v(n); for (int &i: v) cin >> i;
    vector<int> misfits;
    misfits.push_back(0);
    for (int i = 1; i < n; i++) {
      if (v[i] != v[0]) misfits.push_back(i + 1);
    }
    misfits.push_back(n + 1);
    if (misfits.size() == 2) {
      cout << -1 << endl;
    } else {
      int mi = n;
      for (int i = 0; i < misfits.size() - 1; i++) {
        mi = min(mi, misfits[i + 1] - misfits[i] - 1);
      }
      cout << mi << endl;
    }
  }
  return 0;
}
