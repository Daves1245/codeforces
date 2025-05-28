#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;
    int sum = v[0];
    int f = 1;
    vector<int> ans; ans.push_back(sum);
    for (int i = 1; i < n; i++) {
      f &= !v[i] || sum < v[i];
      sum += v[i];
      ans.push_back(sum);
    }
    if (!f) {
      cout << -1 << endl;
    } else {
      for (int i : ans) cout << i << " "; cout << endl;
    }
  }
  return 0;
}
