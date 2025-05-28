#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i <= (int) (s.size()) - 3; i++) {
      if (i <= (int) (s.size()) - 5) {
        if (s.substr(i, 5) == "mapie") {
          cnt++;
          i += 4;
          continue;
        }
      }
      cnt += s.substr(i, 3) == "pie" || s.substr(i, 3) == "map";
    }
    cout << cnt << endl;
  }
  return 0;
}

