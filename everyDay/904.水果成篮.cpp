/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 1;
        unordered_map<int, int> M;
        int l = 0, r = 0;
        for (; r < fruits.size(); r++) {
            M[fruits[r]]++;
            while (M.size() > 2) {
                M[fruits[l]]--;
                auto it = M.find(fruits[l]);
                if (M[fruits[l]] == 0) {
                    M.erase(it);
                }
                l++; 
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end

