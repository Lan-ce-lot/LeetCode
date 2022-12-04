/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
class Solution {
public:
    int ans = 1000000;
    void dfs(int p, int c, vector<int>& toppingCosts, int target) {
        if (abs(ans - target) < c - target) {
            return;
        } else if (abs(ans - target) >= abs(c - target)){
            if (abs(ans - target) > abs(c - target)) {
                ans = c;
            } else {
                ans = min(ans, c);
            }
        }
        if (p == toppingCosts.size()) return;
        dfs(p + 1, c + toppingCosts[p] * 2, toppingCosts, target); 
        dfs(p + 1, c + toppingCosts[p], toppingCosts, target); 
        dfs(p + 1, c, toppingCosts, target);       
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for (auto it : baseCosts) {
            ans = min(it, ans);
        }
        for (auto it : baseCosts) {
            dfs(0, it, toppingCosts, target);
        }
        return ans;
    }
};
// @lc code=end

