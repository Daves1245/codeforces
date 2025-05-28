
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
class ufds {
  public:
    vi p, size;
    ufds(int n) {
      p.resize(n);
      size = vi(n, 1);
      for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int i) {
      return p[i] == i ? i : p[i] = find(p[i]);
    }
    void join(int a, int b) {
      int x = find(a), y = find(b);
      if (x == y) return;
      if (size[x] < size[y]) {
        p[x] = y;
        size[y] += size[x];
      } else {
        p[y] = x;
        size[x] += size[y];
      }
    }
    int getsize(int x) {
      return size[find(x)];
    }
};
int main() {
  int n, m; cin >> n >> m;
  ufds dsu(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dsu.join(a, b);
  }
  vector<vector<int>> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[ dsu.find(i) ].push_back(i);
  }
  vector<vector<int>> ans;
  vector<vector<int>> twos;
  vector<int> ones;
  for (int i = 0; i < n; i++) {
    if (tmp[i].empty()) continue;
    if (tmp[i].size() > 3) {
      cout << -1 << endl;
      return 0;
    } else if (tmp[i].size() == 3) {
      ans.push_back(tmp[i]);
    } else if (tmp[i].size() == 2) {
      twos.push_back(tmp[i]);
    } else if (tmp[i].size() == 1) {
      ones.push_back(tmp[i][0]);
    }
  }
  if (twos.size() > ones.size()) {
    cout << -1 << endl;
    return 0;
  }
  for (auto &group : twos) {
    if (ones.empty()) {
      cout << -1 << endl;
      return 0;
    }
    vector<int> team = group;
    team.push_back(ones.back());
    ones.pop_back();
    ans.push_back(team);
  }
  if (ones.size() % 3 != 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < ones.size(); i += 3) {
    vector<int> team;
    team.push_back(ones[i]);
    team.push_back(ones[i+1]);
    team.push_back(ones[i+2]);
    ans.push_back(team);
  }
  for (auto &i : ans) for (int j : i) cout << j + 1 << " "; cout << endl;
  return 0;
}
