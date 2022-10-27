/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool f = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                f = !f;
            } else if (nums[i] == 0) {
                return 0;
            }
        }
        return f ? 1 : -1;
    }
};
// @lc code=end

