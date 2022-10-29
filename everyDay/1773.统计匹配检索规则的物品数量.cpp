/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n = items.size();
        int f;
        if (ruleKey == "type") {
            f = 0;
        } else if (ruleKey == "color") {
            f = 1;
        } else {
            f = 2;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (items[i][f] == ruleValue) {
                res++;
            }
        }
        return res;
    }
};

// @lc code=end

