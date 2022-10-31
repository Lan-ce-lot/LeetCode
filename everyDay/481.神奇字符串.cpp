/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start    
const int N = 1e5;
int res[N + 1];
int init = []() {
    string s = "\1\2\2";
    for (int i = 2; s.length() < N; ++i)
        s += string(s[i], s.back() ^ 3); 
    for (int i = 0; i < N; ++i)
        res[i + 1] = res[i] + 2 - s[i];
    return 0;
}();
class Solution {
public:
    int magicalString(int n) {
        return res[n];
    }
};
// @lc code=end

