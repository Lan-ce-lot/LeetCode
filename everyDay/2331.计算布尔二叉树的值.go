/*
 * @lc app=leetcode.cn id=2331 lang=golang
 *
 * [2331] 计算布尔二叉树的值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func evaluateTree(root *TreeNode) bool {
	if (root.Left == nil) {
		return root.Val != 0;
	}
	if (root.Val == 2) {
		return evaluateTree(root.Left) || evaluateTree(root.Right)
	} else {

		return evaluateTree(root.Left) && evaluateTree(root.Right)
	}
}
// @lc code=end

