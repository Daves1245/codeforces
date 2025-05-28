#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n; vector<int> b(n); for (int &i : b) cin >> i;
  int m; cin >> m; vector<int> g(m); for (int &i : g) cin >> i;

  sort(b.begin(), b.end());
  sort(g.begin(), g.end());

  map<int, int> gf;
  map<int, int> bf;

  for (int i : b) bf[i]++;
  for (int i : g) gf[i]++;

  int sum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = -1; j <= 1; j++) {
      int cand = b[i] + j;
      if (gf[cand]) {
        int tmp = min(bf[b[i]], gf[cand]);
        bf[b[i]] -= tmp;
        gf[cand] -= tmp;
        sum += tmp;
      }
    }
  }

  cout << sum << endl;
  return 0;
}
