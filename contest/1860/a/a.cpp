#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        string a = "", b = "";

        for (int i = 0; i < n; i++) {
            a += "()";
            b += "(";
        }
        for (int i = 0; i < n; i++) b += ")";

        auto af = a.find(s), bf = b.find(s);
        if (af != string::npos) {
            cout << "YES" << endl;
            cout << a << endl;
            continue;
        }
        if (bf != string::npos) {
            cout << "YES" << endl;
            cout << b << endl;
            continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}
