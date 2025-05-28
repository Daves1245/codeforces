#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int mid = (n - 1) / 2;
    int a = abs(v[0]);
    int cnt = 0;
    for (int i = 1; i < n; i++) {
      if (abs(v[i]) > a) cnt++;
    }
    cout << (cnt >= mid ? "YES" : "NO") << endl;
  }
  return 0;
}
