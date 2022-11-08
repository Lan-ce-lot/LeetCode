/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> M;
        int res = 0;
        for (int i = 0; i < allowed.size(); i++) {
            if (M.count(allowed[i]) == 0) {
                M[allowed[i]] = 1;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            bool f = 0;
            for (auto j : words[i]) {
                if (!M.count(j)) {
                    f = 1;
                    break;
                }
            }
            if (f) {

            } else {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

