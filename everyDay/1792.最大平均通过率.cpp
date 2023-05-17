/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
class Solution {
public:
    struct node {
        int p, t;
        bool operator < ( const node &n) const {
            return (long long) n.t *(n.t + 1) * (t - p) < (long long) t * (t + 1) * (n.t - n.p);
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
/**
p = (pi + x) / (ti + x) + ...
2/ 4 - 3/ 5
pi * (ti + 1) - (pi + 1) * ti
-----------------------------
ti * (ti + 1)
==>

维护一个按增量最大的优先队列

ti - pi
-------
ti * (ti + 1) 


*/
        priority_queue<node> P;
        for (auto &c : classes) {
            P.push({c[0], c[1]});
        }
        for (int i = 0; i < extraStudents; i++) {
            auto [pass, total] = P.top();
            P.pop();
            P.push({pass + 1, total + 1});
        }
        double ans = 0;
        for (int i = 0; i < classes.size(); i++) {
            auto [pass, total] = P.top();
            P.pop();
            ans += 1.0 * pass / total;
        }
        return ans / classes.size();
    }
};
// @lc code=end

