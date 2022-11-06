/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

// @lc code=start
class Solution {
public:
    int reachNumber(int target) {
        int tmp = 0;
        target = abs(target);
        for (int i = 1; ; i++) {
            tmp += i;
            if (tmp > target) {
                if ((tmp - target) % 2 == 0 ) {
                    return i;
                } else {
                    return (tmp + i - target) % 2 == 1? i+ 1 : i + 2;
                }
            } else if (tmp == target) {
                return i;
            }
        }
    }
};
// @lc code=end

