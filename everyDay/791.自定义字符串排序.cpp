/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> M;
        for (int i = 0; i < order.size(); i++) {
            M[order[i]] = i;
        }
        sort(s.begin(), s.end(), [&] (char a, char b) -> bool {
            return M[a] < M[b];
        }
        );
        return s;
    }
};
// @lc code=end

