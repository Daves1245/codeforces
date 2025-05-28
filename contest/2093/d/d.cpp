#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    vector<vector<int>> base_case = {
      {1, 4},
      {3, 2}
    };
    auto query = [&](auto &&self, ll x, ll y, ll a, ll b, ll c, ll d, int len) -> ll {
      if (len == 1) {
        return base_case[x - a][y - c];
      }
      ll step = 1LL << (len - 1);
      ll area = step * step;
      ll split_x = a + step, split_y = c + step;
      if(x < split_x && y < split_y){
        // top left
        return self(self, x, y, a, split_x, c, split_y, len - 1);
      } else if(x >= split_x && y >= split_y){
        // bottom right
        return area + self(self, x, y, split_x, b, split_y, d, len - 1);
      } else if(x >= split_x && y < split_y){
        // bottom left
        return 2 * area + self(self, x, y, split_x, b, c, split_y, len - 1);
      } else {
        // top right
        return 3 * area + self(self, x, y, a, split_x, split_y, d, len - 1);
      }
    };
    auto gen = [&](auto &&self, ll v, ll a, ll b, ll c, ll d, int len) -> pair<ll, ll> {
      if (len == 1) {
        for (ll i = 0; i < 2; i++) {
          for (ll j = 0; j < 2; j++) {
            if (base_case[i][j] == v) {
              return {a + i + 1, c + j + 1};
            }
          }
        }
      }
      ll step = 1LL << (len - 1);
      ll area = step * step;
      ll split_x = a + step, split_y = c + step;
      if (v <= area) {
        return self(self, v, a, split_x, c, split_y, len - 1);
      } else if (v <= 2 * area){
        return self(self, v - area, split_x, b, split_y, d, len - 1);
      } else if (v <= 3 * area){
        return self(self, v - 2 * area, split_x, b, c, split_y, len - 1);
      } else {
        return self(self, v - 3 * area, a, split_x, split_y, d, len - 1);
      }
    };

    ll base = 1LL << n;
    while (q--) {
      string s; cin >> s;
      if (s == "->") {
        int x, y; cin >> x >> y; x--, y--;
        cout << query(query, x, y, 0, base, 0, base, n) << endl;
      } else if (s == "<-") {
        ll d; cin >> d;
        auto [x, y] = gen(gen, d, 0, base, 0, base, n);
        cout << x << " " << y << endl;
      }
    }
  }
  return 0;
}
