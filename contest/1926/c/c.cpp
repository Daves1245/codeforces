#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> nums(2e5 + 10);
vector<ll> ps(2e5 + 11, 0);
void init() {
  for (int i = 0; i < nums.size(); i++) {
    int n = i;
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }
    nums[i] = sum;
    ps[i + 1] = ps[i] + nums[i];
  }
}
int main() {
  init();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; cout << ps[n + 1] << endl;
  }
  return 0;
}
