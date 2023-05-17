/*
 * @lc app=leetcode.cn id=2347 lang=golang
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
func bestHand(ranks []int, suits []byte) string {
    if bytes.Count(suits, suits[:1]) == 5 {
        return "Flush"
    }
    cnt, pair := map[int]int{}, false
    for _, r := range ranks {
        cnt[r]++
        if cnt[r] == 3 {
            return "Three of a Kind"
        }
        if cnt[r] == 2 {
            pair = true
        }
    }
    if pair {
        return "Pair"
    }
    return "High Card"
}
// @lc code=end

