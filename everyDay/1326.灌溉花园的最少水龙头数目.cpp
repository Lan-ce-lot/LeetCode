/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 * [1326] 灌溉花园的最少水龙头数目
 *
 */

// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int> > intervals;
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals.emplace_back(start, end);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (auto [s, e] : intervals) {
          if (dp[s] == INT_MAX) {
            return -1;
          }
          for (int j = s; j <= e; j++) {
            dp[j] = min(dp[j], dp[s] + 1);
          }
        }
        return dp[n];
    }
};
// @lc code=end

