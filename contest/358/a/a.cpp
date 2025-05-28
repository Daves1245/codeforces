#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;
  int f = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int a = v[i], b = v[i + 1];
      int c = v[j], d = v[j + 1];

      if (a > b) swap(a, b);
      if (c > d) swap(c, d);

      f |= a < c && c < b && b < d;
      f |= c < a && a < d && d < b;
    }
  }
  cout << (f ? "yes" : "no") << endl;
  return 0;
}
