#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        vector<vector<int>> ret;
        int n = nums.size();
        auto go = [&](auto &&self, vector<int> &v, int i) -> void {
            ret.push_back(v);
            // ignore the current element
            self(self, v, i + 1);
            // consider the current element
            v.push_back(nums[i]);
            self(self, v, i + 1);
        };
        vector<int> v;
        go(go, v, 0);
        return ret;
    }
};

int main() {

}
