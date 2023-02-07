/*
 * @lc app=leetcode.cn id=1604 lang=golang
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
func alertNames(keyName []string, keyTime []string) []string {
	M := map[string][]int{}
	for i, _ := range keyName {
		n := keyName[i]
		t := keyTime[i]
		h := int(t[0] - '0') * 10 + int(t[1] - '0')
		m := int(t[3] - '0') * 10 + int(t[4] - '0')
		M[n] = append(M[n], h * 60 + m)
	}
	ans := []string{}
	for k, v := range M {
		sort.Ints(v)
		for i, t :=range v[2:] {
			if t - v[i] <= 60 {
                ans = append(ans, k)
                break
			}
		}
	}
	sort.Strings(ans)
	return ans
}
// @lc code=end

