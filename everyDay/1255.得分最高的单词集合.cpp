/*
     * @lc app=leetcode.cn id=1255 lang=cpp
     *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> M;
        int ans = 0;
        for (int i = 0; i < letters.size(); i++) {
            M[letters[i]]++;
        }

        function<void(int, int)> dfs = [&](int now, int total) {
            if (now < 0) {
                ans = max(ans, total);
                return;
            }
         
            dfs(now - 1, total);
            bool f = true;
            for (int i = 0; i < words[now].size(); i++ ) {
                char c = words[now][i];
                if (M[c]-- == 0) {
                    f = false;
                }
                total += score[c - 'a'];
            }
            if (f) {
                dfs(now - 1, total);
            }
            for (int i = 0; i < words[now].size(); i++) {
                M[words[now][i]] ++;
            }
        };
        dfs(words.size() - 1, 0);
        return ans;
    }
};
// @lc code=end

