/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        int n = nums.size();
        // 保证递减
        // res = 0;
        vector<int> res(n - k + 1);
        for (int i = 0; i < n; i++ ){

            while (Q.size() && nums[Q.back()] <= nums[i]) {
                Q.pop_back();
            }
            Q.push_back(i);
            while (Q.size() && Q.front() <= i - k) {
                Q.pop_front();
            }
            if (i >= k - 1) {
                cout << nums[Q.front()] << endl;
                res[i - k + 1] = nums[Q.front()];
            }
        }
        return res;
    }
};
// @lc code=end

