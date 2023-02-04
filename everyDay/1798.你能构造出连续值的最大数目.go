/*
 * @lc app=leetcode.cn id=1798 lang=golang
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
func getMaximumConsecutive(coins []int) int {
	m := 0
	sort.Ints(coins)
	for _, i := range coins {
		if i > m + 1 {
			return m + 1
		}
		m += i
	}
	return m + 1
}
// @lc code=end

