/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> Q;
        int n = nums.size();
        vector<long> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }
        int res = 0x3f3f3f3f;
        for (int i = 0; i <= n; i++) {
            // end
            while (Q.size() && s[i] - s[Q.front()] >= k) {
                res = min(res, i - Q.front());
                Q.pop_front();
            }
            // head
            while (Q.size() && s[i] <= s[Q.back()]) {
                Q.pop_back();
            }
            Q.push_back(i);
        }
        return res <= n ? res : -1;
    }
};
// @lc code=end

