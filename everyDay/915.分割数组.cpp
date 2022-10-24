/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int Q[nums.size()];
        int maxx = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i != nums.size() - 1) {
                Q[i] = min(Q[i + 1], nums[i]);
            } else {
                Q[i] = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            maxx = max(maxx, nums[i]);
            if (maxx <= Q[i + 1]) {
                return i + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

