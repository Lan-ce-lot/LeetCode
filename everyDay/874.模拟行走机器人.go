/*
 * @lc app=leetcode.cn id=874 lang=golang
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
func robotSim(commands []int, obstacles [][]int) int {
	// 0 1 2 3
	// 10000
	// n e s w
	s := 1
	n := []int{0, 0}
	dir := [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
	h := make(map[int]bool)
	res := 0
	for _, o := range obstacles {
		h[o[0] * 60001 + o[1]] = true
	}
	for i := range commands {
		if commands[i] == -1 {
			s = (s + 1) % 4;
		} else if commands[i] == -2 {
			s = (s + 3) % 4;
		} else {
			for j := 0; j < commands[i]; j++ {
				if h[(n[0] + dir[s][0]) * 60001 + n[1] + dir[s][1]] {
					break
				}
				n[0] += dir[s][0]
				n[1] += dir[s][1]
				res = max(res, n[0] * n[0] + n[1] * n[1])
			}
		}
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
// @lc code=end

