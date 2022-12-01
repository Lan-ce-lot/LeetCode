/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int r = -1;
        int d = -1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                if (~r == 0) {
                    d = i;
                    r = abs(points[i][0] - x) + abs(points[i][1] - y);
                } else {
                    if (r > abs(points[i][0] - x) + abs(points[i][1] - y)) {
                        d = i;
                        r = abs(points[i][0] - x) + abs(points[i][1] - y);
                    }
                }
            }
        }
        return d;
    }
};
// @lc code=end

