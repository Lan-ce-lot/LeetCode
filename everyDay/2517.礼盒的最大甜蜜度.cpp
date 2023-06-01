/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

// @lc code=start
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = price.back() - price[0];
        while (l < r) {
            int m = r - (r - l - 1) / 2;
            if (check(price, k, m)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
    bool check(vector<int>& price, int k, int m) {
        int cnt = 0;
        int no = INT_MIN >> 1;
        for (auto it : price) {
            if (it - no >= m) {
                cnt++;
                no = it;
            }
        }

        return cnt >= k;
    }
};
// @lc code=end

