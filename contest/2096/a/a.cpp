#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (char c : s) cnt += c == '<';
    cnt++;
    int l = cnt - 1, r = cnt + 1;
    cout << cnt << " ";
    for (char c : s) {
      if (c == '<') {
        cout << l-- << " ";
      } else {
        cout << r++ << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
