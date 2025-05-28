#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    if (s.size() < 3 || stoi(s.substr(0, 2)) != 10) {
      cout << "NO" << endl;
      continue;
    }

    string t = s.substr(2);
    if (stoi(t) < 2 || t[0] == '0') {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
  return 0;
}
