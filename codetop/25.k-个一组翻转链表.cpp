/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, ListNode*> r(ListNode* head, ListNode* tail) {
        ListNode* pre, *now = head, *nex = head->next;
        while (pre != tail) {
            nex = now->next;
            now->next = pre;
            pre = now;
            now = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* b_head = new ListNode(0);
        b_head->next = head;
        ListNode* ind = head;
        ListNode* pre = b_head;        
        int con = 0;
        while (ind) {
            ListNode* tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return b_head->next;
                }
            }
            ListNode* nex = tail->next;
            tie(head, tail) = r(head, tail);
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return b_head->next ;
    }
};
// @lc code=end

