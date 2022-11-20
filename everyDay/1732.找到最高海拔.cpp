/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, sum = 0;
        for (int i = 0; i < gain.size(); i++ ) {
            sum += gain[i];
            res = max(sum, res);
        }
        return res;
    }
};
// @lc code=end

