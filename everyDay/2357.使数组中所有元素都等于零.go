/*
 * @lc app=leetcode.cn id=2357 lang=golang
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
func minimumOperations(nums []int) int {
	S := map[int]struct{}{}
	for _, i := range nums {
		S[i] = struct{}{}
	}
	if _, ok := S[0]; ok {
		return len(S) - 1
	}
	return len(S)
}
// @lc code=end

