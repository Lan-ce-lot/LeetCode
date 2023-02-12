/*
 * @lc app=leetcode.cn id=1138 lang=golang
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
func alphabetBoardPath(target string) string {
	a := []byte{}
	x, y := 0, 0
	for _, i := range target {
		tx := int(i - 'a') % 5
		ty := int(i - 'a') / 5
		if tx == x && ty == y {
			a = append(a, '!')
		} else {
			if (ty - y < 0) {
				for j := 0; j < y - ty; j++ {
					a = append(a, 'U')
				}
			}
			if (tx - x < 0) {
				for j := 0; j < x - tx; j++ {
					a = append(a, 'L')
				}
			}
			if (tx - x >= 0) {
				for j := 0; j < tx - x; j++ {
					a = append(a, 'R')
				}
			}
			if (ty - y >= 0) {
				for j := 0; j < ty - y; j++ {
					a = append(a, 'D')
				}
			}
			a = append(a, '!')
		}
		x , y = tx, ty
	}
	return string(a)
}
// @lc code=end

