/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int> >V{startTime.size()};
        for (int i = 0; i < startTime.size(); i++) {
            V[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(V.begin(), V.end(), 
        [] (const vector<int> a, const vector<int> b) -> bool {
            return a[1] < b[1];
        });
        
        vector<int> dp(startTime.size() + 1);
        for (int i = 1; i <= startTime.size(); i++) {
             // bsearch
            int l = 0, r = startTime.size() - 1;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (V[m][1] <= V[i - 1][0]) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            if(V[l][1] <= V[i - 1][0])l++;
            dp[i] = max(dp[i - 1], dp[l] + V[i - 1][2]);
        }
        return dp[startTime.size()];
    }
};
// @lc code=end