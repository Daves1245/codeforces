#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (k == 0) {
      string cp = s;
      reverse(cp.begin(), cp.end());
      cout << (s < cp ? "YES" : "NO") << endl;
    } else if (s[0] == s[n - 1]) {
      int f = 0;
      for (char c : s) {
        f |= c != s[0];
      }
      cout << (f ? "YES" : "NO") << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
