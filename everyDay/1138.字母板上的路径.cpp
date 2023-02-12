/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        /*
        v / 5 = y
        v % 5 = x
        */
        string ans = "";
        int p = 0;
        for (auto it : target) {
            
            int t = it - 'a';
            if (p == t) {
                ans += '!';
            } else {
                int ty = t / 5, tx = t % 5;
                int py = p / 5, px = p % 5;
                if (ty - py > 0) {
                    if (tx - px > 0) {
                        for (int j = 0; j < tx - px; j++) {
                            ans += 'R';
                        }
                    } else {
                        for (int j = 0; j < abs(tx - px); j++) {
                            ans += 'L';
                        }
                    }
                    for (int j = 0; j < ty - py; j++) {
                        ans += 'D';
                    }
                } else {
                    for (int j = 0; j < abs(ty - py); j++) {
                        ans += 'U';
                    }
                    if (tx - px > 0) {
                        for (int j = 0; j < tx - px; j++) {
                            ans += 'R';
                        }
                    } else {
                        for (int j = 0; j < abs(tx - px); j++) {
                            ans += 'L';
                        }
                    }
                } 
                ans += '!';
            }
            p = t;
        }
        return ans;
    }
};
// @lc code=end

