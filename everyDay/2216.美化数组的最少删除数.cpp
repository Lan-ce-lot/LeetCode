/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */

// @lc code=start
class Solution {
#define debug(x) std::cout << #x << ": " << (x) << std::endl

public:
    int minDeletion(vector<int>& nums) {
        int r = 0, n = nums.size();
        if (n == 0) return 0;
        // 相邻合并
        int now = nums[0];
        for (int i = 1; i < n; i++) {
            if ((i - r) % 2 && nums[i] == now) {
                r ++;
            } else {
                if ((i - r) % 2 == 0) {
                    now = nums[i];
                }
            }
        }
        if ((n - r) % 2) {
            r++;
        }
        return r;
    }
};
// @lc code=end

