/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution {
public:
    struct node{
        int x, y, s;
        node(int xValue, int yValue, int sValue) : x(xValue), y(yValue), s(sValue) {
        // Initialization list is used to initialize x, y, and s
    }
    };

    int bfs(vector<vector<int>>& heights, int t) {
        queue<node> Q;
        int x = heights.size();
        int y = heights[0].size();
        int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

        int vis[x][y];
   
        memset(vis, 0, sizeof vis);
        vis[0][0] = 1;
        Q.push(node(0,0,0));
        while (Q.size()) {
            node top = Q.front();
            
            if (top.x == x - 1 && top.y == y - 1 && top.s <= t) {
                return 1;
            }
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = top.x + dir[i][0];
                int yy = top.y + dir[i][1];
                int tmp = 1e6+10;
                if ( xx >= 0 && xx < x && yy >=0 && yy < y && vis[xx][yy] == 0) {
                    
                    tmp = min(tmp, max(top.s, abs(heights[xx][yy] - heights[top.x][top.y])));
                    if (tmp > t) continue;
                    vis[xx][yy] = 1;
                    Q.push(node(xx, yy, tmp));
                }
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        // 0-10^6 + 1
        // find a xmin which can't reach the end
        // bfs
        int l = -1, r = 1e7 + 2;
        while (l < r) {
            int m = l + r >> 1;
            int b = bfs(heights, m);
            // cout << "m->" << m  << ' ' << l << ' ' << r << ' ' << b << endl;
            if (b) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
// @lc code=end

