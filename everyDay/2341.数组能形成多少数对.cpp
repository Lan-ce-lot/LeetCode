/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> M;
        for (int i = 0; i < nums.size(); i++) {
            M[nums[i]]++;
        }
        vector<int> ans(2);
        for (auto [k, v] : M) {
            ans[0] += v / 2;
            ans[1] += v % 2;
        }
        return ans;
    }
};
// @lc code=end

