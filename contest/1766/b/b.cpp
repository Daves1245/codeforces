#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    map<string, int> m;
    int f = 0;
    for (int i = 2; i < n - 1; i++) {
      m[s.substr(i - 2, 2)]++;
      f |= m.count(s.substr(i, 2));
    }

    cout << (f ? "YES" : "NO") << endl;
  }
  return 0;
}
