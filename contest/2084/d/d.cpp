
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int d = n / m;
        if (d <= k) {
            for (int i = 0; i < n; i++) cout << "0 "; cout << endl;
        } else {
            for (int i = 0; i < n; i++) cout << (i % d) << " "; cout << endl;
        }
    }
    return 0;
}
