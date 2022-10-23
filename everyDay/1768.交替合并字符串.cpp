/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int i1 = 0, i2 = 0;
        while (i1 < word1.size() || i2 < word2.size()) {
            if (i1 < word1.size()) {
                s += word1[i1++];
            }
            if (i2 < word2.size()) {
                s += word2[i2++];
            }
        } 
        return s;
    }
};
// @lc code=end

