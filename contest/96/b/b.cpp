#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n; cin >> n;

  vector<string> lucky;
  for (int i = 1; i <= 6; i++) {
    vector<char> tmp;
    for (int j = 0; j < i; j++) {
      tmp.push_back('4');
      tmp.push_back('7');
    }
    sort(tmp.begin(), tmp.end());
    lucky.push_back(string(tmp.begin(), tmp.end()));
    while (next_permutation(tmp.begin(), tmp.end())) {
      lucky.push_back(string(tmp.begin(), tmp.end()));
    }
  }

  vector<ll> ans;
  for (auto s : lucky) ans.push_back(stoll(s));
  cout << *lower_bound(ans.begin(), ans.end(), n) << endl;
  return 0;
}
