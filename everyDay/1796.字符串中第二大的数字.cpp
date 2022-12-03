/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
class Solution {
public:
    int secondHighest(string s) {
        int ma = -1, se = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (s[i] > ma) {
                    se = ma;
                    ma = s[i];
                } else if (s[i] < ma && s[i] > se) {
                    se = s[i];
                }
            }
        }
        return ~se ? se - '0' : se;
    }
};
// @lc code=end

