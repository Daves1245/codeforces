#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; vector<int> a(n), b(n); for (int &i : a) cin >> i; for (int &i : b) cin >> i;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = {a[i], b[i]};
    };

    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) cout << c[i].first << " "; cout << endl;
    for (int i = 0; i < n; i++) cout << c[i].second << " "; cout << endl;
  }
  return 0;
}
