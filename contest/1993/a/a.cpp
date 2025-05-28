#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(4, 0);
    for (char c : s) {
      if (c == '?') {
        continue;
      }
      c -= 'A';
      v[c]++;
      v[c] = min(v[c], n);
    }

    cout << accumulate(v.begin(), v.end(), 0) << endl;
  }
  return 0;
}
