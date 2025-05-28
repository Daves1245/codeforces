#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    set<char> seen;
    for (int i = 0; i < n; i++) {
      if (!seen.count(s[i])) {
        cnt += n - i;
      }
      seen.insert(s[i]);
    }
    cout << cnt << endl;
  }
  return 0;
}
