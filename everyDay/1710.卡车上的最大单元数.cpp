/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
            [](autop a, auto b) -> bool {

                return a[1] < b[2];
            }
        )
        int c = 0, i = 0;
        for (j = 0; j< boxTypes.size() &&  i < boxTypes.size() * boxTypes[0].size(); j++) {
            int t = c + boxTypes[j][0] * boxTypes[j][1];
            if (t < truckSize) {
                c = t;
            } else if (t == truckSize) {
                return t;
            } else {
                int all = boxTypes[j][1];
                while (all--) {
                    t -= boxTypes[j][0];
                    if (t <= truckSize) {
                        return t;
                    }
                }
            }
        }
        return c;
    }
};
// @lc code=end

