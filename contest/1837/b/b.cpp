#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; string str; cin >> str;
    vector<int> runs;
    int cur = str[0], len = 0;
    for (char c : str) {
      if (c == cur) len++;
      else {
        runs.push_back(len);
        len = 1;
        cur = c;
      }
    }
    runs.push_back(len);
    cout << *max_element(runs.begin(), runs.end()) + 1 << endl;
  }
  return 0;
}
