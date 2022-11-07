/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    void bfs(int x ,int y, vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int> > Q;
        int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
        Q.push({x, y});
        grid[x][y] = '0';
        while (Q.size()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i][0], yy = y + dir[i][1];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == '1') {
                    grid[xx][yy] = '0';
                    Q.push({xx, yy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

