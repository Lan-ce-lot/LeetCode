/*
 * @lc app=leetcode.cn id=808 lang=golang
 *
 * [808] 分汤
 */

// @lc code=start
func soupServings(n int) float64 {
	n = (n + 24) / 25
	if (n >= 200) {
		n = 200
	}
    dp := make([][]float64, n+1)
    for i := range dp {
        dp[i] = make([]float64, n+1)
    }
	dp[0][0] = 0.5
	for i := 1; i <= n; i++ {
		dp[0][i] = 1.0;
		dp[i][0] = 0;
	}
	for i := 1; i <= n; i++ {
		for j := 1; j<= n; j++ {
			dp[i][j] = (dp[max(i - 4, 0)][j] + dp[max(i - 3, 0)][j - 1] + dp[max(i - 2, 0)][max(j - 2, 0)] + dp[i - 1][max(j - 3, 0)]) / 4.0
		}
	} 
 	return dp[n][n]
}

func max(a int, b int) int {
	if (a > b) {
		return a
	}
	return b
}
// @lc code=end

