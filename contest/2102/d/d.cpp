#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    vector<int> odd, even;
    for (int i = 0; i < n; ++i) {
      ((i & 1) ? odd : even).push_back(v[i]);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    int oi = 0, ei = 0;
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        cout << odd[oi++] << " ";
      } else {
        cout << even[ei++] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
