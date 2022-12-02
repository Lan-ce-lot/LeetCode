/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l = boxes[0] - '0', r = 0, op = 0;
        for (int i = 1; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                r ++;
                op += i;
            }
        }
        vector<int> re(boxes.size());
        re[0] = op;
        for (int i = 1; i < boxes.size(); i++) {
            op += l - r;
            if (boxes[i] == '1') {
                l++;
                r--;
            }
            re[i] = op;
        }
        return re;
    }
};
// @lc code=end

