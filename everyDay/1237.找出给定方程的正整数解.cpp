/*
 * @lc app=leetcode.cn id=1237 lang=cpp
 *
 * [1237] 找出给定方程的正整数解
 */

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

// class Solution {
// public:
//     vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
//         vector<vector<int> > ans;
//         int x = 1, y = 1000;
//         int n = 1001;
//         for (; x < n; x++) {
//             while (customfunction.f(x, y) > z && y > 1) {
//                 y--;
//             }
//             if (customfunction.f(x, y) == z) {
//                 ans.push_back({x, y});
//             }
//         } 
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
//         vector<vector<int> > ans;
//         int x, y;
//         int n = 1001;
//         for (int i = 1; i < n; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (customfunction.f(i, j) == z) {
//                     ans.push_back({i, j});
//                 }
//             }
//         } 
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int> > ans;
        int n = 1001;
        for (int i = 1; i < n; i++) {
            int l = 1, r = n;
            while (l < r) {
                // cout << l << " " << r<< endl;
                int m = l + r >> 1;
                if (customfunction.f(i, m) < z) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if (customfunction.f(i, l) == z) {
                ans.push_back({i, l});
            }
        } 
        return ans;
    }
};
// @lc code=end

