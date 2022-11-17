/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int> > idx(26);
        for (int i = 0; i < s.size(); i++) {
            idx[s[i] - 'a'].push_back(i);
            // idx[s[i]] = i;
        }
        int res = words.size();
        for (auto &it : words) {
            if (it.size() > s.size()) {
                --res;
                continue;
            }
            int now = -1;
            for (char c : it) {
                auto &tm = idx[c - 'a'];
                int l = 0, r = tm.size();
                // cout << r << endl;
                // 找到第一个> x 的数
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (tm[m] > now) {
                        r = m;
                    } else {
                        l = m + 1;
                    }
                }
                // cout << l << ' ' << it << endl;
                if (l >= tm.size()) {
                    res--;
                    break;
                }
                now = tm[l];
            }
        }
        return res;
    }
};
// @lc code=end

