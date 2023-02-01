#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Calculate the original sum of the segment [l, r]
        long long seg_sum = 0;
        for (int i = l - 1; i < r; ++i) {
            seg_sum += a[i];
        }

        long long difference = 0;

        // === Left pass ===
        int i = l - 1;  // 0-based index for position l
        int j = l - 2;  // position l-1 in 0-based index
        while (i < r && j >= 0) {
            if (a[j] < a[i]) {
                difference += (a[i] - a[j]);
                ++i;
                --j;
            } else {
                --j;
            }
        }

        // === Right pass ===
        i = r - 1;  // 0-based index for position r
        int j = i + ;  // position r+1 in 0-based index
        while (i >= (l - 1) && j < n) {
            if (a[j] < a[i]) {
                difference += (a[i] - a[j]);
                --i;
                ++j;
            } else {
                ++j;
            }
        }

        // The minimum sum after the single reversal:
        long long ans = seg_sum - difference;
        if (ans < 0) {
            ans = 0;
        }

        cout << ans << endl;
    }

    return 0;
}

