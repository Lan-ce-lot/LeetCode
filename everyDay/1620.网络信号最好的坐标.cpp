/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
class Solution {
    const int N = 51;
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> res(2);
        int resv = 0;
        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                int tmp = 0;
                for (int k = 0; k < towers.size(); k++) {
                    int dis = (towers[k][0] - i) * (towers[k][0] - i)  +  (towers[k][1] - j) * (towers[k][1] - j);
                    if (dis <= radius * radius) {
                        tmp += (towers[k][2] / (1 + sqrt(dis)));
                    }
                }
                if (tmp > resv) {
                    resv = tmp;
                    res = {i, j};
                }
            }
        }
        return res;
    }
};
// @lc code=end

