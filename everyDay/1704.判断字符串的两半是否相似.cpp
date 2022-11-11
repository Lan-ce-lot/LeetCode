/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
class Solution {
public:
    bool halvesAreAlike(string s) {
        int res = 0;
        int n = s.size() / 2;
        unordered_set<char> S{'a','e','i','o','u','A','E','I','O','U'};
        for (int i = 0; i < n; i++) {
            if (S.count(s[i])) {
                res++;
            }
            if (S.count(s[i + n])) {
                res--;
            }
        }
        return res == 0;
    }
};
// @lc code=end

