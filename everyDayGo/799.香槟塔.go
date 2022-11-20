/*
 * @lc app=leetcode.cn id=799 lang=golang
 *
 * [799] 香槟塔
 */

// @lc code=start
func champagneTower(poured int, query_row int, query_glass int) float64 {
	dp := [101][101]float64{}
	dp[0][0] = float64(poured)
	for i := 0; i <= query_row; i++ {
		for j := 0; j <= i; j++ {
			if dp[i][j] >= 1.0 {
				tm := dp[i][j] - 1.0
				dp[i+1][j] += tm / 2.0
				dp[i+1][j+1] += tm / 2.0
				dp[i][j] = 1.0
			}
			if i == query_row && j == query_glass {
				return dp[i][j]
			}
		}
	}
	return dp[query_row][query_glass]
}

// @lc code=end

