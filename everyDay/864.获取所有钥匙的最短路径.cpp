/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 */

// @lc code=start
class Solution {
public:
// 状态压缩 + 广度优先搜索


    int dir[4][2] = {0, 1, -1, 0, 1, 0, 0, -1};
    int bfs(int x, int y, vector<string>& grid) {
        queue<tuple<int, int, int> > Q;
        unordered_map<char, int> key;
        Q.emplace(x, y, 0);
        int count = 0;
        string tmps = "";
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (islower(grid[i][j]) && !key.count(grid[i][j])) {
                    int c = key.size();
                    key[grid[i][j]] = c;
                }
            }
        }
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(1 << key.size(), -1)));
        int max = 0;
        dist[x][y][0] = 0;
        while (Q.size()) {
            // max++;
            auto [tx, ty, mask] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = tx + dir[i][0], yy = ty + dir[i][1];
                // 
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || grid[xx][yy] == '#') continue;

                // @.
                if (grid[xx][yy] == '.' || grid[xx][yy] == '@'
                ) {
                    if (dist[xx][yy][mask] == -1) {
                        dist[xx][yy][mask] = dist[tx][ty][mask] + 1;
                        Q.emplace(xx, yy, mask);
                    }
                }
                // aA
                else if (islower(grid[xx][yy])) {
                    int idx = key[grid[xx][yy]];
                    cout << idx << endl;
                    cout << dist[xx][yy][mask | (1<< idx)] << endl;
                    // cout << mask | (1 << idx) << endl;
                    if (dist[xx][yy][mask | (1 << idx)] == -1) {
                        dist[xx][yy][mask | (1 << idx)] = dist[tx][ty][mask] + 1;

                        if ((mask | (1 << idx)) == (1 << key.size()) - 1) {
                            return dist[xx][yy][mask | (1 << idx)];
                        }
                        Q.emplace(xx, yy, (mask | (1 << idx)));
                    }
                    
                } 
                // a
                else {
                    int idx = key[tolower(grid[xx][yy])];
                    if ((mask & (1 << idx)) && dist[xx][yy][mask] == -1) {
                        dist[xx][yy][mask] = dist[tx][ty][mask] + 1;
                        Q.emplace(xx, yy, mask);
                    }
                }
            }
        }
        return -1;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int x, y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '@') {
                    x = i, y = j;
                    break;
                }
            }
        }

        return bfs(x, y, grid);
    }
};
// @lc code=end

