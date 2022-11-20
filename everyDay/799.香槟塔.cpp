/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101]{0};
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j= 0; j <= i; j++) {
                if (dp[i][j] >= 1.0) {
                    double lu = dp[i][j] - 1.0;
                    dp[i + 1][j] += lu / 2.0, dp[i + 1][j + 1] += lu / 2.0;
                    dp[i][j] = 1.0;
                }
                if (i == query_row && j == query_glass) {
                    return dp[query_row][query_glass];
                }
            }
        }
        return dp[query_row][query_glass];
    }
};
// @lc code=end

