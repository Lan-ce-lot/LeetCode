/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int lowbit(int x) {
        return x & -x;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > V;

        // bfs
        queue<TreeNode*> Q;
        if (!root) {
            return V;
        }
        Q.push(root);
        int c = 0;
        while (Q.size()) {
            int co = Q.size();
            vector<int> tmp;
            for (int i = 0; i < co; i++) {
                TreeNode* top = Q.front();
                Q.pop();
                if (top != nullptr) {
                    tmp.push_back(top->val);
                }
                if (top->left != nullptr) {
                    Q.push(top->left);
                }
                if (top->right != nullptr) {
                    Q.push(top->right);
                }
            }
            V.push_back(tmp);
            c++;
        }
        return V;
    }
};
// @lc code=end

