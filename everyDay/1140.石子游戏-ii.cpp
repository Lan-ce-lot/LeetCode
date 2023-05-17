/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int dp[101][30];
        memset(dp, -1, sizeof(dp)); // -1 表示没有访问过
        // houzui
        // int s[101];
        for (int i = piles.size() - 2; i >= 0; i--) {
            piles[i] = piles[i + 1] + piles[i];
        }

        function<int(int, int)> dfs = [&](int i, int m) -> int {
            if (i + m * 2 >= piles.size()) return piles[i];
            int mm = INT_MAX;
            int &res = dp[i][m];
            if (res != -1) return res;

            for (int j = 1; j <= m * 2; j++) {
                mm = min(mm, dfs(i + j, max(m, j)));
            }
            return res = piles[i] - mm;
            // return dfs(0, 1);
        };
        return dfs(0, 1);
    }
};
// @lc code=end

