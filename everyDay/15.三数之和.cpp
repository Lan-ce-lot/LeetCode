/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j, r = n - 1;
                while (l < r) {
                    int m = (l + r) / 2; 
                    if (nums[m] > -(nums[i] + nums[j])) {
                        r = m;
                    } else {
                        l = m + 1;
                    }
                }

                int l1 = j, r1 = n - 1;
                while (l1 < r1) {
                    int m = (l1 + r1 + 1) / 2; 
                    if (nums[m] < -(nums[i] + nums[j])) {
                        l1 = m;
                    } else {
                        r1 = m - 1;
                    }
                }
                l1 = max(l1, j + 1);
                while (l1 <= l) {
                    if (nums[l1] == -(nums[i] + nums[j]) && l1 != i && l1 != j) {
                        ans.push_back({nums[i], nums[j], nums[l1]});
                        break;
                    }
                    l1++;
                }
            }

        }
        return ans;
    }
};
// @lc code=end

