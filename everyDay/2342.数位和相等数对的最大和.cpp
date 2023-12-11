/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
class Solution {
public:
    int get(int num) {
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {
        int ans = -1;
        // pair first, second, max of v which swh == key
        // unordered_map<int, int> M;
        int M[890] = {0};
        for (auto it : nums) {
            int t = get(it);
            // update ans
            if (M[t] != 0 ) {
                ans = max(ans, M[t] + it);
            }
            // 1. get > first, second -> first, first = tmp
            // 2. get > second, second -> tmp
            // 3. get < second ...

            if (it > M[t]) {
                M[t] = it;
            }
            // cout << it << " -> " << t << " " << ans <<  endl;
            
        }
        return ans;
    }
};
// @lc code=end

