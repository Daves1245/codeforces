#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int ma = 0;
    for (inti i = 0; i  <n; i++) {
      ma = max(s[i], ma);
    }

    cout << ma << endl;
  }
  return 0;
}
