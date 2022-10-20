/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution {
public:
    int lowbit(int x) {
        return x & -x;
    }

    int kthGrammar(int n, int k) {
        int c = 0;
        k--;
        while (k) {
            k -= lowbit(k);
            c++;
        }
        return c & 1;
    }
};
// @lc code=end

