#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    int a = 0, b = 0;
    for (int i : v) (i & 1) ? a++ : b++;
    if (!b) a -= 2;
    cout << a + 1 << endl;
  }
  return 0;
}
