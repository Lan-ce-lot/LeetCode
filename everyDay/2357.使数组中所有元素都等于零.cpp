/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums) { 
        unordered_set<int> S;
        for (auto &it : nums) {
            S.emplace(it);
        }
        if (S.count(0)) {
            return S.size() - 1;
        }
        return S.size();
    }
};
// @lc code=end

