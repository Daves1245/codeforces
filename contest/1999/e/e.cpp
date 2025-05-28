#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 200000 + 11;

vector<ll> ps(N, 0);
vector<ll> steps(N);
void init() {
  for (int i = 0; i < steps.size(); i++) {
    int cur = 0;
    int n = i;
    while (n) {
      cur++;
      n /= 3;
    }
    steps[i] = cur;
    ps[i + 1] = ps[i] + steps[i];
  }
}
int main() {
  int t; cin >> t;
  init();
  while (t--) {
    int l, r; cin >> l >> r;
    cout << steps[l] + ps[r + 1] - ps[l] << endl;
  }
  return 0;
}
