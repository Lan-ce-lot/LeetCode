/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        string ans;
        int f1 = 0, f2 = 0, f3 = 0;
        char la = 'A';
        for (auto &it : suits) {
            if (la != 'A' && la != it) {
                f1 = 1;
                break;
                }
            la = it;
        }
        if (!f1) return "Flush";
        unordered_map<int, int> M;
        for (auto &it : ranks) {
            M[it]++;
        }
        for (auto [x, y] : M) {
            if (y >= 3) {
                f2 = 1;
                break;
            }
            if (y == 2) {
                f3 = 1;
            }
        }
        if (f2) return "Three of a Kind";
        if (f3) return "Pair";
        return "High Card"; 
    }
};
// @lc code=end

