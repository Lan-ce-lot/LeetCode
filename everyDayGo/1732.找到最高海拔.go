/*
 * @lc app=leetcode.cn id=1732 lang=golang
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
func largestAltitude(gain []int) (res int) {
	res, sum := 0, 0
	for _, i := range gain {
		sum += i
		res = max(res, sum)
	}
	return
}
func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}

// @lc code=end

