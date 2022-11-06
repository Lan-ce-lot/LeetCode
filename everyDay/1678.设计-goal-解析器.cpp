/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            if (command[i] == 'G') {
                res += "G";
            } else if (command[i] == '(' && command[i + 1] == ')') {
                res += "o";
                i ++;
            } else if (command[i] == '(' && command[i + 1] == 'a') {
                res += "al";
                i += 3;
            }
        }
        return res;
    }
};
// @lc code=end

