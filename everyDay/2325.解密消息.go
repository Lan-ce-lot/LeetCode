/*
 * @lc app=leetcode.cn id=2325 lang=golang
 *
 * [2325] 解密消息
 */

// @lc code=start
func decodeMessage(key string, message string) (string) {
    cur := byte('a')
    rules := map[rune]byte{}

    for _, c := range key {
        if c != ' ' && rules[c] == 0 {
            rules[c] = cur
            cur++
        }
    }
	m := []byte(message)
    for i, c := range message {
        if c != ' ' {
            m[i] = rules[c]
        }
    }

    return string(m)
}
// @lc code=end

