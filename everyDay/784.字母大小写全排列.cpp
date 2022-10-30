/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    void dfs(int now, string &s, vector<string> &S) {
        while (now < s.size() && isdigit(s[now])) {
            now++;
        }
        if (now == s.size()) {
            S.push_back(s);
            return;
        }
        s[now] ^= 32;
        dfs(now + 1, s, S);
        s[now] ^= 32;
        dfs(now + 1,s, S);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> S;
        dfs(0, s, S);
        return S;
    }
};
// @lc code=end

