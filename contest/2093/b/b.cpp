#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;

    int mi = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c != '0') {
        mi = i;
      }
    }

    int ans = 0;
    for (char c : s) {
      if (c != '0') ans++;
    }
    ans--;
    for (int i = s.size() - 1; i > mi; i--) {
      if (s[i] == '0')
        ans++;
    }

    cout << ans << endl;
  }
  return 0;
}
