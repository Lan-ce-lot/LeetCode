/*
 * @lc app=leetcode.cn id=808 lang=cpp
 *
 * [808] 分汤
 */

// @lc code=start
class Solution {
public:
    double soupServings(int n) {
        n = min(int(ceil((double) n / 25)), 200);
        // double dp[n + 4][n + 4];
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
            dp[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] + dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]) / 4.0;

            }
        }
        return dp[n][n];
    }
};
// @lc code=end

