
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n); for (int &i : v) cin >> i;
        string str; cin >> str;
        vector<int> ids(n + 1, 0);
        vector<int> sizes;
        int id = 0;
        for (int i = 0; i < n; i++){
            if (ids[v[i]] == 0){
                id++;
                int cur = v[i];
                int len = 0;
                while (ids[cur] == 0) {
                    ids[cur] = id;
                    len += str[i - 1] == '1';
                    cur = v[cur - 1];
                }
                sizes.push_back(len);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << sizes[ids[v[i]] - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}
