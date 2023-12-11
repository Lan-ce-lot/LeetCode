/*
 * @lc app=leetcode.cn id=141 lang=golang
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
	// 1. 快慢指针，相遇
	// 2. 遍历，map
	if head == nil || head.Next == nil {
        return false
    }
	p1 := head
	p2 := head.Next 
	for {
		if p1 != nil {
			p1 = p1.Next
		} else {
			return false
		}
		if p2 != nil && p2.Next != nil {
			p2 = p2.Next.Next
		} else {
			return false
		}		
		if p1 == p2 {
			return true
		}
	}
	return false
}
// @lc code=end

