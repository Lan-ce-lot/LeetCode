/*
 * @lc app=leetcode.cn id=2446 lang=cpp
 *
 * [2446] 判断两个事件是否存在冲突
 */

// @lc code=start
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if (event1[0] <= event2[0] && event1[1] >= event2[0])
            return true;
        if (event1[0] <= event2[1] && event1[1] >= event2[1])
            return true;
        if (event1[0] <= event2[0] && event1[1] >= event2[1])
            return true;
        if (event1[0] >= event2[0] && event1[1] <= event2[1])
            return true;
        return false;
    } 
};
// @lc code=end

