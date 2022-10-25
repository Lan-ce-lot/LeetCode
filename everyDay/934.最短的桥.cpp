/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    int bfs(int x, int y, vector<vector<int>> &grid) {
        queue<pair<int, int> > Q;
        // island
        int n = grid.size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        Q.push({x, y});
        grid[x][y] = -1;
        vector<pair<int, int> > isl;
        isl.push_back({x, y});
        while(Q.size()) {
            pair<int, int> top = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = dirs[i][0] + top.first, yy = dirs[i][1] + top.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 1) {
                    Q.push({xx, yy});
                    grid[xx][yy] = -1;
                    isl.push_back({xx, yy});
                }
            }
        }

        for (auto &&[x1, y1] : isl) {
            Q.push({x1, y1});
            grid[x1][y1] = -1;
        }
        // distant
        int s = 0;
        while (Q.size()) {
            int sz = Q.size();
            for (int i = 0; i < sz; i++) {
                auto [x1, y1] = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x1 + dirs[k][0];
                    int ny = y1 + dirs[k][1];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if (grid[nx][ny] == 0) {
                            Q.emplace(nx, ny);
                            grid[nx][ny] = -1;
                        } else if (grid[nx][ny] == 1) {
                            return s;
                        }
                    }
                }
            }
            s++;
        }
        return -1;

    }
    int shortestBridge(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 1) {
                    return bfs(i, j, grid);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

