#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> v(n); for (int &i : v) cin >> i;
  cout << *max_element(v.begin(), v.end()) << endl;
  return 0;
}
