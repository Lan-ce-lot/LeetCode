/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
private:
    stack<pair<int, int> > stk;
    int idx;
public:
    StockSpanner() {
        this->stk.emplace(-1, INT_MAX);
        this->idx = -1;
    }
    
    int next(int price) {
        idx++;
        while (price >= stk.top().second) {
            stk.pop();
        }
        int res = idx - stk.top().first;
        stk.push({idx, price});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

