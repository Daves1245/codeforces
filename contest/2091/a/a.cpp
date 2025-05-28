#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    vector<int> date = {0, 1, 0, 3, 2, 0, 2, 5};

    auto freq = [](vector<int> &v) -> map<int, int> {
      map<int, int> ret;
      for (int i : v) ret[i]++;
      return ret;
    };

    int i = 0;
    vector<int> cur;
    int flag = 0;
    for (; i < n; i++) {
      flag = 1;
      cur.push_back(v[i]);
      auto f = freq(cur);
      auto g = freq(date);
      for (auto [k, v] : freq(date)) {
        if (f[k] < v) {
          flag = 0;
        }
      }
      if (flag) break;
    }

    if (flag) {
      cout << i + 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
