/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // int dp[n + 1]{0};
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

