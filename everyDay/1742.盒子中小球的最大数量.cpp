/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
public:
    int cal(int a) {
        int res = 0;
        while (a) {
            res += a % 10;
            a /= 10;
        }
        return res;
    }
    int countBalls(int lowLimit, int highLimit) {
        int a[100]{0};
        for (int i = lowLimit; i <= highLimit; i++) {
            a[cal(i)] ++;
        }
        return *max_element(a, a + 100);
    }
};
// @lc code=end

