/*
 * @lc app=leetcode.cn id=1742 lang=golang
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
func cal(a int) (res int) {
	for {
		if a <= 0 {
			break;
		}
		res += a % 10;
		a /= 10;
	}
	return res;
}
func countBalls(lowLimit int, highLimit int) int {
	a := make([]int, 100)
	ma := 0
	for i := lowLimit; i <= highLimit; i++ {
		t := cal(i)
		a[t]++
		if (a[t] > ma) {
			ma = a[t]
		}
	}
	return ma
}
// @lc code=end

