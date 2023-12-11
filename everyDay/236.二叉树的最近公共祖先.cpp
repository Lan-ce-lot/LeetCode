/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return asn;
    }
    int ans = 0;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == null) {
            return 0;
        }
        // left
        int res = 0;
        if (root == p) {
            res ++;
        }
        if (root == q) {
            res ++;
        }
        res += dfs(root->left, p, q);
        res += dfs(root->right, p, q);
        if (res >= 2) {
            ans = root->val;
        }
        return res;
    }
};
// @lc code=end

