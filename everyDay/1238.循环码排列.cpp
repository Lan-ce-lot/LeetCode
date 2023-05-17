/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> tans{0, 1};
        
        int l = (1 << (n - 1));
        for (int i = 2; i <= n; i++) {
            int tm = (1 << (i - 1));
            vector<int> V;
            for (auto it : tans) {
                V.push_back(it + tm);
            }
            reverse(V.begin(), V.end());
            tans.insert(tans.end(), V.begin(), V.end());
        }
        // return tans;
        vector<int> ans;
        int f = -1;
        for (int i = 0; i < tans.size(); i++) {
            if (~f || tans[i] == start) {
                if (f == -1) f = i;
                ans.push_back(tans[i]);
            }
        }
        for (int i = 0; i < f; i++) {
            ans.push_back(tans[i]);
        }
        return ans;
    }
};
// @lc code=end

