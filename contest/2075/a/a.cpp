#include <iostream>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int cnt = 0;
        if (n & 1) {
          if (k & 1) {
            n -= min(n, k);
          } else {
            n -= min(n, k - 1);
          }
          cnt++;
        }

        if (k & 1) {
          cnt += n / (k - 1) + (n % (k - 1) != 0);
        } else {
          cnt += n / k + (n % k != 0);
        }

        cout << cnt << endl;
    }

    return 0;
}
