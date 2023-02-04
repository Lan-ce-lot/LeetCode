/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
class Solution {
public:
    bool vis[101], vis1[101];
    struct no {
        int p, s;
        bool f;
        no(int _p, int _s, bool _f):p(_p), s(_s), f(_f){}
    };
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> a(n, -1);
        vector<int> R[101];
        vector<int> B[101];
        for (int i = 0; i < redEdges.size(); i++) {
            R[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for (int i = 0; i < blueEdges.size(); i++) {
            B[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        for (int i = 0; i < n; i++) {
            int RR = bfs(0, i, R, B);
            cout << "===" << endl;
            int BB = bfs(1, i, R, B);
            cout << RR <<' ' << BB << endl;
            if (RR == -1 && BB == -1) {
                a[i] = -1;
            } else if (RR == -1 && BB != -1) {
                a[i] = BB;
            } else if (RR != -1 && BB == -1) {
                a[i] = RR;
            } else {
                a[i] = min(BB, RR);
            }
        }
        return a;
    }
    int bfs(int f, int i, vector<int>(& R)[101], vector<int>(& B)[101]) {
        queue<no> Q;
        Q.push(no(0, 0, f));
        memset(vis, 0, sizeof vis);
        memset(vis1, 0, sizeof vis1);
        if (f) {
            vis[0] = 1;
        } else {
            vis1[0] = 1;
        }
        
        while (Q.size()) {
            no T = Q.front();
            cout << T.p << ' ' << T.s << ' ' << T.f << endl;
            Q.pop();
            if (T.p == i) {
                return T.s;
            }
            if (T.f) {
                for (int i = 0; i < R[T.p].size(); i++) {
                    int pp = R[T.p][i];
                    if ((!vis[pp] && !T.f) || (!vis1[pp] && T.f)) {
                        if (!T.f) {
                            vis[pp] = 1;
                        } else {
                            vis1[pp] = 1;
                        }
                        Q.push(no{pp, T.s + 1, !T.f});
                    }
                }
            } else {
                for (int i = 0; i < B[T.p].size(); i++) {
                    int pp = B[T.p][i];
                    if ((!vis[pp] && !T.f) || (!vis1[pp] && T.f)) {
                        if (!T.f) {
                            vis[pp] = 1;
                        } else {
                            vis1[pp] = 1;
                        }
                        Q.push(no{pp, T.s + 1, !T.f});
                    }
                }
            }
        }
        return -1;
    }
};
/*
3\n[[0,1]]\n[[1,2]]
*/


// @lc code=end

