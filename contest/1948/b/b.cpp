#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
      if (ans.size() && v[i] > ans.back()) {
        if (v[i] >= 10) {
          ans.push_back(v[i] % 10);
          ans.push_back(v[i] / 10);
        } else {
          ans.push_back(v[i]);
        }
      } else {
        ans.push_back(v[i]);
      }
    }
    reverse(ans.begin(), ans.end());
    cout << (is_sorted(ans.begin(), ans.end()) ? "YES" : "NO") << endl;
  }
  return 0;
}
