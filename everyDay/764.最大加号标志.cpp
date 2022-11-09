/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int > M;
    // int S;
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // vector<vector<int> > V;
        // S = n;
        if(mines.size()==0)
            return (n+1)/2;
        if(mines.size()==n*n)
            return 0;
        for (int i = 0; i < mines.size(); i++) {
            M[mines[i][0] * n + mines[i][1]] = -1;
            // cout << mines[i][0] * n + mines[i][1] << endl;
        }

        // n * n * n
        int res = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (M[x * n + y] == -1) {
                    
                    continue;
                }
                int max_n = min(x, n - x - 1);
                max_n = min(max_n, min(y, n - y - 1));
                // cout << max_n << endl;

                if (max_n + 1 <= res) continue;
                int i = 1;
                for (; i <= max_n; i++) {
                    if (!(M[x * n + y - i] != -1 && M[x * n + y + i] != -1
                    && M[(x + i) * n + y] != -1 && M[(x - i) * n + y] != -1
                    )) {
                        break;
                    }

                }
                res = max(res, i);
            }
        }
        return res;
    }
};
// @lc code=end

