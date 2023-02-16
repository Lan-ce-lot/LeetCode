/*
 * @lc app=leetcode.cn id=2341 lang=golang
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
func numberOfPairs(nums []int) []int {
	m := map[int]int{}
	for _, i := range nums {
		m[i]++
	}
	a := []int{0, 0}
	for _, v := range m {
		a[0] += v / 2
		a[1] += v % 2
	}
	return a
}
// @lc code=end

