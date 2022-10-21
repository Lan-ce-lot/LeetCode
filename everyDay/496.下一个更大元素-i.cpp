/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> M;
        stack<int> s;
        s.push(nums2[nums2.size() - 1]);
        M[nums2[nums2.size() - 1]] = -1;
        for (int i = nums2.size() - 2; i >= 0; i--) {
            while (s.size() && s.top() < nums2[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                M[nums2[i]] = -1;
            } else {
                M[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        // 优化，比push_back快
        vector<int> v(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            v[i] = M[nums1[i]];
        }
        return v;
    }
};
// @lc code=end

