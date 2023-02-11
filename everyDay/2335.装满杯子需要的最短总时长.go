/*
 * @lc app=leetcode.cn id=2335 lang=golang
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
func fillCups(amount []int) int {
	sort.Ints(amount)
	t := (amount[0] + amount[1]) - amount[2]
	if t <= 0 {
		return amount[2]
	} else {
		return amount[2] + (t + 1) / 2
	}
}
// @lc code=end

