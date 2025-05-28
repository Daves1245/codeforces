#include <bits/stdc++.h>
using namespace std;

pair<int,int> tableToReal(int tx, int ty, int pos) {
    int baseX = 3*tx + 1;
    int baseY = 3*ty + 1;
    if (pos == 0) return {baseX, baseY};
    if (pos == 1) return {baseX, baseY+1};
    if (pos == 2) return {baseX+1, baseY};
    return {baseX+1, baseY+1};
}

int tableDist(int tx, int ty) {
    return max(3*tx + 1, 3*ty + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        
        map<pair<int,int>, vector<bool>> tables;
        
        for (int i = 0; i < n; i++) {
            int maxDist = 0;
            pair<int,int> bestTable;
            int bestPos = 0;
            bool found = false;
            
            while (!found) {
                maxDist++;
                for (int tx = 0; tx <= maxDist/3 + 1; tx++) {
                    for (int ty = 0; ty <= maxDist/3 + 1; ty++) {
                        if (tableDist(tx, ty) != maxDist) continue;
                        
                        auto& seats = tables[{tx, ty}];
                        if (seats.empty()) seats = vector<bool>(4, false);
                        
                        int occupied = count(seats.begin(), seats.end(), true);
                        
                        if ((t[i] == 0 && occupied == 0) || 
                            (t[i] == 1 && occupied < 4)) {
                            for (int pos = 0; pos < 4; pos++) {
                                if (!seats[pos]) {
                                    bestTable = {tx, ty};
                                    bestPos = pos;
                                    found = true;
                                    break;
                                }
                            }
                            if (found) break;
                        }
                    }
                    if (found) break;
                }
            }
            
            tables[bestTable][bestPos] = true;
            
            auto [x, y] = tableToReal(bestTable.first, bestTable.second, bestPos);
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}
