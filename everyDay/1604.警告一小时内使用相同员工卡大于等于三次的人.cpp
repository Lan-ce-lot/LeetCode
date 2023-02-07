/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int> > M;
        for (int i = 0; i < keyName.size(); i++)  {
            string name = keyName[i];
            string time = keyTime[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            M[name].emplace_back(hour * 60 + minute);
        }
        vector<string> A;
        for (auto &[name, list] : M) {
            sort(list.begin(), list.end());
             int size = list.size();
            for (int i = 2; i < size; i++) {
                int time1 = list[i - 2], time2 = list[i];
                int difference = time2 - time1;
                if (difference <= 60) {
                    A.emplace_back(name);
                    break;
                }
            }
        }
        sort(A.begin(), A.end());
        return A;
    }
};
// @lc code=end

