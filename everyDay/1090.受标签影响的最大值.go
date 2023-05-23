/*
 * @lc app=leetcode.cn id=1090 lang=golang
 *
 * [1090] 受标签影响的最大值
 */

// @lc code=start
func largestValsFromLabels(values []int, labels []int, numWanted int, useLimit int) int {
	// make a new arr to sort
	// sort by idx
	n := len(values)
	idx := make([]int, n)

	m := make(map[int]int)
	for i := 0; i < n; i++ {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		return values[idx[i]] > values[idx[j]]
	})
	sum := 0
	for i := 0; i < n; i++ {
		if numWanted == 0 {
			break
		}
		l := labels[idx[i]]
		v := values[idx[i]]
		if m[l] < useLimit {
			numWanted--;
			m[l]++
			sum += v
		}
	}
	return sum

}
// @lc code=end

