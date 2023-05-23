/*
 * @lc app=leetcode.cn id=1090 lang=cpp
 *
 * [1090] 受标签影响的最大值
 */

// @lc code=start
class Solution {
public:
    int vis[100000];
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        // 排好队一个一个
        vector<pair<int, int> > V;
        for (int i = 0; i < values.size(); i++) {
            V.push_back({values[i], labels[i]});
            // V.emplace_back({values[i], labels[i]});
        }
        int sum = 0;
        sort(V.begin(), V.end(), greater<pair<int, int> >());
        for (int i = 0; i < V.size(); i++) {
            // cout << V[i].first << endl;
            if (!numWanted) {
                break;
            }
            if (vis[V[i].second] < useLimit) {
                vis[V[i].second]++;
                sum += V[i].first;
                numWanted--;
            }
        }

        return sum;
    }
};
// @lc code=end

