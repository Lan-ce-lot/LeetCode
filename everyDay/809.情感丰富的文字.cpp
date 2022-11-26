/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

// @lc code=start
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        // int n = words.size();
        int res = 0;
        // 扩张达到3以上
        for (int i = 0; i < words.size(); i++) {
            int f = 1;
            //
            int j = 0, k = 0;
            while (j < words[i].size() && k < s.size()) {
                int cntj = 0, cntk = 0;
                if (words[i][j] != s[k]) {
                    f = 0;
                    break;
                }
                char c = s[k];
                while (k < s.size() && s[k] == c) {
                    k ++;
                    cntk ++;
                }

                while (j < words[i].size() && words[i][j] == c) {
                    j++;
                    cntj++;
                }
                if (cntj > cntk) {
                    f = 0;
                    break;
                }
                if (cntj != cntk && cntk < 3) {
                    f = 0;
                    break;
                }
            }
            if (f) f = (j == words[i].size() && k == s.size());
            //
            
            res += f;
        }
        return res;
    }
};
// @lc code=end

