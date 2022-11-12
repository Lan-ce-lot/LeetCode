/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start
class Solution {
public:
    const int m = 1e9 + 7;
    int numTilings(int n) {
        long long dp[4][1005];
        dp[3][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[3][i - 1];
            dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % m;
            dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % m;
            dp[3][i] = ((dp[0][i - 1] + dp[1][i - 1]) % m + dp[2][i - 1] + dp[3][i - 1]) % m;
        }
        return dp[3][n];
    }
};
// @lc code=end

