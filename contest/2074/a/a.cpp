#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    vector<int> v(4); for (int &i : v) cin >> i;
    int f = 1;
    for (int i : v) f &= i == v[0];
    cout << (f ? "YES" : "NO") << endl;
  }
  return 0;
}
