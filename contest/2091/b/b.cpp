#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;
    vector<int> v(n); for (int &i : v) cin >> i;
    sort(v.begin(), v.end());
    int cur = 0, len = 0;
    int teams = 0;
    for (int i = n - 1; i >= 0; i--) {
      len++;
      if (len * v[i] >= x) {
        len = 0;
        teams++;
      }
    }

    cout << teams << endl;
  }
  return 0;
}
