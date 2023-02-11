/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int t = (amount[0] + amount[1]) - amount[2]; 
        if (t <= 0) {
            return amount[2];
        } else {
            return (t + 1) / 2 + amount[2]; 
        }
    }
};
// @lc code=end

