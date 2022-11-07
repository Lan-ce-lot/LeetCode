/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution {
public:
    vector<string> check(string s)
{
    if (s.back() == '0')
        return {s};
    //这步必须要优先
    if (s[0] == '0')
        return {s.substr(0, 1) + "." + s.substr(1)};
    vector<string> ret = {s};
    for (int i = 1; i < s.size(); ++i)
        ret.emplace_back(s.substr(0, i) + "." + s.substr(i));
    return ret;
}
vector<string> ambiguousCoordinates(string s)
{
    string t = s.substr(1, s.size() - 2);
    int n = t.size();
    vector<string> ans;
    for (int i = 1; i < n; ++i)
    {
        if (i > 1 && t[0] == '0' && t[i - 1] == '0' || i < n - 1 && t[i] == '0' && t.back() == '0')
            continue;
        vector<string> le = check(t.substr(0, i));
        vector<string> ri = check(t.substr(i));
        for (string &a : le)
            for (string &b : ri)
                ans.emplace_back("(" + a + ", " + b + ")");
    }
    return ans;
}
};
// @lc code=end

