/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        int l1= s.size() / 4;
        // int a[4];
        unordered_map<char, int> T, C, M;

        for (int i = 0; i < s.size(); i++) {
            T[s[i]]++;
        }
        for (auto [k, v] : T) {
            if (v > l1) {
                C[k] = v;
            }
        }
        if (C.size() == 0) {
            return 0;
        }
        int ans = s.size(), l = 0, r = 0;
        for (; r < s.size(); r++) {
            T[s[r]]--;
            while (T['Q'] <= l1 && T['W'] <= l1 && T['E'] <= l1 && T['R'] <= l1) {
                ans = min(ans, r - l + 1);
                T[s[l++]]++;
            }

        }

        return ans;
    }
};
// @lc code=end

