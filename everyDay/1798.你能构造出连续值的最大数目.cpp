/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int m = 0;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] > m + 1) {
                break;
            } else {
                m += coins[i];
            }
        }
        return m + 1;
    }
};
// @lc code=end

