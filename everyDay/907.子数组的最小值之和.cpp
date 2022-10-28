/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    const int m = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> S;
        vector<int> l(n), r(n);

        for (int i = 0; i < n; i++) {
            while (S.size() && arr[S.top()] > arr[i]) {
                S.pop();
            }
            l[i] = S.size() ? i - S.top() : i + 1;
            S.push(i);
            // cout <<l[i] << ' ';
        }
        S = stack<int>();
        // S.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (S.size() && arr[S.top()] >= arr[i]) {
                S.pop();
            }
            r[i] = S.size() ? S.top() - i : n - i;
            S.push(i);
        }
        
        long res = 0;
        for (int i = 0; i < n; i++) {
            res =  (res + ((1l * l[i] * r[i]) % m ) * arr[i] % m) % m;
        }
        return res;
        
    }
};
// @lc code=end
// 1 6 3
1 6 3 5 4 2 3
 

