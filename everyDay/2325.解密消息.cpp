/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution
{
public:
    string decodeMessage(string key, string message) {
        string ans;
        int n = message.size();
        char s[26]{0};
        for (int i = 0, c = 0; i < key.size(); i++) {
            if (key[i] != ' ' && !s[key[i] - 'a']) {
                s[key[i] - 'a'] = c + 'a';
                c++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (message[i] != ' ') {
                ans += s[message[i] - 'a'];
            } else
                ans += ' ';
        }
        return ans;
    }
};
// @lc code=end
